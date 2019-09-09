# Libraries links

* https://github.com/RobotCing/Attiny85_IO_basic
* https://github.com/RobotCing/Attiny85_IO
* https://github.com/RobotCing/Attiny84_IO_basic
* https://github.com/RobotCing/Attiny84_IO
* https://github.com/RobotCing/Atmega8_IO_basic
* https://github.com/RobotCing/Atmega8_IO
* https://github.com/RobotCing/Atmega328_IO

# Library function table for procesors

## Attiny Libraries Functions

| Fuctions | [Attiny85_IO.h](https://goo.gl/e7SNYL) | [Attiny85_IO_basic.h](https://goo.gl/mPpM7q) | [Attiny84_IO.h](https://goo.gl/XXbVaZ) | [Attiny84_IO_basic.h](https://goo.gl/QJ4H8T) | [Attiny13_IO_basic.h]() |
|:----- | :-----: | :-----: | :-----: | :-----: | :-----: |
| Cing.RunMotor("AB",1,"digital") | ✓ | ✓ | ✓ | ✓ | ✓ |
| Cing.RunMotor("AB",-1,"digital") | × | ×  | ✓ | ✓ | × |
| Cing.RunMotor("AB",100,"analog") | ✓ | ✓ | ✓ | ✓ | ✓ |
| Cing.RunMotor("AB",-100,"analog") | × | ×  | ✓ | ✓ | × |
| Cing.ReadButtonExternal()==1 | × | × | ✓ | ✓ | × |
| Cing.ReadPotentiometerExternal()>50 | ✓ | ✓ | ✓ | ✓ | ✓ |
| Cing.ReadLightSensor(1,"digital")==1 | ✓ | ✓ | ✓ | ✓ | ✓ |
| Cing.ReadLightSensor(2,"analog")>20 | ✓ | ✓ | ✓ | ✓ | ✓ |
| Cing.ReadShineSensor()>20 | ✓ | ✓ | ✓ | ✓ | ✓ |
| Cing.ReadTempSensor()>30 | ✓ | × | ✓ | × | × |
| Cing.UltrasonicSensor()>20 | ? | ? | ? | ? | ? |

## Atmega Libraries Functions

| Fuctions | [Atmega8_IO.h](https://goo.gl/BfjU1t) | [Atmega8_IO_basic.h](https://goo.gl/PLgGDv) | [Atmega328_IO.h]() | [Atmega32u4_IO.h]() |
|:----- | :-----: | :-----: | :-----: | :-----: |
| Cing.RunMotor("AB",1,"digital") | ✓ | ✓ | ✓ | ✓ |
| Cing.RunMotor("AB",-1,"digital") | ✓ | ✓ | ✓ | ✓ |
| Cing.RunMotor("AB",100,"analog") | × | × | × | × |
| Cing.RunMotor("AB",-100,"digital") | × | × | × | × |
| Cing.ReadButton()==1 | ✓ | ✓ | ✓ | ✓ | ✓ |
| Cing.ReadButtonExternal()==1 | ? | ? | ? | ? |
| Cing.ReadPotentiometer()>50 | ? | ? | ? | ? |
| Cing.ReadLightSensor(1)==1 | ✓ | ✓ | ✓ | ✓ |
| Cing.ReadLightSensor(2)>20 | ✓ | ✓ | ✓ | ✓ |
| Cing.ReadShineSensor()==1 | ✓ | ✓ | ✓ | ✓ |
| Cing.ReadShineSensor()>20 | × | × | × | × |
| Cing.ReadTempSensor()>30 | ✓ | ✓ | ✓ | ✓ |
|Cing.LedStart()| × | × | ✓ | ✓ |
|Cing.SetLedColor(1,100,100,100)| × | × | ✓ | ✓ |
|Cing.LedShow()| × | × | ✓ | ✓ |
| Cing.UltrasonicSensor()>20 | ? | ? | ? | ? |
| Cing.ReadColorSensor()==5 | ? | ? | ? | ? |
