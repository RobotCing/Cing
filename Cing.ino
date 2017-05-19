#include "Attiny85_IO_basic.h"
Attiny attiny;
void setup() {


}

void loop() 
{
  /*if(attiny.LightSensor(1,"digital")<1){attiny.motor("A", 0, "digital");}
  else{attiny.motor("A", 1, "digital");}
  if(attiny.LightSensor(2,"digital")<1){attiny.motor("B", 0, "digital");}
  else{attiny.motor("B", 1, "digital");}
  */
  if(attiny.LightSensor(2,"digital")==0) {attiny.motor("B", 0,"digital");attiny.motor("A", 1, "digital");}
  else{attiny.motor("A", 0, "digital");attiny.motor("B", 1,"digital");}
}
