#include <Attiny85_IO_basic.h>
Attiny attiny;
int x;
void setup() {}
void loop() 
  {
    if (x <= 10)
      {
        attiny.motor("AB", 1,"digital");
        if (attiny.LightSensor(2, "digital")==1)
          { 
            x++;
            delay(200);
          }
      }
    else
      {
        attiny.motor("B", 0,"digital");
        attiny.motor("A", 1,"digital");
        delay (800);
        attiny.motor("AB", 0,"digital");         
      }
  }
