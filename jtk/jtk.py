"""
Jhonatan da Silva
Last Updated version :
Wed Feb  8 23:35:42 2017
Number of code lines: 
13
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
while True:
    Jtk().ativarUltrassonico()
