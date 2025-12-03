import rclpy
from rclpy.node import Node
from .roboclaw_3 import Roboclaw
import time
from adafruit_servokit import ServoKit


class Control_motor:
    def __init__(self,roboclaw_instance,address):

        self.rc = roboclaw_instance
        self.address=address  
        
        self.ticks=1712 #28 pulsos por vuelta 2*pi*7= cm

    def mover_motores(self,velocidad_izq,velocidad_der):
        
        v_izq=int(velocidad_izq * self.ticks)
        v_der=int(velocidad_der * self.ticks)
        
        self.rc.SpeedM1(self.address,v_izq)
        self.rc.SpeedM2(self.address,v_der)
    
    def motores_bruto(self, velocidad_izq, velocidad_der):
        """
        Mueve los motores por voltaje directo (Duty Cycle).
        Rango de entrada: -127 (atrás tope) a 127 (adelante tope).
        0 es parado.
        """
        
        # --- MOTOR 1 (Izquierda) ---
        if velocidad_izq >= 0:
            # Aseguramos que no pase de 127
            velocidad = min(int(velocidad_izq), 127) 
            self.rc.ForwardM1(self.address, velocidad)
        else:
            # Convertimos negativo a positivo y aseguramos tope 127
            velocidad = min(int(abs(velocidad_izq)), 127)
            self.rc.BackwardM1(self.address, velocidad)

        # --- MOTOR 2 (Derecha) ---
        # Aquí estaba el error: 'SpeedM2' usa PID. 
        # Lo cambiamos por Forward/BackwardM2 para control directo.
        if velocidad_der >= 0:
            velocidad = min(int(velocidad_der), 127)
            self.rc.ForwardM2(self.address, velocidad)
        else:
            velocidad = min(int(abs(velocidad_der)), 127)
            self.rc.BackwardM2(self.address, velocidad)

class ControladorServos:
    def __init__(self):
        # Inicializamos la placa de 16 canales
        try:
            self.kit = ServoKit(channels=16)
            print("✅ Controlador de Servos iniciado correctamente.",flush=True)
        except Exception as e:
            print(f"❌ Error al iniciar ServoKit: {e}",flush=True)

    def mover(self, canal, angulo):
        """
        Mueve el servo del 'canal' (0-15) al 'angulo' (0-180).
        """
        # 1. Protección de seguridad para el ángulo (Clamp)
        # Si pides más de 180, lo baja a 180. Si pides menos de 0, lo sube a 0.
        if angulo > 180:
            angulo = 180
        elif angulo < 0:
            angulo = 0
            
        # 2. Protección de canal válido
        if 0 <= canal <= 15:
            try:
                self.kit.servo[canal].angle = angulo
                # print(f"Servo {canal} movido a {angulo}°") # Descomenta para ver logs
            except Exception as e:
                print(f"⚠️ Error moviendo servo {canal}: {e}",flush=True)
        else:
            print(f"⚠️ Error: El canal {canal} no existe (Usa 0-15).",flush=True)

    def apagar_todos(self):
        """Libera la fuerza de todos los servos (para que no consuman)"""
        for i in range(16):
            try:
                self.kit.servo[i].angle = None
            except:
                pass


def main(args=None):
    print("Iniciando nodo de control de motores y servos...",flush=True)
    rclpy.init(args=args)
    # --- 1. CREAMOS LA CONEXIÓN MAESTRA (UNA SOLA VEZ) ---
    print("🔌 Abriendo puerto Roboclaw COMPARTIDO...", flush=True)
    roboclaw_maestra = Roboclaw("/dev/ttyAMA0", 38400)
    
    if roboclaw_maestra.Open():
        print("✅ Puerto abierto correctamente.", flush=True)
        # Aquí aplicamos el truco de velocidad UNA VEZ para todos
        roboclaw_maestra._port.timeout = 0.1 
        roboclaw_maestra._trys = 1
    else:
        print("❌ Error fatal: No se pudo abrir el puerto.", flush=True)
        return # Salimos si no hay conexión
        
    # --- 2. PASAMOS LA CONEXIÓN A LAS CONTROLADORAS ---
    # Fíjate que le pasamos 'roboclaw_maestra' como primer argumento
    controladora1 = Control_motor(roboclaw_maestra, 0x80)
    controladora2 = Control_motor(roboclaw_maestra, 0x81)
    controladora3 = Control_motor(roboclaw_maestra, 0x82)
    servo=ControladorServos()
    try:
        print("Avanzando motores a velocidad bruta 100",flush=True)
        print("1. Enviando orden motor...", flush=True)
        t_inicio_comando = time.time()
        
        
        
        #controladora1.motores_bruto(35,35)
        #time.sleep(0.2)
        controladora2.motores_bruto(35,35)
        #time.sleep(0.2)
        #controladora3.motores_bruto(35,35)
        time.sleep(2)
        t_fin_comando = time.time()
        print(f"   -> Tiempo enviando comando: {t_fin_comando - t_inicio_comando:.4f} seg", flush=True)
        print("Deteniendo motores",flush=True)
        controladora1.motores_bruto(0.0,0.0)
        controladora2.motores_bruto(0.0,0.0)
        controladora3.motores_bruto(0.0,0.0)
        time.sleep(1)
        print("Moviendo servos a 45 grados",flush=True)
        servo.mover(0,45)
        servo.mover(1,45)
        servo.mover(2,45)
        servo.mover(3,45)
        time.sleep(1)
        servo.mover(0,0)
        time.sleep(1)
        servo.apagar_todos()

    except KeyboardInterrupt:
        pass

    finally:
        print("Cerrando nodos...",flush=True)
        rclpy.shutdown()

if __name__ == '__main__':
    main()
