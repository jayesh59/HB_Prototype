import serial
import struct

uno = serial.Serial('COM8', 9600, timeout=1)
output = [0,0,0,0,0,0]

while True:
    uno.write(struct.pack('>BBBBBB', output[0],output[1],output[2],output[3],output[4],output[5]))
    data = uno.readline();
    print(data)
    