#!/usr/bin/python3
import serial
import time

try:
	ser = serial.Serial('/dev/ttyUSB0', 115200)
except:
	try:
		ser = serial.Serial('/dev/ttyUSB1', 115200)
	except:
		print("Board is not available. Make sure your board is on (the green LED is on) and connected to the computer.")
		exit()

def ReadSerial():
	serial = str(ser.readline())
	serial_string = "";
	for x in range(2,len(serial)-5):
		serial_string += serial[x]
	return serial_string


def ReadSensors():
	values = []
	starttime = time.time()
	value = ReadSerial()
	if(value == "------"):
		for x in range(20):
			value = ReadSerial()
			if(value !="-127.00"):
				values.append(value)
			else:
				values.append("Fail")
		return(values)

if __name__ == '__main__':
	message = False
	while True:
		data = ReadSensors()
		if(data != None):
			gyro = data[1]
			if(gyro != "Fail"):
				gyro_val = gyro.split(" ");
				gyro = gyro_val[0] + "° " + gyro_val[1] + "° " + gyro_val[2] + "° "
			else:
				gyro = "Fail"
			accelerometer = data[2]
			if(accelerometer != "Fail"):
				pass
			else:
				accelerometer = " Fail"
			print("Cing modules data")
			for x in range(1):
				print("")
			print("LightSensor 1:                 {}".format(data[10]))
			print("LightSensor 2:                 {}".format(data[11]))
			print("ShineArray 1:                  {}".format(data[14]))
			print("ShineArray 2:                  {}".format(data[15]))
			print("Gyro:                          {}".format(gyro))
			print("Accelerometer:                {}".format(accelerometer))
			print("Button:                        {}".format(data[13]))
			print("Battery:                       {}".format(data[0]))
			print("TempSensor:                    {}".format(data[16]))
			print("Barometric Pressure Sensor:    {}".format(data[8]))
			print("Altitude Sensor:               {}".format(data[9]))
			print("Sound System:                  {}".format(data[3]))
			print("Potentiometer:                 {}".format(data[16]))
			print("Servo Driver 2:                {}".format(data[17]))
			print("Encoder A:                     {}".format(data[18]))
			print("Encoder B:                     {}".format(data[19]))
			for x in range(5):
				print("")
		elif(message == False):
			print("Connecting to board. Please wait.")
			for x in range(21):
				print("")
			message = True
