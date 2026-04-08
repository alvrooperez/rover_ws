import serial
import struct
import time
from gpiozero import OutputDevice

# --- Clase mínima para test ---
class TMCTest:
    def __init__(self, port="/dev/serial0"):
        self.ser = serial.Serial(port, 115200, timeout=0.1)
    
    def _calc_crc(self, data):
        crc = 0
        for byte in data:
            for _ in range(8):
                if (crc ^ byte) & 0x01:
                    crc = (crc >> 1) ^ 0x8C
                else:
                    crc >>= 1
                byte >>= 1
        return crc

    def escribir(self, reg, val):
        buf = struct.pack(">BBBI", 0x05, 0x00, reg | 0x80, val)
        buf += struct.pack("B", self._calc_crc(buf))
        self.ser.write(buf)

# --- Configuración de pines ---
step = OutputDevice(18)
dir_pin = OutputDevice(23)

print("Iniciando prueba de conexión...")
try:
    tmc = TMCTest()
    # 1. Intentamos configurar la corriente (Registro 0x10)
    # Mandamos un valor que active el motor
    tmc.escribir(0x10, 0x00080F0A) 
    print("Configuración UART enviada.")
    
    # 2. Prueba de movimiento
    print("Moviendo motor... (Si hay conexión correcta, el motor girará)")
    dir_pin.on()
    for _ in range(400): # 2 vueltas si no hay microstepping
        step.on()
        time.sleep(0.002)
        step.off()
        time.sleep(0.002)
        
    print("Prueba finalizada con éxito.")

except Exception as e:
    print(f"Error: {e}")
