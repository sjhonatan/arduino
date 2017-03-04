#!usr/bin/env
# -*- coding: utf-8 -*-
"""
Jhonatan da Silva
Last Updated version :
Sat Mar  4 19:27:14 2017
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
