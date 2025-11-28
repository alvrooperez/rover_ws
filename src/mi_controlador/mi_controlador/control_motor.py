import rclpy
from rclpy.node import Node
from .roboclaw_3 import Roboclaw
import time


class Control_motor(Node):
    def __init__(self,address,baudrate):
        super().__init__('controlador_motor')
        
        
        
    
        self.rc = Roboclaw("/dev/ttyS0",baudrate) 
        self.rc.Open()
        self.address=address  
        self.get_logger().info(f"Conectando a ({baudrate}) Dirección: {self.address}")

        self.ticks=1712 #28 pulsos por vuelta 2*pi*7= cm

    def mover_motores(self,velocidad_izq,velocidad_der):
        
        v_izq=int(velocidad_izq * self.ticks)
        v_der=int(velocidad_der * self.ticks)
        
        self.rc.SpeedM1(self.address,v_izq)
        self.rc.ForwardM2(self.address,v_der)
       

def main(args=None):
    rclpy.init(args=args)
    controladora1= Control_motor(0x80,38400)
    
    try:
        controladora1.mover_motores(0.5,0.5)
        time.sleep(2)
        controladora1.mover_motores(0.0,0.0)
        time.sleep(0.1)
    except KeyboardInterrupt:
        pass

    finally:
        controladora1.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()