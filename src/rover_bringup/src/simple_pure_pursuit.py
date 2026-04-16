#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist, PoseStamped
from nav_msgs.msg import Odometry  # <--- NUEVO: Importamos Odometry
import math

class SimplePurePursuit(Node):
    def __init__(self):
        super().__init__('simple_pure_pursuit')
        
        # Publicador de velocidad
        self.publisher_ = self.create_publisher(Twist, '/cmd_vel_intuitive', 5)
        
        # Suscriptores
        self.sub_goal = self.create_subscription(PoseStamped, '/goal_pose', self.goal_callback, 10)
        
        # NUEVO: Nos suscribimos directamente a la salida del EKF en lugar de usar TF
        self.sub_odom = self.create_subscription(Odometry, '/odometry/filtered', self.odom_callback, 10)
        
        self.timer = self.create_timer(0.1, self.control_loop)
        
        self.goal = None
        self.current_pose = None  # Aquí guardaremos la posición que nos da el EKF
        
        self.max_v = 0.3
        self.max_w = 0.3
        self.kp_v = 0.5
        self.kp_w = 1.5
        self.dist_tol = 0.3
        
        self.get_logger().info("Controlador Pure Pursuit iniciado (Leyendo de /odometry/filtered).")

    def goal_callback(self, msg):
        self.goal = msg.pose
        self.get_logger().info(f"Nuevo destino: X={self.goal.position.x:.2f}, Y={self.goal.position.y:.2f}")

    # NUEVO: Callback que lee la posición exacta del EKF continuamente
    def odom_callback(self, msg):
        x = msg.pose.pose.position.x
        y = msg.pose.pose.position.y
        q = msg.pose.pose.orientation
        
        # Convertir cuaternión a Euler (Yaw)
        siny_cosp = 2 * (q.w * q.z + q.x * q.y)
        cosy_cosp = 1 - 2 * (q.y * q.y + q.z * q.z)
        yaw = math.atan2(siny_cosp, cosy_cosp)
        
        self.current_pose = (x, y, yaw)

    def control_loop(self):
        if self.goal is None or self.current_pose is None:
            return
            
        x, y, yaw = self.current_pose
        
        dx = self.goal.position.x - x
        dy = self.goal.position.y - y
        dist = math.hypot(dx, dy)
        
        msg = Twist()
        
        if dist < self.dist_tol:
            self.get_logger().info("¡Destino alcanzado!")
            self.goal = None
            msg.linear.x = 0.0
            msg.angular.z = 0.0
            self.publisher_.publish(msg)
            return
            
        target_yaw = math.atan2(dy, dx)
        yaw_error = target_yaw - yaw
        yaw_error = math.atan2(math.sin(yaw_error), math.cos(yaw_error)) 
        
        w_calc = max(min(self.kp_w * yaw_error, self.max_w), -self.max_w)
        v_calc = max(min(self.kp_v * dist, self.max_v), -self.max_v)
        
        if abs(yaw_error) < 0.2:
            w_calc = 0.0
            
        msg.angular.z = float(w_calc)
        msg.linear.x = float(v_calc)
        
        self.get_logger().info(
            f"Pose Real EKF: ({x:.2f},{y:.2f},{yaw:.2f}) | Meta: ({self.goal.position.x:.2f},{self.goal.position.y:.2f}) "
            f"Dist: {dist:.2f}m | Error: {yaw_error:.2f}rad | V:{msg.linear.x:.2f} W:{msg.angular.z:.2f}",
            throttle_duration_sec=0.5
        )
        
        self.publisher_.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = SimplePurePursuit()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()