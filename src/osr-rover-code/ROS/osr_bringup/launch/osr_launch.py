import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, DeclareLaunchArgument
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def generate_launch_description():
    # 1. Configuración de tiempo de simulación
    use_sim_time = LaunchConfiguration('use_sim_time', default='true')

    # Directorios de los paquetes
    rover_bringup_dir = get_package_share_directory('rover_bringup')
    nav2_bringup_dir = get_package_share_directory('nav2_bringup')
    osr_gazebo_dir = get_package_share_directory('osr_gazebo')

    # 2. Simulación Base (Mundo + Rover + Controladores)
    # En lugar de reescribir todo, llamamos a tu launch de osr_gazebo que ya funciona perfecto.
    gazebo_rover_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(osr_gazebo_dir, 'launch', 'empty_world.launch.py')
        )
    )

    # 3. Puente de Sensores (Gazebo Harmonic -> ROS 2 Jazzy)
    # IMPORTANTÍSIMO: Pasa los datos del Lidar, IMU y Cámara para que Nav2 y el EKF no estén ciegos.
    # Nota: Tu C++ node ya escucha cmd_vel nativamente, así que no hace falta puentear la velocidad.
    sensor_bridge = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        arguments=[
            '/scan@sensor_msgs/msg/LaserScan[gz.msgs.LaserScan',
            '/imu@sensor_msgs/msg/Imu[gz.msgs.IMU',
            '/camera@sensor_msgs/msg/Image[gz.msgs.Image',
            '/camera_info@sensor_msgs/msg/CameraInfo[gz.msgs.CameraInfo'
        ],
        parameters=[{'use_sim_time': use_sim_time}],
        output='screen'
    )

    # 4. Localización (EKF / Filtro de Kalman de tu compañero)
    localizacion_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(rover_bringup_dir, 'launch', 'localizacion.launch.py')
        ),
        launch_arguments={'use_sim_time': use_sim_time}.items()
    )

    # 5. Nav2 (Navegación Autónoma)
    # OJO: Asegúrate de tener un mapa guardado en esta ruta
    map_file = os.path.join(rover_bringup_dir, 'maps', 'mapa.yaml')
    nav2_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(nav2_bringup_dir, 'launch', 'bringup_launch.py')
        ),
        launch_arguments={
            'map': map_file,
            'use_sim_time': use_sim_time,
            'autostart': 'true'
        }.items()
    )

    # 6. RViz (Interfaz visual)
    rviz_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(nav2_bringup_dir, 'launch', 'rviz_launch.py')
        ),
        launch_arguments={'use_sim_time': use_sim_time}.items()
    )

    # 7. Nodo de detección ArUco
    aruco_params_path = os.path.join(rover_bringup_dir, 'config', 'aruco.yaml')
    aruco_node = Node(
        package='ros2_aruco',
        executable='aruco_node',
        name='aruco_node',
        parameters=[aruco_params_path, {'use_sim_time': use_sim_time}],
        output='screen'
    )

    return LaunchDescription([
        DeclareLaunchArgument('use_sim_time', default_value='true'),
        gazebo_rover_launch,
        sensor_bridge,
        localizacion_launch,
        nav2_launch,
        rviz_launch,
        aruco_node
    ])