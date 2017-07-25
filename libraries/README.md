| Fuctions | Attiny85 | Attiny84 | Atmega8 | Attiny13 | Atmega328 | Atmega32u4 |
| :----- | :-----: | :-----: | :-----: | :-----: | :-----: | :-----: |
| Motor Forward Digital | ✓ | ✓ | ✓ | ✓ | ✓ |  | 
| Motor Backward Digital | × | ✓ | ✓ | × | ✓ |  |
| Motor Forward Analog | ✓ | ✓ | × | ✓ | × | |
| Motor Backward Analog | × | ✓ | × | × | × | |
| Button | × | ✓ | ✓ | × | ✓ | |
| PotentiometerInternal Digital | × | ✓ | ✓ | × | ✓ | |
| PotentiometerInternal Analog | × | ✓ | ✓ | × | ✓ | |
| PotentiometerExternal Digital | ✓ | ✓ | ✓ | ✓ | ✓ | |
| PotentiometerExternal Analog | ✓ | ✓ | × | ✓ | × | |
| LightSensor Digital | ✓ | ✓ | ✓ | ✓ | ✓ | |
| LightSensor Analog | ✓ | ✓ | ✓ | ✓ | ✓ | |
| UltrasonicSensor | ? | ? | ? | ? | ? | ? |
| ShineSensor Digital | ✓ | ✓ | ✓ | ✓ | ✓ | |
| ShineSensor Analog | ✓ | ✓ | × | ✓ | × | |
| Buzzer | × | ✓ | ✓ | × | ✓ | |
| Temp | ✓ | ✓ | ✓ | × | ✓ | |

## Attiny Libraries Functions

| Fuctions | [Attiny85_IO.h](https://goo.gl/e7SNYL) | [Attiny85_IO_basic.h](https://goo.gl/mPpM7q) | [Attiny84_IO.h](https://goo.gl/XXbVaZ) | [Attiny84_IO_basic.h](https://goo.gl/QJ4H8T) | [Attiny13_IO_basic.h]() |
|:----- | :-----: | :-----: | :-----: | :-----: | :-----: |
| attiny.motor("AB",1,"digital") | ✓ | ✓ | ✓ | ✓ | ✓ |
| attiny.motor("AB",-1,"digital") | × | ×  | ✓ | ✓ | × |
| attiny.motor("AB",100,"analog") | ✓ | ✓ | ✓ | ✓ | ✓ |
| attiny.motor("AB",-100,"digital") | × | ×  | ✓ | ✓ | × |
| attiny.PotentiometerInternal()==1 | × | × | ✓ | ✓ | × |
| attiny.PotentiometerInternal()>50  | × | × | ✓ | ✓ | × |
| attiny.PotentiometerExternal()==1 | ✓ | ✓ | ✓ | ✓ | ✓ |
| attiny.PotentiometerExternal()>50 | ✓ | ✓ | ✓ | ✓ | ✓ |
| attiny.LightSensor(1)==1 | ✓ | ✓ | ✓ | ✓ | ✓ |
| attiny.LightSensor(2)>20 | ✓ | ✓ | ✓ | ✓ | ✓ |
| attiny.UltrasonicSensor()>20 | ? | ? | ? | ? | ? |
| attiny.ShineSensor()==1 | ✓ | ✓ | ✓ | ✓ | ✓ |
| attiny.ShineSensor()>20 | ✓ | ✓ | ✓ | ✓ | ✓ |
| attiny.Buzzer() | × | × | ✓ | ✓ | × |
| attiny.Temp()>30 | ✓ | × | ✓ | × | × |

## Atmega Libraries Functions

| Fuctions | [Atmega8_IO.h](https://goo.gl/BfjU1t) | [Atmega8_IO_basic.h](https://goo.gl/PLgGDv) | [Atmega328_IO.h]() | [Atmega32u4_IO.h]() |
|:----- | :-----: | :-----: | :-----: | :-----: |
| atmega.motor("AB",1,"digital") | ✓ | ✓ | ✓ | ✓ |
| atmega.motor("AB",-1,"digital") | ✓ | ✓ | ✓ | ✓ |
| atmega.motor("AB",100,"analog") | × | × | × | × |
| atmega.motor("AB",-100,"digital") | × | × | × | × |
| atmega.PotentiometerInternal()==1 | ✓ | ✓ | ✓ | ✓ |
| atmega.PotentiometerInternal()>50  | ✓ | ✓ | ✓ | ✓ |
| atmega.PotentiometerExternal()==1 | ✓ | ✓ | ✓ | ✓ |
| atmega.PotentiometerExternal()>50 | × | × | × | × |
| atmega.LightSensor(1)==1 | ✓ | ✓ | ✓ | ✓ |
| atmega.LightSensor(2)>20 | ✓ | ✓ | ✓ | ✓ |
| atmega.UltrasonicSensor()>20 | ? | ? | ? | ? |
| atmega.ShineSensor()==1 | ✓ | ✓ | ✓ | ✓ |
| atmega.ShineSensor()>20 | × | × | × | × |
| atmega.Buzzer() | ✓ | ✓ | ✓ | ✓ |
| atmega.Temp()>30 | ✓ | ✓ | ✓ | ✓ |

