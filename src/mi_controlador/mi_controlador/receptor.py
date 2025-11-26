import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class NodoReceptor(Node):
    def __init__(self):
        super().__init__('receptor_noticias')
        # Creamos la Suscripción:
        # - Debe coincidir el Tipo (String) y el Topic ('noticias_robot')
        self.subscription = self.create_subscription(
            String,
            'noticias_robot',
            self.listener_callback,
            10)
        self.subscription  # Evita advertencias de variable no usada

    def listener_callback(self, msg):
        # Esta función se activa SOLA cada vez que llega un mensaje
        self.get_logger().info('He oído: "%s"' % msg.data)

def main(args=None):
    rclpy.init(args=args)
    nodo = NodoReceptor()
    try:
        rclpy.spin(nodo)
    except KeyboardInterrupt:
        pass
    nodo.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()