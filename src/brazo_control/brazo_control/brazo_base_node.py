import rclpy
from rclpy.node import Node
from adafruit_servokit import ServoKit
from gpiozero import OutputDevice
from .tmc2209_driver import TMC2209Driver
import time

class BrazoNode(Node):
    def __init__(self):
        super().__init__('brazo_control_node')
        
        # --- CONFIGURACIÓN SERVOS ---
        self.kit = ServoKit(channels=16)
        self.motores_indices = [4, 5, 6, 7, 11]
        self.posiciones_actuales = {4: 30, 5: 20, 6: 90, 7: 90, 11: 100}
        
        for i in self.motores_indices:
            self.kit.servo[i].actuation_range = 300
            self.kit.servo[i].set_pulse_width_range(500, 2500)

        # --- CONFIGURACIÓN STEPPER (TMC2209) ---
        self.step_pin = OutputDevice(18)
        self.dir_pin = OutputDevice(23)
        self.posicion_base_actual = 0.0 
        self.pasos_por_grado = 8.88 # Basado en 3200 pasos (1/16) por vuelta completa

        try:
            self.tmc = TMC2209Driver(port="/dev/serial0")
            self.tmc.configurar_basico()
            self.get_logger().info("UART: TMC2209 configurado correctamente.")
        except Exception as e:
            self.get_logger().error(f"Error UART TMC2209: {e}")
        
        self.get_logger().info("Nodo del Brazo y Base listo.")

    def mover_suave(self, canal, angulo_destino, velocidad=0.6):
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

    def mover_base(self, grados_objetivo, velocidad=0.001):
        diferencia_grados = grados_objetivo - self.posicion_base_actual
        if abs(diferencia_grados) < 0.1:
            return

        pasos_a_dar = int(abs(diferencia_grados) * self.pasos_por_grado)
        self.dir_pin.value = True if diferencia_grados > 0 else False

        for _ in range(pasos_a_dar):
            self.step_pin.on()
            time.sleep(velocidad)
            self.step_pin.off()
            time.sleep(velocidad)
        
        self.posicion_base_actual = grados_objetivo

def main(args=None):
    rclpy.init(args=args)
    node = BrazoNode()
    orden_servos = [4, 5, 6, 7, 11]

    pasos = [
        {"nombre": "1. POSICIÓN INICIAL", "angulos": {4: 30, 5: 20, 6: 70, 7: 90, 11: 100}, "base": 0.0},
        {"nombre": "2. ROTAR BASE", "angulos": {4: 30, 5: 20, 6: 70, 7: 90, 11: 100}, "base": 0.0},
        {"nombre": "3. GRIPPER ABAJO", "angulos": {4: 30, 5: 20, 6: 70, 7: 90, 11: 100}, "base": 0.0},
        {"nombre": "4. MOVIMIENTO DE HOMBRO", "angulos": {4: 120, 5: 20, 6: 70, 7: 90, 11: 100}, "base": 0.0},
        {"nombre": "5. AJUSTE GRIPPER Y CIERRE", "angulos": {4: 120, 5: 20, 6: 70, 7: 90, 11: 170}, "base": 0.0},
        {"nombre": "6. HOMBRO DE VUELTA", "angulos": {4: 30, 5: 20, 6: 70, 7: 90, 11: 170}, "base": 90.0},
        {"nombre": "7. ROTAR BASE A DESTINO", "angulos": {4: 30, 5: 20, 6: 70, 7: 90, 11: 170}, "base": 90.0},
        {"nombre": "8. DEJAR PIEZA Y ABRIR", "angulos": {4: 30, 5: 70, 6: 70, 7: 90, 11: 100}, "base": 90.0},
        {"nombre": "9. BAJAR GRIPPER", "angulos": {4: 30, 5: 70, 6: 70, 7: 90, 11: 100}, "base": 90.0},
        {"nombre": "10. VUELTA A REPOSO", "angulos": {4: 30, 5: 20, 6: 70, 7: 90, 11: 100}, "base": 90.0}
    ]

    try:
        for paso in pasos:
            node.get_logger().info(f"Ejecutando: {paso['nombre']}")
            
            # Movimiento de Servos
            for motor in orden_servos:
                if motor in paso['angulos']:
                    objetivo = paso['angulos'][motor]
                    node.mover_suave(motor, objetivo, velocidad=0.4)
                    time.sleep(0.05)
            
            # Movimiento de Base (Stepper)
            if "base" in paso:
                node.mover_base(paso["base"])
            
            time.sleep(1.0)

    except KeyboardInterrupt:
        node.get_logger().info("Secuencia interrumpida.")
    
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
