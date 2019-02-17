import sys
import serial
ser = serial.Serial('/dev/ttyUSB0', 115200)
while True:
	sys.stdout.write(ser.readline())
