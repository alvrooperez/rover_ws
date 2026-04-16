import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, DeclareLaunchArgument, ExecuteProcess
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node, SetParameter

def generate_launch_description():
    # 1. Configuración de tiempo
    use_sim_time = LaunchConfiguration('use_sim_time', default='false')

    # Directorios de paquetes
    rover_bringup_dir = get_package_share_directory('rover_bringup')
    osr_bringup_dir = get_package_share_directory('osr_bringup')
    ydlidar_dir = get_package_share_directory('ydlidar_ros2_driver')

    # Ruta del mapa
    map_file = os.path.join(rover_bringup_dir, 'maps', 'map.yaml')

    # --- HARDWARE FÍSICO ---
    osr_control_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(osr_bringup_dir, 'launch', 'osr_launch.py') 
        ),
        launch_arguments={'enable_odometry': 'false',
                          'publish_transform': 'false'}.items()
    )
    
    v4l2_camera_node = Node(
        package='v4l2_camera',
        executable='v4l2_camera_node',
        name='v4l2_camera',
        parameters=[
            {'video_device': '/dev/video0'}, 
            {'image_size': [640, 480]},     
            {'framerate': 10}                
        ],
        output='screen'
    )

    lidar_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(ydlidar_dir, 'launch', 'ydlidar_launch.py') 
        )
    )

    bno055_node = Node(
        package='bno055',
        executable='bno055',
        name='bno055_node',
        parameters=[
            {'connection_type': 'i2c'},
            {'i2c_bus': 1},
            {'frame_id': 'imu_link'}
        ],
        remappings=[
            ('bno055/imu', 'imu'),
            ('bno055/calib_status', 'imu/calib_status')
        ],
        output='screen'
    )

    # --- LOCALIZACIÓN Y MAPAS ---
    localizacion_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(rover_bringup_dir, 'launch', 'localizacion_imu.launch.py')
        ),
        launch_arguments={'use_sim_time': use_sim_time}.items()
    )

    map_server_node = Node(
        package='nav2_map_server',
        executable='map_server',
        name='map_server',
        output='screen',
        parameters=[{'yaml_filename': map_file},
                    {'use_sim_time': use_sim_time}]
    )

    amcl_node = Node(
        package='nav2_amcl',
        executable='amcl',
        name='amcl',
        output='screen',
        parameters=[{'use_sim_time': use_sim_time}]
    )

    lifecycle_manager = Node(
        package='nav2_lifecycle_manager',
        executable='lifecycle_manager',
        name='lifecycle_manager_localization',
        output='screen',
        parameters=[{'use_sim_time': use_sim_time},
                    {'autostart': True},
                    {'node_names': ['map_server']}]
    )

    # --- RECONOCIMIENTO Y CONTROL ---
    aruco_params_path = os.path.join(rover_bringup_dir, 'config', 'aruco.yaml')
    aruco_node = Node(
        package='ros2_aruco',
        executable='aruco_node',
        name='aruco_node',
        parameters=[aruco_params_path, {'use_sim_time': use_sim_time}],
        remappings=[
            ('/camera/color/image_raw', '/image_raw'),
            ('/camera/color/camera_info', '/camera_info')
        ],
        output='screen'
    )
    
    mock_aruco_node = ExecuteProcess(
        cmd=['python3', os.path.join(os.getcwd(), 'src', 'rover_bringup', 'config', 'mock_aruco.py'), '--ros-args', '-p', 'use_sim_time:=false'],
        output='screen'
    )

    pure_pursuit_node = ExecuteProcess(
        cmd=['python3', os.path.join(os.getcwd(), 'src', 'rover_bringup', 'src', 'simple_pure_pursuit.py')],
        output='screen'
    )
    fake_odom_node = ExecuteProcess(
        cmd=['python3', os.path.join(os.getcwd(), 'src', 'rover_bringup', 'src', 'fake_odom.py')],
        output='screen'
    )

    # --- TF ---
    camera_tf = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        name='camera_tf',
        arguments=['0.09', '0.0', '0.2', '0', '0', '0', 'base_link', 'camera']
    )

    base_footprint_tf = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        name='base_footprint_tf',
        arguments=['0', '0', '0', '0', '0', '0', 'base_link', 'base_footprint']
    )

    map_tf = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        name='map_tf',
        arguments=['0', '0', '0', '0', '0', '0', 'map', 'odom']
    )
    
    imu_tf = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        name='imu_tf',
        arguments=['0.09', '0.0', '0.2', '-1.57', '0', '0', 'base_link', 'imu_link']
    )

    return LaunchDescription([
        SetParameter(name='use_sim_time', value=False),
        DeclareLaunchArgument('use_sim_time', default_value='false'),
        
       	osr_control_launch,
        v4l2_camera_node,
        #lidar_launch,
        bno055_node,
        localizacion_launch,
        map_server_node,
        #amcl_node,
        lifecycle_manager,
        aruco_node,
        mock_aruco_node,
        pure_pursuit_node,
        camera_tf,
        map_tf,
        base_footprint_tf,
        imu_tf,
        fake_odom_node
    ])
