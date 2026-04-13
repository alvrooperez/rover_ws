import serial
import struct

class TMC2209Driver:
    def __init__(self, port="/dev/serial0", baudrate=115200):
        self.ser = serial.Serial(port, baudrate, timeout=0.1)

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

    def escribir_registro(self, reg, val):
        # Paquete: [Sync, Addr, Reg+RW, Data(4 bytes), CRC]
        buf = struct.pack(">BBBI", 0x05, 0x00, reg | 0x80, val)
        buf += struct.pack("B", self._calc_crc(buf))
        self.ser.write(buf)

    def configurar_basico(self):
        # Ejemplo: Configurar corriente y micropasos (Registro IHOLD_IRUN 0x10)
        # Este valor es un ejemplo para corriente media
        self.escribir_registro(0x10, 0x00080F0A) 
        # Habilitar StealthChop (Silencio)
        self.escribir_registro(0x6C, 0x10000053)
