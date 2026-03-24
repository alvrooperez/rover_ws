import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    # Obtener la ruta de nuestro paquete
    rover_bringup_dir = get_package_share_directory('rover_bringup')
    
    # Ruta al archivo YAML que acabamos de crear
    ekf_config_path = os.path.join(rover_bringup_dir, 'config', 'ekf.yaml')

    # Configurar el nodo de robot_localization
    ekf_node = Node(
        package='robot_localization',
        executable='ekf_node',
        name='ekf_filter_node',
        output='screen',
        parameters=[
            ekf_config_path,
            {'use_sim_time': True} # Forzamos el tiempo simulado aquí también
        ]
    )

    return LaunchDescription([
        ekf_node
    ])