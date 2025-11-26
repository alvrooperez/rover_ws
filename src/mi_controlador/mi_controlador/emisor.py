import rclpy
from rclpy.node import Node
from std_msgs.msg import String  # Importamos el tipo de mensaje de texto

class NodoEmisor(Node):
    def __init__(self):
        super().__init__('emisor_noticias')
        # Creamos un Publicador:
        # - Tipo de mensaje: String
        # - Nombre del Topic: 'noticias_robot' (el canal de radio)
        # - Cola (10): Si se envían muchos muy rápido, guarda 10 antes de borrar
        self.publisher_ = self.create_publisher(String, 'noticias_robot', 10)
        
        # Timer de 1 segundo
        self.timer = self.create_timer(1.0, self.timer_callback)
        self.i = 0

    def timer_callback(self):
        msg = String()
        msg.data = 'Hola, mensaje número: %d' % self.i
        
        # ¡Publicamos el mensaje!
        self.publisher_.publish(msg)
        self.get_logger().info('Publicando: "%s"' % msg.data)
        self.i += 1

def main(args=None):
    rclpy.init(args=args)
    nodo = NodoEmisor()
    try:
        rclpy.spin(nodo)
    except KeyboardInterrupt:
        pass
    nodo.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()