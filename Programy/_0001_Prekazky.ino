#include <Atmega8_IO.h>
Atmega atmega;
void setup(){}
void loop() 
  {
    if (atmega.UltrasonicSensor()<=20) 
      {
        atmega.motor("AB", 0, "digital");
        for (int x;x<10;x++)
          {
            atmega.Buzzer(1);
            delay(500);
            atmega.Buzzer(0);
            delay(500);
          }
      }
    else
      {
        atmega.motor("AB", 1, "digital");
      }
  }
