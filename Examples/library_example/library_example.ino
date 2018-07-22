/*
Program for line following using Cing Robot library
*/
//Including basic library for Cing robot with Attiny85 procesor
#include <Attiny85_IO_basic.h>
//Constructor
Attiny attiny;
void setup() {}
void loop() 
  {
    //Read value from sensor 2
    if (attiny.LightSensor(2,"digital")==1) 
      {
        //Turn of motor A
        attiny.Runmotor("A", 0, "digital");
        //Turn on motor B
        attiny.Runmotor("B", 1, "digital");
      }
    else 
      {
        //Turn of motor B
        attiny.Runmotor("B", 0, "digital");
        //Turn on motor A
        attiny.Runmotor("A", 1, "digital");
      }
}

