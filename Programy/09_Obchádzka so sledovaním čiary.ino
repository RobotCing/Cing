#include "Attiny85_IO_basic.h"
Attiny attiny;
void setup() {


}

void loop() 
{
  if (attiny.UltrasonicSensor()<20) 
    {
      attiny.motor("A", 1, "digital");
      delay (500);
      attiny.motor("A", 0, "digital");
      attiny.motor("B", 1, "digital");
      delay (500);
      attiny.motor("AB", 1, "digital");
      delay (500);
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



