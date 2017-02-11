"""
Jhonatan da Silva
Last Updated version :
Sat Feb 11 14:36:15 2017
Number of code lines: 
21
"""
import serial 
import io
import time
ser = serial.Serial('/dev/ttyUSB0')

class Jtk():
    def __init__(self):
        pass
    
    def ativarUltrassonico(self):
        ser.write(b'U')

    def ativarLCD(self):
        ser.write(b'L')
    
    def carrinho(...):
        ....

while True:
    Jtk().ativarLCD()
    time.sleep(.1)
