import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, SetEnvironmentVariable
from launch.launch_description_sources import PythonLaunchDescriptionSource

def generate_launch_description():
    # 1. Obtener la ruta del paquete nav2_bringup que instalamos antes
    nav2_bringup_dir = get_package_share_directory('nav2_bringup')
    
    # 2. Configurar la variable de entorno del modelo del robot
    set_turtlebot_model = SetEnvironmentVariable(name='TURTLEBOT3_MODEL', value='waffle')
    
    # 3. Preparar el lanzamiento de la simulacion de TurtleBot3 con Nav2
    tb3_sim_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(nav2_bringup_dir, 'launch', 'tb3_simulation_launch.py')
        ),
        launch_arguments={
            'headless': 'False',
            'use_sim_time': 'True'
        }.items()
    )

    # 4. Devolver la descripción del lanzamiento con todas las acciones
    return LaunchDescription([
        set_turtlebot_model,
        tb3_sim_launch
    ])