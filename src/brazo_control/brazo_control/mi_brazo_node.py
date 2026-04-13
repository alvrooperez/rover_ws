import rclpy
from rclpy.node import Node
from .tmc2209_driver import TMC2209Driver
from gpiozero import OutputDevice
from adafruit_servokit import ServoKit
import time

class BrazoNode(Node):
    def __init__(self):
        super().__init__('brazo_control_node')

        self.kit = ServoKit(channels=16)
        self.motores_indices = [4, 5, 6, 7, 11]
        
        # Estado inicial lógico (donde el código cree que está el brazo al arrancar)
        # Lo ideal es que coincida con tu primera posición física real
        self.posiciones_actuales = {4: 30, 5: 20, 6: 90, 7: 90, 11: 100}
        
        for i in self.motores_indices:
            self.kit.servo[i].actuation_range = 300
            self.kit.servo[i].set_pulse_width_range(500, 2500)
        
        self.get_logger().info("Nodo del Brazo listo para ejecutar secuencia.")

    def mover_suave(self, canal, angulo_destino, velocidad=0.5):
        angulo_inicio = self.posiciones_actuales[canal]
        if abs(angulo_inicio - angulo_destino) < 0.1:
            return

        paso = 1.0 if angulo_destino > angulo_inicio else -1.0
        retraso = 0.01 / velocidad 

        actual = float(angulo_inicio)
        while abs(actual - angulo_destino) > 0.5:
            actual += paso
            self.kit.servo[canal].angle = actual
            time.sleep(retraso)
        
        self.kit.servo[canal].angle = angulo_destino
        self.posiciones_actuales[canal] = angulo_destino

def main(args=None):
    rclpy.init(args=args)
    node = BrazoNode()
    orden = [4, 5, 6, 7, 11] # Tu orden secuencial preferido

    # --- DEFINICIÓN DE LA SECUENCIA ---
    pasos = [
        {"nombre": "1. POSICIÓN INICIAL", "angulos": {4: 30, 5: 20, 6: 90, 7: 90, 11: 100}},
        {"nombre": "2. GRIPPER ABAJO", "angulos": {4: 30, 5: 20, 6: 150, 7: 90, 11: 100}},
        {"nombre": "3. MOVIMIENTO DE HOMBRO", "angulos": {4: 120, 5: 20, 6: 150, 7: 90, 11: 100}},
        {"nombre": "4. AJUSTE GRIPPER Y CIERRE", "angulos": {4: 120, 5: 20, 6: 90, 7: 90, 11: 170}},
        {"nombre": "5. HOMBRO DE VUELTA", "angulos": {4: 30, 5: 20, 6: 90, 7: 90, 11: 170}},
        {"nombre": "6. DEJAR PIEZA Y ABRIR", "angulos": {4: 30, 5: 70, 6: 90, 7: 90, 11: 100}},
        {"nombre": "7. BAJAR GRIPPER (EVITAR CONTACTO)", "angulos": {4: 30, 5: 70, 6: 150, 7: 90, 11: 100}},
        {"nombre": "8. VUELTA A REPOSO", "angulos": {4: 30, 5: 20, 6: 90, 7: 90, 11: 100}}
    ]

    # --- EJECUCIÓN ---
    try:
        for paso in pasos:
            node.get_logger().info(f"Ejecutando: {paso['nombre']}")
            # Dentro de cada paso, movemos motor por motor en el orden 4,5,6,7,11
            for motor in orden:
                if motor in paso['angulos']:
                    objetivo = paso['angulos'][motor]
                    node.mover_suave(motor, objetivo, velocidad=0.5) # Un poco más rápido que 0.5
                    time.sleep(0.1) # Pausa entre motores
            
            time.sleep(1.0) # Pausa de seguridad entre pasos completos

    except KeyboardInterrupt:
        node.get_logger().info("Secuencia interrumpida.")
    
    node.get_logger().info("Secuencia finalizada con éxito. Cerrando...")
    node.destroy_node()
    rclpy.shutdown()
