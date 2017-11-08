#include <Atmega8_IO.h>
Atmega atmega;
int hodnota_ciary;
void setup(){}
void loop() 
  {
    hodnota_ciary = atmega.PotentiometerExternal();
    if (atmega.LightSensor(1,"digital")==hodnota_ciary) 
      {
        atmega.motor("A", 0, "digital");
      }
    else if (atmega.LightSensor(2,"digital")==hodnota_ciary)
      {
        atmega.motor("B", 0, "digital");
      }
    else
      {
        atmega.motor("AB", 1, "digital");
      }
  }


