#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist, PoseStamped
from tf2_ros import Buffer, TransformListener
import math

class SimplePurePursuit(Node):
    def __init__(self):
        super().__init__('simple_pure_pursuit')
        self.publisher_ = self.create_publisher(Twist, '/cmd_vel_intuitive', 5)
        self.subscription = self.create_subscription(PoseStamped, '/goal_pose', self.goal_callback, 10)
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)
        self.timer = self.create_timer(0.1, self.control_loop)
        self.goal = None
        self.max_v = 0.3
        self.max_w = 0.3
        self.kp_v = 0.5
        self.kp_w = 1.5
        self.dist_tol = 0.65
        self.get_logger().info("Controlador iniciado.")

    def goal_callback(self, msg):
        self.goal = msg.pose
        self.get_logger().info(f"Nuevo destino: X={self.goal.position.x:.2f}, Y={self.goal.position.y:.2f}")

    def get_current_pose(self):
        try:
            trans = self.tf_buffer.lookup_transform('map', 'base_link', rclpy.time.Time())
            x = trans.transform.translation.x
            y = trans.transform.translation.y
            q = trans.transform.rotation
            siny_cosp = 2 * (q.w * q.z + q.x * q.y)
            cosy_cosp = 1 - 2 * (q.y * q.y + q.z * q.z)
            yaw = math.atan2(siny_cosp, cosy_cosp)
            return x, y, yaw
        except Exception as e:
            self.get_logger().warn(f'No se pudo obtener TF map->base_link: {str(e)}')
            return None

    def control_loop(self):
        if self.goal is None:
            return
        pose = self.get_current_pose()
        if pose is None:
            return
        x, y, yaw = pose
        dx = self.goal.position.x - x
        dy = self.goal.position.y - y
        dist = math.hypot(dx, dy)
        msg = Twist()
        if dist < self.dist_tol:
            self.get_logger().info("Destino alcanzado!")
            self.goal = None
            self.publisher_.publish(msg)
            return
        target_yaw = math.atan2(dy, dx)
        yaw_error = target_yaw - yaw
        yaw_error = math.atan2(math.sin(yaw_error), math.cos(yaw_error))
        msg.angular.z = max(min(self.kp_w * yaw_error, self.max_w), -self.max_w)
        msg.linear.x = max(min(self.kp_v * dist, self.max_v), -self.max_v)
        if abs(yaw_error) < 0.2:
            msg.angular.z = 0.0
        self.get_logger().info(
            f"Pose: ({x:.2f},{y:.2f},{yaw:.2f}) Meta: ({self.goal.position.x:.2f},{self.goal.position.y:.2f}) "
            f"Dist: {dist:.2f}m Error: {yaw_error:.2f}rad V:{msg.linear.x:.2f} W:{msg.angular.z:.2f}",
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