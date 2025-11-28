from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        # Primer nodo: El que habla
        Node(
            package='mi_controlador',  # Nombre del paquete
            executable='motor',        # Nombre del comando (en setup.py)
            name='nodo_motores'      # (Opcional) Renombrar el nodo al lanzarlo
        ),
        
    
    ])