import rclpy
from rclpy.node import Node
import sys, select, termios, tty
from .roboclaw_3 import Roboclaw
from adafruit_servokit import ServoKit
import time

# ================= CONFIGURACIÓN =================
VELOCIDAD_AVANCE = 35    # Velocidad (0-127)
ANGULO_GIRO = 35         # Grados relativos
CENTROS = [100, 107, 115, 140] # Tus centros calibrados
# =================================================

settings = None

def getKey():
    tty.setraw(sys.stdin.fileno())
    rlist, _, _ = select.select([sys.stdin], [], [], 0.1)
    if rlist:
        key = sys.stdin.read(1)
        if key == '\x1b':
            key += sys.stdin.read(2)
    else:
        key = ''
    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
    return key

# --- CLASES DE CONTROL ---
class Control_motor:
    def __init__(self, roboclaw_instance, address):
        self.rc = roboclaw_instance
        self.address = address   
    
    def mover(self, v_izq, v_der):
        if v_izq >= 0: 
            self.rc.ForwardM1(self.address, min(int(v_izq), 127))
        else:          
            self.rc.BackwardM1(self.address, min(int(abs(v_izq)), 127))
        
        if v_der >= 0: 
            self.rc.ForwardM2(self.address, min(int(v_der), 127))
        else:          
            self.rc.BackwardM2(self.address, min(int(abs(v_der)), 127))

class ControladorServos:
    def __init__(self):
        try:
            self.kit = ServoKit(channels=16)
            for i in range(4):
                self.kit.servo[i].set_pulse_width_range(500, 1800)
                # Configuración goBILDA 300 grados
                self.kit.servo[i].actuation_range = 300 
        except: 
            pass

    def mover_direccion(self, angulo_relativo):
        # Mueve los 4 servos sumando el ángulo relativo a su centro
        for i in range(4):
            centro = CENTROS[i]
            final = centro + angulo_relativo
            if final < 0: final = 0
            if final > 300: final = 300
            try: 
                self.kit.servo[i].angle = final
            except: 
                pass

def main(args=None):
    rclpy.init(args=args)
    global settings
    settings = termios.tcgetattr(sys.stdin)

    print("🔌 Conectando hardware...")
    try:
        rc = Roboclaw("/dev/ttyAMA0", 38400)
        rc.Open()
    except:
        print("❌ Error abriendo puerto RoboClaw")
        return

    # Tus 3 Rovers
    rovers = [
        Control_motor(rc, 0x80), 
        Control_motor(rc, 0x81), 
        Control_motor(rc, 0x82)
    ]
    servos = ControladorServos()

    print("\n🎮  CONTROL ACTIVO  🎮")
    print("   ⬆️  Adelante")
    print("   ⬇️  Atrás")
    print("   ⬅️  Servos -90°")
    print("   ➡️  Servos +90°")
    print("   Espacio: Centrar Servos")
    print("   P: PARADA TOTAL")
    print("   Ctrl+C: Salir")

    try:
        while True:
            key = getKey()
            
            if key == '\x1b[A':   # FLECHA ARRIBA
                print("🚀 ADELANTE")
                for r in rovers: 
                    r.mover(VELOCIDAD_AVANCE, VELOCIDAD_AVANCE)

            elif key == '\x1b[B': # FLECHA ABAJO
                print("🔙 ATRÁS")
                for r in rovers: 
                    r.mover(-VELOCIDAD_AVANCE, -VELOCIDAD_AVANCE)

            elif key == '\x1b[D': # FLECHA IZQUIERDA
                print("⬅️  SERVOS -90°")
                servos.mover_direccion(-ANGULO_GIRO)

            elif key == '\x1b[C': # FLECHA DERECHA
                print("➡️  SERVOS +90°")
                servos.mover_direccion(ANGULO_GIRO)

            elif key == ' ':      # ESPACIO -> CENTRAR
                print("👌 SERVOS CENTRADOS")
                servos.mover_direccion(0)

            elif key == 'p' or key == 'P': # TECLA P -> PARADA
                print("🛑 STOP MOTORES")
                for r in rovers: 
                    r.mover(0, 0)

            elif key == '\x03': # Ctrl+C
                break

    except Exception as e:
        print(f"Error: {e}")

    finally:
        # ESTA PARTE ES LA QUE FALLABA ANTES
        print("\nApagando todo...")
        for r in rovers: 
            r.mover(0, 0)
        
        servos.mover_direccion(0)
        termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
        rclpy.shutdown()

if __name__ == '__main__':
    main()
