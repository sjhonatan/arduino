#!usr/bin/env
# -*- coding: utf-8 -*-
"""
Jhonatan da Silva
Last Updated version :
Sat Mar  4 19:26:59 2017
Number of code lines: 
35
"""
import serial 
import io
import time
import matplotlib.pyplot as plt
import matplotlib.animation as animation 
import numpy as np 
from matplotlib import style
style.use('ggplot')
ser = serial.Serial('/dev/ttyUSB0',timeout=1,baudrate=9600)
j = 0
fig = plt.figure()
ax = fig.add_subplot(1,1,1)
voltage = 0
current = 0
voltage = []
current = []

while True:

    ser.write(b'A')
    v = ser.readline().decode('ascii')
    if len(v) > 1:
        voltage.append(v)
    c = ser.readline().decode('ascii')
    if len(c) > 1:
        current.append(c)

    if len(voltage) == 100:
        voltage = [int(v)*5/1023 for v in voltage]
        current = [int(c)*5/1023 for c in current]
        plt.scatter(voltage,current)
        plt.show()
        del voltage[:]
        del current[:]

