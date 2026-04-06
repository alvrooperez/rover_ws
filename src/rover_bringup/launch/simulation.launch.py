import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, DeclareLaunchArgument
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch_ros.actions import SetParameter


def generate_launch_description():
    # 1. Configuración de tiempo de simulación
    use_sim_time = LaunchConfiguration('use_sim_time', default='true')

    # Directorios de paquetes
    rover_bringup_dir = get_package_share_directory('rover_bringup')
    nav2_bringup_dir = get_package_share_directory('nav2_bringup')
    # tb3_gazebo_dir = get_package_share_directory('turtlebot3_gazebo')
    # tb3_nav2_dir = get_package_share_directory('turtlebot3_navigation2')

    osr_gazebo_dir = get_package_share_directory('osr_gazebo')

    # 2. Entorno y Robot (Usamos el launch de tu paquete osr_gazebo)
    osr_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(osr_gazebo_dir, 'launch', 'empty_world.launch.py')
        ),
        launch_arguments={'use_sim_time': use_sim_time}.items()
    )

    # 2.5 Nuestro Puente Correcto (CMD_VEL)
    puente_bueno = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        arguments=[
            # El reloj vital para que no se congele ROS 2
            '/clock@rosgraph_msgs/msg/Clock[gz.msgs.Clock',
            # Sensores para Nav2
            '/scan@sensor_msgs/msg/LaserScan[gz.msgs.LaserScan',
            '/imu@sensor_msgs/msg/Imu[gz.msgs.IMU',
            # ¡Los ojos para el ArUco!
            '/camera/image_raw@sensor_msgs/msg/Image[gz.msgs.Image',
            '/camera/camera_info@sensor_msgs/msg/CameraInfo[gz.msgs.CameraInfo'
        ],
        parameters=[{'use_sim_time': use_sim_time}],
        output='screen'
    )

    # 3. Nav2
    map_file = os.path.join(rover_bringup_dir, 'maps', 'map.yaml')  # usa tu mapa local
    nav2_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(nav2_bringup_dir, 'launch', 'bringup_launch.py')
        ),
        launch_arguments={
            'map': map_file,
            'use_sim_time': use_sim_time,
            'autostart': 'true' # Desactivado temporalmente hasta tener un mapa de 7x7.sdf
        }.items()
    )

    # 4. RViz
    rviz_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(nav2_bringup_dir, 'launch', 'rviz_launch.py')
        ),
        launch_arguments={'use_sim_time': use_sim_time}.items()
    )

    # 5. Localización (EKF / AMCL)
    localizacion_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(rover_bringup_dir, 'launch', 'localizacion.launch.py')
        ),
        launch_arguments={'use_sim_time': use_sim_time}.items()
    )

    # 6. Nodo de detección ArUco
    aruco_params_path = os.path.join(rover_bringup_dir, 'config', 'aruco.yaml')
    aruco_node = Node(
        package='ros2_aruco',
        executable='aruco_node',
        name='aruco_node',
        parameters=[aruco_params_path, {'use_sim_time': use_sim_time}],
        output='screen'
    )

    # 7. Aparecer el ArUco (1 metro delante del robot)
    aruco_sdf_path = os.path.join(rover_bringup_dir, 'models', 'aruco_marker', 'model.sdf')
    spawn_aruco = Node(
        package='ros_gz_sim',
        executable='create',
        arguments=[
            '-name', 'marcador_1',
            '-file', aruco_sdf_path,
            '-x', '4.0', '-y', '0.0', '-z', '0.15',
            '-R', '0.0', '-P', '1.5708', '-Y', '0.0'
        ],
        output='screen'
    )

    return LaunchDescription([
        SetParameter(name='use_sim_time', value=True),
        DeclareLaunchArgument('use_sim_time', default_value='true'),
        
        osr_launch,         # Levanta Gazebo, el mapa 7x7 y spawnea tu rover con sus controladores
        spawn_aruco,        # El ArUco en 1,0
        puente_bueno,
        nav2_launch,      # Comentado hasta generar el mapa de tu mundo
        rviz_launch,
        localizacion_launch,
        aruco_node
    ])