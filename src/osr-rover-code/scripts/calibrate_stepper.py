import argparse
import time
from gpiozero import OutputDevice
from brazo_control.tmc2209_driver import TMC2209Driver

def main():
    parser = argparse.ArgumentParser(
        prog='StepperCalibrator',
        description='Mueve el motor NEMA 17 de la base una cantidad específica de grados.'
    )
    
    parser.add_argument('grados', type=float, 
                        help='Grados a mover (ejemplo: 45 o -45 para sentido inverso)')
    parser.add_argument('--speed', type=float, default=0.001, 
                        help='Velocidad (delay entre pasos). Por defecto 0.001')

    args = parser.parse_args()

    # --- Configuración de Hardware ---
    step_pin = OutputDevice(18)
    dir_pin = OutputDevice(23)
    # Importante: el pin EN debe estar a GND (físico o mediante GPIO si lo usas)
    
    # --- Configuración UART ---
    try:
        tmc = TMC2209Driver(port="/dev/serial0")
        tmc.configurar_basico()
        print("UART: TMC2209 configurado.")
    except Exception as e:
        print(f"Error UART: {e}")

    # --- Cálculo de pasos ---
    # 3200 pasos = 360 grados (con microstepping 1/16)
    pasos_por_grado = 8.88
    pasos_a_dar = int(abs(args.grados) * pasos_por_grado)
    
    # Determinar dirección
    dir_pin.value = True if args.grados > 0 else False
    
    print(f"Moviendo {args.grados} grados ({pasos_a_dar} pasos)...")

    # --- Ejecución del movimiento ---
    for _ in range(pasos_a_dar):
        step_pin.on()
        time.sleep(args.speed)
        step_pin.off()
        time.sleep(args.speed)

    print("Movimiento finalizado.")

if __name__ == '__main__':
    main()
