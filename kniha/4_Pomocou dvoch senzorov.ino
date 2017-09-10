#include "Attiny85_IO_basic.h"
Attiny attiny;
void setup() {


}
void loop() 
  {
    if (attiny.LightSensor(1,"digital")==0) 
      {
        attiny.motor("A", 0, "digital");
      }
    else if (attiny.LightSensor(2,"digital")==0)
      {
        attiny.motor("B", 0, "digital");
      }
    else
      {
        attiny.motor("AB", 1, "digital");
      }
}



