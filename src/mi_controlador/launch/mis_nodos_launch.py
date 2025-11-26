from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        # Primer nodo: El que habla
        Node(
            package='mi_controlador',  # Nombre del paquete
            executable='habla',        # Nombre del comando (en setup.py)
            name='nodo_charlatan'      # (Opcional) Renombrar el nodo al lanzarlo
        ),
        
        # Segundo nodo: El que escucha
        Node(
            package='mi_controlador',
            executable='escucha',
            name='nodo_cotilla'
        ),
    ])