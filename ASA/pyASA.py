#!usr/bin/env
# -*- coding: utf-8 -*-
"""
Jhonatan da Silva
Last Updated version :
Mon Mar  6 18:44:13 2017
Number of code lines: 
39
"""
import serial 
import io
import time
import matplotlib.pyplot as plt
import matplotlib.animation as animation 
import numpy as np 
from matplotlib import style
style.use('ggplot')
ser = serial.Serial('/dev/ttyACM0',timeout=1,baudrate=9600)
j = 0
fig = plt.figure()
ax = fig.add_subplot(1,1,1)

def livePlot(i):
    global j
    voltage = 0
    current = 0
    voltage = []
    current = []
    ser.write(b'A')
    v = ser.readline().decode('ascii')
    c = ser.readline().decode('ascii')
    if len(v) > 1:
        voltage = int(v)*5/1023
        current = int(c)*5/1023
        j += 1
        ax.scatter(voltage,current,c='c')
        print(j)
    if j > 100:
        j = 0
        ax.clear()

def makeAnimation():
    a = animation.FuncAnimation(fig,livePlot)
    plt.show()

while True:
    makeAnimation()

