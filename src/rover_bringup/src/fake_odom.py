#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist, TransformStamped
from nav_msgs.msg import Odometry
from tf2_ros import TransformBroadcaster
import math

class FakeOdom(Node):
    def __init__(self):
        super().__init__('fake_odom')
        
        # --- CALIBRACIÓN DE ODOMETRÍA ---
        # Factor lineal: Realidad (2.0m) / Odom Falsa (4.2m)
        self.linear_scale = 1
        # Factor angular: Dejar a 1.0 por ahora, ajustar si al rotar no coincide
        self.angular_scale = 1.0 
        
        # Nos suscribimos a los comandos de velocidad de tu rover
        self.sub_cmd = self.create_subscription(Twist, '/cmd_vel_intuitive', self.cmd_cb, 10)
        
        # Publicador de la odometría
        self.pub_odom = self.create_publisher(Odometry, '/odom', 10)
        
        # (Opcional) Broadcaster del árbol TF. 
        # Déjalo comentado si tu robot_localization (EKF) ya se encarga de publicar odom -> base_link
        # self.tf_broadcaster = TransformBroadcaster(self)
        
        self.x = 0.0
        self.y = 0.0
        self.th = 0.0
        self.vx = 0.0
        self.vth = 0.0
        
        self.last_time = self.get_clock().now()
        self.last_cmd_time = self.get_clock().now()
        self.timer = self.create_timer(0.05, self.update_odom) # Actualizamos a 20 Hz
        
        self.get_logger().info("Chapuza Fake Odom iniciada (Integrando /cmd_vel_intuitive para estimar posición).")

    def cmd_cb(self, msg):
        self.vx = msg.linear.x * self.linear_scale
        self.vth = msg.angular.z * self.angular_scale
        self.last_cmd_time = self.get_clock().now()

    def update_odom(self):
        current_time = self.get_clock().now()
        dt = (current_time - self.last_time).nanoseconds / 1e9
        self.last_time = current_time
        
        # Timeout de seguridad: Si hace más de 0.5 segundos que no recibimos un cmd_vel,
        # asumimos que el robot se ha detenido (el nodo de control ha dejado de publicar).
        if (current_time - self.last_cmd_time).nanoseconds / 1e9 > 0.2:
            self.vx = 0.0
            self.vth = 0.0
        
        # Integración cinemática simple (Dead Reckoning)
        delta_x = self.vx * math.cos(self.th) * dt
        delta_y = self.vx * math.sin(self.th) * dt
        delta_th = self.vth * dt
        
        self.x += delta_x
        self.y += delta_y
        self.th += delta_th
        
        q_z = math.sin(self.th / 2.0)
        q_w = math.cos(self.th / 2.0)
        
        # 1. Crear y publicar el mensaje /odom
        odom = Odometry()
        odom.header.stamp = current_time.to_msg()
        odom.header.frame_id = 'odom'
        odom.child_frame_id = 'base_link'
        
        odom.pose.pose.position.x = self.x
        odom.pose.pose.position.y = self.y
        odom.pose.pose.orientation.z = q_z
        odom.pose.pose.orientation.w = q_w
        
        odom.twist.twist.linear.x = self.vx
        odom.twist.twist.angular.z = self.vth
        
        # Covarianzas artificialmente altas porque sabemos que es una estimación sin hardware
        odom.pose.covariance[0]  = 0.5
        odom.pose.covariance[7]  = 0.5
        odom.pose.covariance[35] = 0.5

        odom.twist.covariance[0]  = 0.5
        odom.twist.covariance[7]  = 0.5
        odom.twist.covariance[35] = 0.5
        
        self.pub_odom.publish(odom)

def main(args=None):
    rclpy.init(args=args)
    node = FakeOdom()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()