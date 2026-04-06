import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    # Obtener la ruta de nuestro paquete
    rover_bringup_dir = get_package_share_directory('rover_bringup')
    
    # Ruta al archivo YAML que acabamos de crear
    ekf_config_path = os.path.join(rover_bringup_dir, 'config', 'ekf.yaml')

    # EKF Local (Odometría e IMU -> odom a base_link)
    ekf_local_node = Node(
        package='robot_localization',
        executable='ekf_node',
        name='ekf_local_node',
        output='screen',
        parameters=[
            ekf_config_path,
            {'use_sim_time': True}
        ],
        remappings=[('odometry/filtered', 'odometry/local')]
    )

    # EKF Global (Odometría, IMU y ArUcos -> map a odom)
    ekf_global_node = Node(
        package='robot_localization',
        executable='ekf_node',
        name='ekf_global_node',
        output='screen',
        parameters=[
            ekf_config_path,
            {'use_sim_time': True}
        ],
        remappings=[('odometry/filtered', 'odometry/global')]
    )

    return LaunchDescription([
        ekf_local_node,
        ekf_global_node
    ])