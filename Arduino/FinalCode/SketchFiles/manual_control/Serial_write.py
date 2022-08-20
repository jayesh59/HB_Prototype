import serial
import struct
from time import sleep

uno = serial.Serial('COM8', 9600, timeout=1)
mega = serial.Serial('COM5', 9600, timeout=1)
output = [0,0,0,0,0,0]

while True:
    data = uno.readline()
    if data:
        a = data.decode('utf-8').split(',')[:-1]
        #a = list(a[0:][:-2])
        if len(a) == 6:
            for i in range(len(a)):
                output[i] = int(int(a[i])*255/1023)
            
            mega.write(struct.pack('>BBBBBB',output[0],output[1],output[2],output[3],output[4],output[5]))