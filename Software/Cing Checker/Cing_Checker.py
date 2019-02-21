#!/usr/bin/python3

import ReadCingSensors
import threading
import time
from flask import Flask
from flask import abort, redirect, url_for, jsonify
from flask import render_template
from flask import send_from_directory

temp_sensor = "Reading Value"
shine_sensor1 = "Reading Value"
shine_sensor2 = "Reading Value"
button = "Reading Value"
gyro = "Reading Value"
accelerometer = "Reading Value"
battery = "Reading Value"
sound_system = "Reading Value"
light1 = "Reading Value"
light2 = "Reading Value"
oled = "Reading Value"
char_display = "Reading Value" #16x2 display
altitude = "Reading Value" #bmp180
baro = "Reading Value" #bmp180
lidar = "Reading Value" #vl53l0x
pot = "Reading Value"
Servo = "Reading Value"
ENCA = "Reading Value"
ENCB = "Reading Value"



app = Flask(__name__, static_url_path = "/img", static_folder = "img")

@app.before_first_request
def activate_job():
    def run_job():
        while True:
            global temp_sensor,shine_sensor1,shine_sensor2,button,gyro,accelerometer
            global battery,sound_system,light1,light2,oled,char_display,baro,altitude
            global lidar,pot,Servo,ENCA,ENCB
            data = []
            data = ReadCingSensors.ReadSensors()
            if(data != None):
                battery = data[0]
                accelerometer = data[2]
                sound_system = data[3]
                oled = data[4]
                char_display = data[5]
                lidar = data[7]
                baro = data[8]
                altitude = data[9]
                light1 = data[10]
                light2 = data[11]
                pot = data[12]
                button = data[13]
                shine_sensor1 = data[14]
                shine_sensor2 = data[15]
                temp_sensor = data[16]
                Servo = data[17]
                ENCA = data[18]
                ENCB = data[19]
                if(temp_sensor != "Fail"):
                    temp_sensor += "°C"
                gyro = data[1]
                if(gyro != "Fail"):
                    gyro_val = gyro.split(" ");
                    gyro = gyro_val[0] + "° " + gyro_val[1] + "° " + gyro_val[2] + "° "

            time.sleep(0.05)

    thread = threading.Thread(target=run_job)
    thread.start()


@app.route('/')
def SensorData():
    return render_template('index.html')
@app.errorhandler(404)
def page_not_found(error):
    return render_template('index.html')


if __name__ == "__main__":
    app.run(debug)

@app.route('/_update', methods= ['GET'])
def update_values():
    return jsonify(
    temp_sensor = temp_sensor,
    shine_sensor1 = shine_sensor1,
    shine_sensor2 = shine_sensor2,
    button = button,
    gyro = gyro,
    accelerometer = accelerometer,
    battery = battery,
    sound_system = sound_system,
    light1 = light1,
    light2 = light2,
    char_display = char_display,
    oled = oled,
    baro = baro,
    altitude=altitude,
    pot = pot,
    lidar = lidar,
    Servo = Servo,
    ENCA = ENCA,
    ENCB = ENCB
    )

if __name__ == '__main__':
    app.run(debug=False)
