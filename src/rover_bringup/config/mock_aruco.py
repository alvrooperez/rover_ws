#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseWithCovarianceStamped
from nav_msgs.msg import Odometry
import random
import math

# Si el (0,0) del mapa se generó mirando hacia el lado opuesto al de Gazebo
INVERTIR_MAPA = True

# Offset de posición inicial en el mapa.
# Ajusta estos valores a las coordenadas reales del mapa donde hace spawn el rover.
OFFSET_X = 5.2
OFFSET_Y = 2.7

# Usamos grados para que sea más fácil de probar (el código lo pasa a radianes solo)
OFFSET_YAW_GRADOS = -90.0
INVERTIR_GIRO = False # Cambiar a True si cuando el rover gira a la izquierda en Gazebo, en RViz la flecha gira a la derecha

class MockAruco(Node):
    def __init__(self):
        super().__init__('mock_aruco')
        
        # Nos suscribimos a la odometría de Gazebo que es nuestra posición "Dios" (100% real)
        self.sub = self.create_subscription(Odometry, '/odom_gazebo', self.odom_cb, 10)
        
        # Publicador para inyectar la pose al EKF Global
        self.pub = self.create_publisher(PoseWithCovarianceStamped, '/aruco_pose', 10)
        
        # Temporizador para simular que vemos un ArUco cada 6 segundos
        self.timer = self.create_timer(6.0, self.timer_cb)
        self.latest_odom = None
        
        self.get_logger().info("Nodo Mock ArUco iniciado. Enviando datos al EKF Global en /aruco_pose...")

    def odom_cb(self, msg):
        # Guardamos la última posición real conocida
        self.latest_odom = msg

    def timer_cb(self):
        if self.latest_odom is None:
            return

        # Simulamos que a veces la cámara no ve el ArUco (30% de probabilidad de fallar)
        if random.random() < 0.3:
            self.get_logger().info("Buscando ArUco... No hay marcadores a la vista.")
            return

        # Creamos el mensaje de pose inicial para AMCL
        pose_msg = PoseWithCovarianceStamped()
        pose_msg.header.stamp = self.get_clock().now().to_msg()
        pose_msg.header.frame_id = 'map' # La detección es absoluta respecto al mapa

        # Simulamos el error/ruido de lectura de la cámara (+/- 10 cm de error)
        noise_x = random.uniform(-0.1, 0.1)
        noise_y = random.uniform(-0.1, 0.1)

        # Extraemos el Yaw (rotación en Z) del cuaternión de Gazebo
        q_gz = self.latest_odom.pose.pose.orientation
        current_yaw = math.atan2(2.0 * (q_gz.w * q_gz.z + q_gz.x * q_gz.y), 1.0 - 2.0 * (q_gz.y * q_gz.y + q_gz.z * q_gz.z))

        # Invertimos el sentido del giro si es necesario
        if INVERTIR_GIRO:
            current_yaw = -current_yaw

        # Calculamos la rotación total que hay entre el mundo de Gazebo y el Mapa de RViz
        angulo_offset_rad = math.radians(OFFSET_YAW_GRADOS)
        if INVERTIR_MAPA:
            angulo_offset_rad += math.pi
            
        # 1. Rotamos la posición X e Y de Gazebo para que coincida con los ejes del mapa
        x_g = self.latest_odom.pose.pose.position.x
        y_g = self.latest_odom.pose.pose.position.y
        
        x_rot = x_g * math.cos(angulo_offset_rad) - y_g * math.sin(angulo_offset_rad)
        y_rot = x_g * math.sin(angulo_offset_rad) + y_g * math.cos(angulo_offset_rad)
        
        # Aplicamos la posición rotada + los offsets
        pose_msg.pose.pose.position.x = x_rot + OFFSET_X + noise_x
        pose_msg.pose.pose.position.y = y_rot + OFFSET_Y + noise_y
        
        # 2. Rotamos la orientación del robot con el mismo ángulo exacto
        new_yaw = current_yaw + angulo_offset_rad

        # Convertimos de nuevo el Yaw a cuaternión para publicarlo
        pose_msg.pose.pose.orientation.x = 0.0
        pose_msg.pose.pose.orientation.y = 0.0
        pose_msg.pose.pose.orientation.z = math.sin(new_yaw / 2.0)
        pose_msg.pose.pose.orientation.w = math.cos(new_yaw / 2.0)

        # Matriz de covarianza moderada (le decimos a AMCL que confiamos bastante en esta lectura)
        pose_msg.pose.covariance[0] = 0.05   # Varianza en X
        pose_msg.pose.covariance[7] = 0.05   # Varianza en Y
        pose_msg.pose.covariance[35] = 0.05  # Varianza en Yaw

        self.pub.publish(pose_msg)
        self.get_logger().info(f"¡ArUco detectado! Enviando corrección global (X: {pose_msg.pose.pose.position.x:.2f}, Y: {pose_msg.pose.pose.position.y:.2f})")

def main(args=None):
    rclpy.init(args=args)
    node = MockAruco()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()