from .roboclaw_3 import Roboclaw
import time


def main(args=None):
    puerto="/dev/ttyAMA0"
    baudrate=38400
    address=0x80
    rc = Roboclaw(puerto, baudrate)
    correcto=rc.Open()
    if not correcto:
        print("No se pudo abrir el puerto del RoboClaw")
        return
    else :
        print("Puerto del RoboClaw abierto correctamente")
        version=rc.ReadVersion(address)
        if version[0]==False:
            print("No se pudo leer la versión del RoboClaw")
            return
        else:
            print("Versión del RoboClaw:",version[1].decode('utf-8'))

    print("Moviendo motor ...")
    rc.ForwardM1(address, 50)
    time.sleep(2)
    rc.ForwardM1(address, 0)
    print("Motor detenido.")

if __name__ == '__main__':
    main()