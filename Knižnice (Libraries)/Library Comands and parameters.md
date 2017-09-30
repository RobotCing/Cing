
| Attiny85/Attiny13 | Attiny84 | Atmega8/Atmega328|
|:-----:|:-----:|:-----:|
|attiny.motor("A"/"B"/"AB",0/1,"digital") |attiny.motor("A"/"B"/"AB",0/1/-1,"digital")|attiny.motor("A"/"B"/"AB",0/1/-1,"digital")| 
|attiny.motor("A"/"B"/"AB",0 - 100,"analog")|attiny.motor("A"/"B"/"AB",-100 - 100),"analog")|~~attiny.motor("A"/"B"/"AB",-100 - 100),"analog")~~|
|~~attiny.PotentiometerInternal()>50~~|attiny.PotentiometerInternal()>50|attiny.PotentiometerInternal()>50|
|~~attiny.Button()==1~~|attiny.Button()==1|attiny.Button()==1|attiny.Button()==1|
|~~atmega.PotentiometerExternal()==1~~|~~atmega.PotentiometerExternal()==1~~|atmega.PotentiometerExternal()==1|
|attiny.PotentiometerExternal()>50|attiny.PotentiometerExternal()>50|~~attiny.PotentiometerExternal()>50~~|
|attiny.LightSensor(1/2,"digital")==1|attiny.LightSensor(1/2,"digital")==1|attiny.LightSensor(1/2,"digital")==1|
|attiny.LightSensor(1/2,"analog")>20|attiny.LightSensor(1/2,"analog")>20|attiny.LightSensor(1/2,"analog")>20|
|attiny.UltrasonicSensor()>20|attiny.UltrasonicSensor()>20|attiny.UltrasonicSensor()>20|
|attiny.ShineSensor()>20|attiny.ShineSensor()>20|attiny.ShineSensor()>20|attiny.ShineSensor()=1|
|~~attiny.Buzzer(0/1/2,500)~~|attiny.Buzzer(0/1/2,500)|attiny.Buzzer(0/1/2,500)|
|attiny.Temp()>30|attiny.Temp()>30|attiny.Temp()>30|
