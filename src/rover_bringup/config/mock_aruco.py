#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseWithCovarianceStamped, PoseArray
from tf2_ros import Buffer, TransformListener
import math

class ArucoProcessor(Node):
    def __init__(self):
        super().__init__('aruco_processor')
        
        # Nos suscribimos a las detecciones REALES de ros2_aruco
        self.sub = self.create_subscription(PoseArray, '/aruco_poses', self.pose_cb, 10)
        
        self.pub_ekf = self.create_publisher(PoseWithCovarianceStamped, '/aruco_pose', 10)
        self.pub_initial = self.create_publisher(PoseWithCovarianceStamped, '/initialpose', 10)
        self.amcl_inicializado = False

        # Buffer de TF para conocer hacia dónde está mirando el rover
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)
        
        self.get_logger().info("Puente ArUco Real -> EKF iniciado. Esperando detectar marcadores...")

    def pose_cb(self, msg: PoseArray):
        if not msg.poses:
            return

        try:
            # Buscamos la transformación desde el mapa hasta la cámara
            trans = self.tf_buffer.lookup_transform('map', msg.header.frame_id, rclpy.time.Time())
        except Exception as e:
            self.get_logger().warn(f"Esperando árbol TF para transformar el ArUco: {e}")
            return

        # Tomamos la primera detección (si hubiera más, podríamos promediar o elegir por id)
        marker_pose = msg.poses[0]
        
        # La posición del marcador respecto a la cámara (frame óptico: Z al frente, X derecha)
        z_c = marker_pose.position.z
        x_c = marker_pose.position.x
        
        # Sabemos que en Gazebo spawneamos el marcador en estas coordenadas absolutas:
        MARKER_X = 4.0
        MARKER_Y = 0.0
        
        # Extraemos el Yaw actual de la cámara respecto al mapa usando cuaterniones del TF
        q = trans.transform.rotation
        siny_cosp = 2 * (q.w * q.z + q.x * q.y)
        cosy_cosp = 1 - 2 * (q.y * q.y + q.z * q.z)
        yaw = math.atan2(siny_cosp, cosy_cosp)
        
        # Proyectamos el vector de distancia cámara->marcador hacia los ejes del mapa global
        dx = z_c * math.cos(yaw) - x_c * math.sin(yaw)
        dy = z_c * math.sin(yaw) + x_c * math.cos(yaw)
        
        # La posición de la cámara (rover) es la posición del marcador menos el vector de distancia
        cam_x = MARKER_X - dx
        cam_y = MARKER_Y - dy
        
        # Creamos el mensaje para el EKF
        pose_msg = PoseWithCovarianceStamped()
        pose_msg.header.stamp = self.get_clock().now().to_msg()
        pose_msg.header.frame_id = 'map'
        
        pose_msg.pose.pose.position.x = cam_x
        pose_msg.pose.pose.position.y = cam_y
        pose_msg.pose.pose.position.z = 0.0
        
        # Ignoramos la orientación enviada al EKF, dejando que el Odom/IMU hagan ese trabajo
        pose_msg.pose.pose.orientation.w = 1.0

        # Matriz de covarianza: Damos mucha confianza a (X, Y) y anulamos el resto
        pose_msg.pose.covariance[0] = 0.05
        pose_msg.pose.covariance[7] = 0.05
        pose_msg.pose.covariance[14] = 9999.0 # Ignorar Z
        pose_msg.pose.covariance[21] = 9999.0 # Ignorar Roll
        pose_msg.pose.covariance[28] = 9999.0 # Ignorar Pitch
        pose_msg.pose.covariance[35] = 9999.0 # Ignorar Yaw

        self.pub_ekf.publish(pose_msg)
        
        if not self.amcl_inicializado:
            init_msg = PoseWithCovarianceStamped()
            init_msg.header = pose_msg.header
            init_msg.pose.pose = pose_msg.pose.pose
            init_msg.pose.covariance = pose_msg.pose.covariance
            init_msg.pose.covariance[35] = 0.25 # Permitimos dispersión angular en AMCL
            self.pub_initial.publish(init_msg)
            self.amcl_inicializado = True
            self.get_logger().info(f"¡ArUco detectado! Partículas de AMCL inicializadas en X:{cam_x:.2f}, Y:{cam_y:.2f}")

def main(args=None):
    rclpy.init(args=args)
    node = ArucoProcessor()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()