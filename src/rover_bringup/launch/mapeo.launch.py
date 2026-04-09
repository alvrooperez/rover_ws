import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, DeclareLaunchArgument
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def generate_launch_description():
    # Directorios de los paquetes
    rover_bringup_dir = get_package_share_directory('rover_bringup')
    slam_toolbox_dir = get_package_share_directory('slam_toolbox')

    # Ruta a tu archivo de parámetros personalizado
    slam_config_path = os.path.join(rover_bringup_dir, 'config', 'mi_slam.yaml')

    # 1. Nodo de SLAM Toolbox (Modo asíncrono online)
    slam_node = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(slam_toolbox_dir, 'launch', 'online_async_launch.py')
        ),
        launch_arguments={
            'slam_params_file': slam_config_path,
            'use_sim_time': 'false'
        }.items()
    )

    # 2. (Opcional) Si quieres que este launch también arranque el EKF y sensores, 
    # podrías incluir aquí el real.launch.py, pero es mejor lanzarlos por separado 
    # para tener más control durante el mapeo.

    return LaunchDescription([
        DeclareLaunchArgument('use_sim_time', default_value='false'),
        slam_node
    ])
