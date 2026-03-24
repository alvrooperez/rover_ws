import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, SetEnvironmentVariable
from launch.launch_description_sources import PythonLaunchDescriptionSource

def generate_launch_description():
    rover_bringup_dir = get_package_share_directory('rover_bringup')
    nav2_bringup_dir = get_package_share_directory('nav2_bringup')
    tb3_gazebo_dir = get_package_share_directory('turtlebot3_gazebo')
    tb3_nav2_dir = get_package_share_directory('turtlebot3_navigation2')

    # 1. Forzar el modelo Waffle (¡con cámara!)
    set_turtlebot_model = SetEnvironmentVariable(name='TURTLEBOT3_MODEL', value='waffle')

    # 2. Lanzar Gazebo con el mundo oficial
    gazebo_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(tb3_gazebo_dir, 'launch', 'turtlebot3_world.launch.py')
        )
    )

    # 3. Lanzar el cerebro de Nav2 (con el mapa correspondiente a este mundo)
    map_file = os.path.join(tb3_nav2_dir, 'map', 'map.yaml')
    nav2_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(nav2_bringup_dir, 'launch', 'bringup_launch.py')
        ),
        launch_arguments={
            'map': map_file,
            'use_sim_time': 'true',
            'autostart': 'true'  # Forzamos que despierte solo
        }.items()
    )

    # 4. Lanzar RViz
    rviz_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(nav2_bringup_dir, 'launch', 'rviz_launch.py')
        ),
        launch_arguments={'use_sim_time': 'true'}.items()
    )

    # 5. Nuestro EKF Local (Odometría + IMU)
    localizacion_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(rover_bringup_dir, 'launch', 'localizacion.launch.py')
        ),
        launch_arguments={'use_sim_time': 'true'}.items()
    )

    return LaunchDescription([
        set_turtlebot_model,
        gazebo_launch,
        nav2_launch,
        rviz_launch,
        localizacion_launch

    ])