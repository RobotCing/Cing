#include "Attiny85_IO.h"
Attiny attiny;
void setup() {
 
}

void loop() 
  {
    if (attiny.UltrasonicSensor()<20)
    {
      for (int x=0;x<4;x++)
        {
          attiny.motor("A", 1, "digital");
          delay (500);
          attiny.motor("A", 0, "digital");
          attiny.motor("B", 1, "digital");
          delay (500);
          attiny.motor("AB", 1, "digital");
          delay (500);
        }
    }
    else
    {
      attiny.motor("AB", 1, "digital");
    }
  }
