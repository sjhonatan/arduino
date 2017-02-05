"""
Jhonatan da Silva
Last Updated version :
Sun Feb  5 08:50:16 2017
Number of code lines: 
12
"""
import serial 
import io
import time
ser = serial.Serial('/dev/ttyUSB0')
ser.write(b'A')
time.sleep(1)

ser.write(b'B')
time.sleep(1)

ser.write(b'C')
time.sleep(1)
