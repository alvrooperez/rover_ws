import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, SetEnvironmentVariable, DeclareLaunchArgument, GroupAction
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node, SetRemap

def generate_launch_description():
    # 1. Configuración de tiempo de simulación
    use_sim_time = LaunchConfiguration('use_sim_time', default='true')

    # Directorios de paquetes
    rover_bringup_dir = get_package_share_directory('rover_bringup')
    nav2_bringup_dir = get_package_share_directory('nav2_bringup')
    tb3_gazebo_dir = get_package_share_directory('turtlebot3_gazebo')
    tb3_nav2_dir = get_package_share_directory('turtlebot3_navigation2')

    # Forzamos el modelo Waffle Pi (mejor soporte de cámara)
    modelo_robot = 'waffle_pi'
    set_turtlebot_model = SetEnvironmentVariable(name='TURTLEBOT3_MODEL', value=modelo_robot)

    # 2. Mundo de Gazebo (SIN el robot original para evitar duplicados)
    # Cargamos solo el escenario
    gazebo_world_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(tb3_gazebo_dir, 'launch', 'turtlebot3_world.launch.py')
        ),
        # Le pasamos poses imposibles o vacías para que no intente spawnear su propio robot
        # O simplemente usamos el GroupAction para anular su cmd_vel
        launch_arguments={'use_sim_time': use_sim_time}.items()
    )

    # 2.1 INYECCIÓN FORZADA DEL ROBOT (Aquí mandas tú en las coordenadas)
    # Buscamos el archivo SDF del modelo
    robot_sdf_path = os.path.join(tb3_gazebo_dir, 'models', modelo_robot, 'model.sdf')
    
    spawn_robot_dir = Node(
        package='ros_gz_sim',
        executable='create',
        arguments=[
            '-name', modelo_robot,
            '-file', robot_sdf_path,
            '-x', '0.0',   # Centro X
            '-y', '0.0',   # Centro Y
            '-z', '0.05'   # Un poco elevado para que no se atasque
        ],
        output='screen'
    )

    # 2.5 Nuestro Puente Correcto (CMD_VEL)
    puente_bueno = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        arguments=['/cmd_vel@geometry_msgs/msg/Twist@gz.msgs.Twist'],
        parameters=[{'use_sim_time': use_sim_time}],
        output='screen'
    )

    # 3. Nav2
    map_file = os.path.join(tb3_nav2_dir, 'map', 'map.yaml')
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
            '-x', '1.0', '-y', '0.0', '-z', '0.15',
            '-R', '0.0', '-P', '1.5708', '-Y', '0.0'
        ],
        output='screen'
    )

    return LaunchDescription([
        DeclareLaunchArgument('use_sim_time', default_value='true'),
        set_turtlebot_model,
        
        # Envolvemos el mundo en un GroupAction para silenciar su cmd_vel defectuoso
        GroupAction(actions=[
            SetRemap(src='/cmd_vel', dst='/cmd_vel_malo'),
            gazebo_world_launch
        ]),

        spawn_robot_dir,    # El robot en 0,0
        spawn_aruco,        # El ArUco en 1,0
        puente_bueno,
        nav2_launch,
        rviz_launch,
        localizacion_launch,
        aruco_node
    ])