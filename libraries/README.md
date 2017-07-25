# Library function table for procesors 

## Attiny Libraries Functions

| Fuctions | [Attiny85_IO.h](https://goo.gl/e7SNYL) | [Attiny85_IO_basic.h](https://goo.gl/mPpM7q) | [Attiny84_IO.h](https://goo.gl/XXbVaZ) | [Attiny84_IO_basic.h](https://goo.gl/QJ4H8T) | [Attiny13_IO_basic.h]() |
|:----- | :-----: | :-----: | :-----: | :-----: | :-----: |
| attiny.motor("AB",1,"digital") | ✓ | ✓ | ✓ | ✓ | ✓ |
| attiny.motor("AB",-1,"digital") | × | ×  | ✓ | ✓ | × |
| attiny.motor("AB",100,"analog") | ✓ | ✓ | ✓ | ✓ | ✓ |
| attiny.motor("AB",-100,"digital") | × | ×  | ✓ | ✓ | × |
| attiny.PotentiometerInternal()>50  | × | × | ✓ | ✓ | × |
| attiny.Button()==1 | × | × | ✓ | ✓ | × |
| attiny.PotentiometerExternal()==1 | × | × | × | × | × |
| attiny.PotentiometerExternal()>50 | ✓ | ✓ | ✓ | ✓ | ✓ |
| attiny.LightSensor(1,"digital")==1 | ✓ | ✓ | ✓ | ✓ | ✓ |
| attiny.LightSensor(2,"analog")>20 | ✓ | ✓ | ✓ | ✓ | ✓ |
| attiny.UltrasonicSensor()>20 | ? | ? | ? | ? | ? |
| attiny.ShineSensor()==1 | × | × | × | × | × |
| attiny.ShineSensor()>20 | ✓ | ✓ | ✓ | ✓ | ✓ |
| attiny.Buzzer(0) | × | × | ✓ | ✓ | × |
| attiny.Temp()>30 | ✓ | × | ✓ | × | × |

## Atmega Libraries Functions

| Fuctions | [Atmega8_IO.h](https://goo.gl/BfjU1t) | [Atmega8_IO_basic.h](https://goo.gl/PLgGDv) | [Atmega328_IO.h]() | [Atmega32u4_IO.h]() |
|:----- | :-----: | :-----: | :-----: | :-----: |
| atmega.motor("AB",1,"digital") | ✓ | ✓ | ✓ | ✓ |
| atmega.motor("AB",-1,"digital") | ✓ | ✓ | ✓ | ✓ |
| atmega.motor("AB",100,"analog") | × | × | × | × |
| atmega.motor("AB",-100,"digital") | × | × | × | × |
| atmega.PotentiometerInternal()>50  | ✓ | ✓ | ✓ | ✓ |
| atmega.Button()==1 | ✓ | ✓ | ✓ | ✓ | ✓ |
| atmega.PotentiometerExternal()==1 | ✓ | ✓ | ✓ | ✓ |
| atmega.PotentiometerExternal()>50 | × | × | × | × |
| atmega.LightSensor(1)==1 | ✓ | ✓ | ✓ | ✓ |
| atmega.LightSensor(2)>20 | ✓ | ✓ | ✓ | ✓ |
| atmega.UltrasonicSensor()>20 | ? | ? | ? | ? |
| atmega.ShineSensor()==1 | ✓ | ✓ | ✓ | ✓ |
| atmega.ShineSensor()>20 | × | × | × | × |
| atmega.Buzzer() | ✓ | ✓ | ✓ | ✓ |
| atmega.Temp()>30 | ✓ | ✓ | ✓ | ✓ |

