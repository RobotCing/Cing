#!/usr/bin/python3
import serial
import time
ports = ['/dev/ttyUSB','COM']
error = 0
config = open("config.txt","r")
config.readline()
port = config.readline().split("=")
port = port[1]
port = port.strip()

def BoardNotFound():
	print("Board is not available. Make sure your board is on (the green LED is on) and connected to the computer.")
	exit()

if(port == "AUTO"):
	for x in range(len(ports)):
		for y in range(255):
			try:
				ser = serial.Serial(ports[x]+str(y), 9600)
				print("Opening port: {}. Please wait.".format())
				break
			except:
				error += 1
			if(error > len(ports)*256):
				BoardNotFound()
else:
	ser = serial.Serial(port, 9600)


def ReadSerial():
	serial = str(ser.readline())
	serial_string = ""
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
			gyro = data[4]
			if(gyro != "Fail"):
				gyro_val = gyro.split(" ");
				gyro = gyro_val[0] + "° " + gyro_val[1] + "° " + gyro_val[2] + "° "
			else:
				gyro = "Fail"
			accelerometer = data[5]
			if(accelerometer != "Fail"):
				pass
			else:
				accelerometer = " Fail"
			print("---------------------------------------------------------")
			print("|                 Cing modules data                     |")
			print("---------------------------------------------------------")
			print("LightSensor 1:                 {}" .format(data[0]))
			print("LightSensor 2:                 {}".format(data[1]))
			print("ShineArray 1:                  {}".format(data[2]))
			print("ShineArray 2:                  {}".format(data[3]))
			print("Gyro:                          {}".format(gyro))
			print("Accelerometer:                {}".format(accelerometer))
			print("Button:                        {}".format(data[6]))
			print("Battery:                       {}".format(data[7]))
			print("OLED:                          {}".format(data[8]))
			print("16x2 Display:                  {}".format(data[9]))
			print("Ultrasonic:                    {}".format(data[10]))
			print("Lidar:                         {}".format(data[11]))
			print("TempSensor:                    {}".format(data[12]))
			print("Barometric Pressure Sensor:    {}".format(data[13]))
			print("Altitude Sensor:               {}".format(data[14]))
			print("IO expander:                   {}".format(data[15]))
			print("Potentiometer:                 {}".format(data[16]))
			print("Servo Driver:                  {}".format(data[17]))
			print("Encoder A:                     {}".format(data[18]))
			print("Encoder B:                     {}".format(data[19]))

		elif(message == False):
			print("Connecting to board. Please wait.")
			for x in range(21):
				print("")
			message = True
