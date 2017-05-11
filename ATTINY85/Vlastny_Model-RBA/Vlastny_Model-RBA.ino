#include "Attiny85_IO.h"
Attiny attiny;
void setup() {


}

void loop() 
{
  if (attiny.LightSensor(1,"digital")==1){attiny.motor ("A", 1, "digital");}
  else {attiny.motor("A", 0, "digital");}
}
