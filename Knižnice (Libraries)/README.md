# Library function table for procesors 

## Attiny Libraries Functions

| Fuctions | [Attiny85_IO.h](https://goo.gl/e7SNYL) | [Attiny85_IO_basic.h](https://goo.gl/mPpM7q) | [Attiny84_IO.h](https://goo.gl/XXbVaZ) | [Attiny84_IO_basic.h](https://goo.gl/QJ4H8T) | [Attiny13_IO_basic.h]() |
|:----- | :-----: | :-----: | :-----: | :-----: | :-----: |
| attiny.RunMotor("AB",1,"digital") | ✓ | ✓ | ✓ | ✓ | ✓ |
| attiny.RunMotor("AB",-1,"digital") | × | ×  | ✓ | ✓ | × |
| attiny.RunMotor("AB",100,"analog") | ✓ | ✓ | ✓ | ✓ | ✓ |
| attiny.RunMotor("AB",-100,"analog") | × | ×  | ✓ | ✓ | × |
| attiny.ReadButton()==1 | × | × | ✓ | ✓ | × |
| attiny.ReadProtentiometerExternal()==1 | × | × | × | × | × |
| attiny.ReadProtentiometerExternal()>50 | ✓ | ✓ | ✓ | ✓ | ✓ |
| attiny.ReadLightSensor(1,"digital")==1 | ✓ | ✓ | ✓ | ✓ | ✓ |
| attiny.ReadLightSensor(2,"analog")>20 | ✓ | ✓ | ✓ | ✓ | ✓ |
| attiny.ReadShineSensor()==1 | × | × | × | × | × |
| attiny.ReadShineSensor()>20 | ✓ | ✓ | ✓ | ✓ | ✓ |
| attiny.ReadTempSensor()>30 | ✓ | × | ✓ | × | × |
<!--| attiny.UltrasonicSensor()>20 | ? | ? | ? | ? | × |-->

## Atmega Libraries Functions

| Fuctions | [Atmega8_IO.h](https://goo.gl/BfjU1t) | [Atmega8_IO_basic.h](https://goo.gl/PLgGDv) | [Atmega328_IO.h]() | [Atmega32u4_IO.h]() |
|:----- | :-----: | :-----: | :-----: | :-----: |
| atmega.RunMotor("AB",1,"digital") | ✓ | ✓ | ✓ | ✓ |
| atmega.RunMotor("AB",-1,"digital") | ✓ | ✓ | ✓ | ✓ |
| atmega.RunMotor("AB",100,"analog") | × | × | × | × |
| atmega.RunMotor("AB",-100,"digital") | × | × | × | × |
| atmega.ReadButton()==1 | ✓ | ✓ | ✓ | ✓ | ✓ |
| atmega.ReadProtentiometerExternal()==1 | ✓ | ✓ | ✓ | ✓ |
| atmega.ReadProtentiometerExternal()>50 | × | × | × | × |
| atmega.ReadLightSensor(1)==1 | ✓ | ✓ | ✓ | ✓ |
| atmega.ReadLightSensor(2)>20 | ✓ | ✓ | ✓ | ✓ |
| atmega.ReadShineSensor()==1 | ✓ | ✓ | ✓ | ✓ |
| atmega.ReadShineSensor()>20 | × | × | × | × |
| atmega.ReadTempSensor()>30 | ✓ | ✓ | ✓ | ✓ |
|LedStart()| × | × | ✓ | ✓ |
|LedSetColor(1,100,100,100)| × | × | ✓ | ✓ |
|LedShow()| × | × | ✓ | ✓ |
<!--| atmega.UltrasonicSensor()>20 | ? | ? | ? | ? |-->

