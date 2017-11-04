#include <Attiny85_IO_basic.h>
Attiny attiny;
void setup() {}
void loop() 
  {
    if (attiny.UltrasonicSensor()<20) 
    {
      attiny.motor("AB", 0, "digital");
    }
    else 
    {
      if (attiny.LightSensor(1, "digital")==0)
      {
        attiny.motor("B",1, "digital");
      }
      else 
      {
        attiny.motor("A", 1, "digital");
      }
      }
    }
