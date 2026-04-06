import os
from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, RegisterEventHandler
from launch.event_handlers import OnProcessExit
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.actions import TimerAction
from launch_ros.actions import Node
import xacro

def generate_launch_description():
    
    osr_gazebo_dir = get_package_share_directory('osr_gazebo')
    ros_gz_sim_dir = get_package_share_directory('ros_gz_sim')

    # --- NUEVO: Ruta a tu mapa ---
    world_file = os.path.join(osr_gazebo_dir, 'worlds', '7x7.sdf')

    xacro_file = os.path.join(osr_gazebo_dir, 'urdf', 'osr.urdf.xacro')
    doc = xacro.process_file(xacro_file)
    params = {'robot_description': doc.toxml(), 'use_sim_time': True}

    # JAZZY: Lanzar Gazebo Harmonic CARGANDO TU MAPA
    gazebo = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(ros_gz_sim_dir, 'launch', 'gz_sim.launch.py')
        ),
        # Cambiamos 'empty.sdf' por tu archivo world_file
        launch_arguments={'gz_args': f'-r {world_file}'}.items(),
    )

    node_robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        output='screen',
        parameters=[params]
    )

    controller_spawn = Node(
        package='osr_gazebo',
        executable='osr_controller',
        output='screen'
    )
    
    spawn_entity = Node(
        package='ros_gz_sim',
        executable='create',
        arguments=[
            '-topic', 'robot_description',
            '-name', 'rover',
            '-z', '0.5' 
        ],
        output='screen'
    )

    load_joint_state_controller = Node(
        package='controller_manager',
        executable='spawner',
        arguments=['joint_state_broadcaster'],
        output='screen'
    )

    rover_wheel_controller = Node(
        package='controller_manager',
        executable='spawner',
        arguments=['wheel_controller'],
        output='screen'
    )

    servo_controller = Node(
        package='controller_manager',
        executable='spawner',
        arguments=['servo_controller'],
        output='screen'
    )
    
    return LaunchDescription([
        gazebo,
        node_robot_state_publisher,
        spawn_entity,
        controller_spawn,
        
        # 1. Esperamos 8 segundos reales después de que aparezca el robot
        RegisterEventHandler(
            event_handler=OnProcessExit(
                target_action=spawn_entity,
                on_exit=[
                    TimerAction(
                        period=8.0,
                        actions=[load_joint_state_controller]
                    )
                ],
            )
        ),
        
        # 2. Las ruedas esperan al broadcaster
        RegisterEventHandler(
            event_handler=OnProcessExit(
                target_action=load_joint_state_controller,
                on_exit=[rover_wheel_controller],
            )
        ),
        
        # 3. Los servos esperan a las ruedas
        RegisterEventHandler(
            event_handler=OnProcessExit(
                target_action=rover_wheel_controller,
                on_exit=[servo_controller],
            )
        )
    ])