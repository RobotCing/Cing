/*
Program for line following using Cing Robot library
*/
//Including basic library for Cing robot with Attiny85 procesor
#include <Attiny85_IO_basic.h>
//Constructor
Cing cing;
void setup() {}
void loop() 
  {
    //Read value from sensor 2
    if (cing.ReadLightSensor(2,"digital")==1) 
      {
        //Turn of motor A
        cing.RunMotor("A", 0, "digital");
        //Turn on motor B
        cing.RunMotor("B", 1, "digital");
      }
    else 
      {
        //Turn of motor B
        cing.RunMotor("B", 0, "digital");
        //Turn on motor A
        cing.RunMotor("A", 1, "digital");
      }
}

