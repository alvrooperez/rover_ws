import argparse
import time
from adafruit_servokit import ServoKit

# --- CONFIGURACIÓN ---
CANAL_ASCENSOR = 10
ANGULO_SUBIR = 100
ANGULO_BAJAR = 70
VELOCIDAD = 0.5  # Mitad de la velocidad máxima

def mover_suave(kit, canal, actual, destino, velocidad):
    """Mueve el motor grado a grado para controlar la velocidad."""
    paso = 1.0 if destino > actual else -1.0
    retraso = 0.01 / velocidad

    while abs(actual - destino) > 0.5:
        actual += paso
        kit.servo[canal].angle = actual
        time.sleep(retraso)
    
    kit.servo[canal].angle = destino
    return destino

def main():
    parser = argparse.ArgumentParser(description='Control del eje Z (Ascensor)')
    parser.add_argument('accion', choices=['subir', 'bajar'], help='Dirección del movimiento')
    args = parser.parse_args()

    kit = ServoKit(channels=16)
    
    # Configuración de límites (igual que los otros motores)
    kit.servo[CANAL_ASCENSOR].actuation_range = 300
    kit.servo[CANAL_ASCENSOR].set_pulse_width_range(500, 2500)

    # Nota: Al ser un script independiente, no sabemos la posición previa.
    # Para mayor seguridad, asumimos que empieza en un punto medio o 
    # simplemente iniciamos el movimiento desde donde esté.
    # En este caso, usaremos 75 como punto de referencia intermedio.
    posicion_estimada = 75 
    
    if args.accion == 'subir':
        print(f"Subiendo a {ANGULO_SUBIR} grados...")
        mover_suave(kit, CANAL_ASCENSOR, posicion_estimada, ANGULO_SUBIR, VELOCIDAD)
    elif args.accion == 'bajar':
        print(f"Bajando a {ANGULO_BAJAR} grados...")
        mover_suave(kit, CANAL_ASCENSOR, posicion_estimada, ANGULO_BAJAR, VELOCIDAD)

    print("Movimiento completado.")

if __name__ == '__main__':
    main()
