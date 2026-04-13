#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseWithCovarianceStamped
from ros2_aruco_interfaces.msg import ArucoMarkers # CAMBIO: Importamos el mensaje que contiene los IDs
from tf2_ros import Buffer, TransformListener
import math

class ArucoProcessor(Node):
    def __init__(self):
        super().__init__('aruco_processor')
        
        # CAMBIO: Nos suscribimos a /aruco_markers para poder leer qué ID (número) estamos viendo
        self.sub = self.create_subscription(ArucoMarkers, '/aruco_markers', self.marker_cb, 10)
        
        self.pub_ekf = self.create_publisher(PoseWithCovarianceStamped, '/aruco_pose', 10)
        self.pub_initial = self.create_publisher(PoseWithCovarianceStamped, '/initialpose', 10)
        self.amcl_inicializado = False

        # Buffer de TF para conocer hacia dónde está mirando el rover
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)
        
        # ==========================================================
        # AQUÍ ESTÁ TU MAPA DE ARUCOS (ID: [X, Y])
        # Solo necesitamos X e Y absolutos de tu mapa.
        # ==========================================================
        self.mapa_arucos = {
            10: (0.035927, 0.027083), # Las coordenadas que me pasaste para el ID 10
            # Añade aquí otros ArUcos si los tienes en tu mapa, separados por comas:
            # 17: (2.5, -1.2), 
            # 22: (4.0, 3.0)
        }
        
        self.get_logger().info("Puente ArUco Real -> EKF iniciado. Esperando detectar marcadores...")

    def marker_cb(self, msg: ArucoMarkers):
        # Si no hay marcadores o la lista viene vacía, no hacemos nada
        if not msg.marker_ids:
            return

        try:
            # Buscamos la transformación desde el mapa hasta la cámara
            trans = self.tf_buffer.lookup_transform('map', msg.header.frame_id, rclpy.time.Time())
        except Exception as e:
            self.get_logger().warn(f"Esperando árbol TF para transformar el ArUco: {e}")
            return

        # Extraemos el Yaw actual de la cámara respecto al mapa usando cuaterniones del TF
        q = trans.transform.rotation
        siny_cosp = 2 * (q.w * q.z + q.x * q.y)
        cosy_cosp = 1 - 2 * (q.y * q.y + q.z * q.z)
        yaw = math.atan2(siny_cosp, cosy_cosp)

        # Procesamos TODOS los marcadores que la cámara esté viendo en este momento
        for i, marker_id in enumerate(msg.marker_ids):
            # Si el marcador que vemos no está en nuestro mapa, lo ignoramos
            if marker_id not in self.mapa_arucos:
                continue
                
            # Extraemos las coordenadas REALES de este marcador en el mundo
            MARKER_X = self.mapa_arucos[marker_id][0]
            MARKER_Y = self.mapa_arucos[marker_id][1]

            # Tomamos la medición de la cámara para este marcador concreto
            marker_pose = msg.poses[i]
            
            # La posición del marcador respecto a la cámara (frame óptico: Z al frente, X derecha)
            z_c = marker_pose.position.z
            x_c = marker_pose.position.x
            
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
                self.get_logger().info(f"¡ArUco {marker_id} detectado! Partículas de AMCL inicializadas en X:{cam_x:.2f}, Y:{cam_y:.2f}")

def main(args=None):
    rclpy.init(args=args)
    node = ArucoProcessor()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
