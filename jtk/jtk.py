"""
Jhonatan da Silva
Last Updated version :
Thu Feb  9 19:29:46 2017
Number of code lines: 
18
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
    
while True:
    Jtk().ativarLCD()
    time.sleep()
