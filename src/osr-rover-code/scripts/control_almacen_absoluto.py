import argparse
import time
from adafruit_servokit import ServoKit

# --- CONFIGURACIÓN ---
CANAL_ASCENSOR = 10
VELOCIDAD = 0.5 
# Definimos los puntos fijos de tu estructura
POS_SUBIR = 100
POS_BAJAR = 70

def mover_suave(kit, canal, destino, velocidad):
    # LEER LA MEMORIA: Obtenemos el ángulo donde está el servo actualmente
    actual = kit.servo[canal].angle
    
    # Si es la primera vez o el valor es None, usamos un valor de seguridad
    if actual is None:
        actual = 85.0 

    print(f"Posición actual detectada: {actual:.1f}°. Moviendo a {destino}°...")

    if abs(actual - destino) < 0.1:
        print("El motor ya está en esa posición.")
        return

    paso = 1.0 if destino > actual else -1.0
    retraso = 0.01 / velocidad

    temp_pos = float(actual)
    while abs(temp_pos - destino) > 0.5:
        temp_pos += paso
        kit.servo[canal].angle = temp_pos
        time.sleep(retraso)
    
    # Ajuste final preciso
    kit.servo[canal].angle = destino

def main():
    parser = argparse.ArgumentParser(description='Control Absoluto del Ascensor')
    parser.add_argument('accion', choices=['subir', 'bajar', 'centro'], help='Dirección')
    args = parser.parse_args()

    kit = ServoKit(channels=16)
    
    # Configuración de límites del servo de 300°
    kit.servo[CANAL_ASCENSOR].actuation_range = 300
    kit.servo[CANAL_ASCENSOR].set_pulse_width_range(500, 2500)

    if args.accion == 'subir':
        mover_suave(kit, CANAL_ASCENSOR, POS_SUBIR, VELOCIDAD)
    elif args.accion == 'bajar':
        mover_suave(kit, CANAL_ASCENSOR, POS_BAJAR, VELOCIDAD)
    elif args.accion == 'centro':
        mover_suave(kit, CANAL_ASCENSOR, 85, VELOCIDAD)

    print("Movimiento completado.")

if __name__ == '__main__':
    main()
