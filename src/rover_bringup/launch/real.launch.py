import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, DeclareLaunchArgument, ExecuteProcess
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node, SetParameter

def generate_launch_description():
    # 1. Configuración de tiempo (FALSO para el robot real)
    use_sim_time = LaunchConfiguration('use_sim_time', default='false')

    # Directorios de paquetes
    rover_bringup_dir = get_package_share_directory('rover_bringup')
    nav2_bringup_dir = get_package_share_directory('nav2_bringup')
    osr_bringup_dir = get_package_share_directory('osr_bringup')

    # ========================================================================
    # ESPACIO PARA EL HARDWARE FÍSICO (Para añadir en el futuro)
    # ========================================================================
    # 1.5 Nodo/Launch del control real del Open Source Rover (OSR)
    # Esto levantará los motores, leerá encoders y publicará la odometría real.
    osr_control_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(osr_bringup_dir, 'launch', 'osr_launch.py') # IMPORTANTE: Ajusta el nombre si tu archivo real se llama distinto
        )
    )
    
    # Aquí irían nodos como:
    # - v4l2_camera (Cámara USB real)
    # - rplidar_ros (Lidar físico)
    # ========================================================================

    # 2. Localización (EKF local y global)
    localizacion_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(rover_bringup_dir, 'launch', 'localizacion.launch.py')
        ),
        launch_arguments={'use_sim_time': use_sim_time}.items()
    )

    # 3. Reconocimiento ArUco (ros2_aruco)
    aruco_params_path = os.path.join(rover_bringup_dir, 'config', 'aruco.yaml')
    aruco_node = Node(
        package='ros2_aruco',
        executable='aruco_node',
        name='aruco_node',
        parameters=[aruco_params_path, {'use_sim_time': use_sim_time}],
        output='screen'
    )
    
    # 4. Puente: Procesador ArUco -> EKF
    mock_aruco_node = ExecuteProcess(
        cmd=['python3', os.path.join(os.getcwd(), 'src', 'rover_bringup', 'config', 'mock_aruco.py'), '--ros-args', '-p', 'use_sim_time:=false'],
        output='screen'
    )

    # 5. Nav2 (Navegación Autónoma) - Descomentar cuando tengas el mapa real
    # map_file = os.path.join(rover_bringup_dir, 'maps', 'map_real.yaml') 
    # nav2_launch = IncludeLaunchDescription( ... )

    return LaunchDescription([
        # Forzamos el uso del reloj del sistema (hardware real)
        SetParameter(name='use_sim_time', value=False),
        DeclareLaunchArgument('use_sim_time', default_value='false'),
        
        osr_control_launch,
        localizacion_launch,
        aruco_node,
        mock_aruco_node
        # nav2_launch
    ])