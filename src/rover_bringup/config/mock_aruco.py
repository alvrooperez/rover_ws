#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseWithCovarianceStamped
from nav_msgs.msg import Odometry
import random

# Si el (0,0) del mapa se generó mirando hacia el lado opuesto al de Gazebo
INVERTIR_MAPA = True

# Offset de posición inicial en el mapa.
# Ajusta estos valores a las coordenadas reales del mapa donde hace spawn el rover.
OFFSET_X = 5.2
OFFSET_Y = 2.7

class MockAruco(Node):
    def __init__(self):
        super().__init__('mock_aruco')
        
        # Nos suscribimos a la odometría de Gazebo que es nuestra posición "Dios" (100% real)
        self.sub = self.create_subscription(Odometry, '/odom_gazebo', self.odom_cb, 10)
        
        # Publicador para inyectar la pose a AMCL (que usa el LiDAR)
        self.pub = self.create_publisher(PoseWithCovarianceStamped, '/initialpose', 10)
        
        # Temporizador para simular que vemos un ArUco cada 6 segundos
        self.timer = self.create_timer(6.0, self.timer_cb)
        self.latest_odom = None
        
        self.get_logger().info("Nodo Mock ArUco iniciado. Trabajando en conjunto con el LiDAR (AMCL)...")

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

        if INVERTIR_MAPA:
            # Invertimos X e Y y aplicamos el offset
            pose_msg.pose.pose.position.x = -self.latest_odom.pose.pose.position.x + OFFSET_X + noise_x
            pose_msg.pose.pose.position.y = -self.latest_odom.pose.pose.position.y + OFFSET_Y + noise_y
            # Rotamos el cuaternión de orientación exactamente 180 grados (Eje Z)
            pose_msg.pose.pose.orientation.x = 0.0
            pose_msg.pose.pose.orientation.y = 0.0
            pose_msg.pose.pose.orientation.z = self.latest_odom.pose.pose.orientation.w
            pose_msg.pose.pose.orientation.w = -self.latest_odom.pose.pose.orientation.z
        else:
            pose_msg.pose.pose.position.x = self.latest_odom.pose.pose.position.x + OFFSET_X + noise_x
            pose_msg.pose.pose.position.y = self.latest_odom.pose.pose.position.y + OFFSET_Y + noise_y
            pose_msg.pose.pose.orientation = self.latest_odom.pose.pose.orientation

        # Matriz de covarianza moderada (le decimos a AMCL que confiamos bastante en esta lectura)
        pose_msg.pose.covariance[0] = 0.05   # Varianza en X
        pose_msg.pose.covariance[7] = 0.05   # Varianza en Y
        pose_msg.pose.covariance[35] = 0.05  # Varianza en Yaw

        self.pub.publish(pose_msg)
        self.get_logger().info(f"¡ArUco detectado! Corrigiendo LiDAR/AMCL a X: {pose_msg.pose.pose.position.x:.2f}, Y: {pose_msg.pose.pose.position.y:.2f}")

def main(args=None):
    rclpy.init(args=args)
    node = MockAruco()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()