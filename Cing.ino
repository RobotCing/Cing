#include "Attiny85_IO_basic.h"
Attiny attiny;
void setup() {


}

void loop() 
{
if (attiny.UltrasonicSensor()<20){attiny.motor("AB", 0,"digital");}
else{attiny.motor("AB", 1,"digital");}
//if (attiny.LightSensor(2,"digital")==0){attiny.motor("B", 1,"digital");}
//else{attiny.motor("B", 0,"digital");}
}



