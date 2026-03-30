import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, SetEnvironmentVariable, DeclareLaunchArgument, GroupAction
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node, SetRemap # Importante tener SetRemap y Node

def generate_launch_description():
    # 1. El reloj unificado
    use_sim_time = LaunchConfiguration('use_sim_time', default='true')

    rover_bringup_dir = get_package_share_directory('rover_bringup')
    nav2_bringup_dir = get_package_share_directory('nav2_bringup')
    tb3_gazebo_dir = get_package_share_directory('turtlebot3_gazebo')
    tb3_nav2_dir = get_package_share_directory('turtlebot3_navigation2')

    # Cambiamos el modelo a 'waffle_pi' que es el que incluye la cámara de profundidad.
    # El modelo 'waffle' a veces funciona, pero 'waffle_pi' es más seguro.
    set_turtlebot_model = SetEnvironmentVariable(name='TURTLEBOT3_MODEL', value='waffle_pi')

    # 2. Gazebo (Aislamos su puente defectuoso)
    gazebo_launch = GroupAction(
        actions=[
            # Mandamos el TwistStamped del puente original a un topic que nadie usa
            SetRemap(src='/cmd_vel', dst='/cmd_vel_malo'),
            IncludeLaunchDescription(
                PythonLaunchDescriptionSource(
                    os.path.join(tb3_gazebo_dir, 'launch', 'turtlebot3_world.launch.py')
                ),
                launch_arguments={'use_sim_time': use_sim_time}.items()
            )
        ]
    )

    # 2.5 NUESTRO Puente Correcto (Traduce el Twist de Nav2 directo a Gazebo)
    puente_bueno = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        # Usamos @ para que sea bidireccional y compatible con el tipo simple
        arguments=['/cmd_vel@geometry_msgs/msg/Twist@gz.msgs.Twist'],
        parameters=[{'use_sim_time': use_sim_time}],
        output='screen'
    )

    # 3. Nav2 (Lanzamiento limpio, sin alterar sus topics)
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

    # 5. Tu Localización
    localizacion_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(rover_bringup_dir, 'launch', 'localizacion.launch.py')
        ),
        launch_arguments={'use_sim_time': use_sim_time}.items()
    )

    # 6. Detección de ArUcos
    # Se asume que el paquete 'ros2_aruco' ya está instalado en tu workspace.
    # Asegúrate de haber ejecutado los comandos de instalación en el Paso 1.
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
        set_turtlebot_model,
        gazebo_launch,
        puente_bueno, # Lanzamos nuestro puente parcheado
        nav2_launch,
        rviz_launch,
        localizacion_launch,
        aruco_node
    ])