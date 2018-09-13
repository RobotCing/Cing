/*
Program for line following using Cing Robot library
*/
//Including basic library for Cing robot with Attiny85 procesor
#include <Attiny85_IO_basic.h>
//Constructor
Cing Cing;
void setup() {}
void loop() 
  {
    //Read value from sensor 2
    if (Cing.ReadLightSensor(2,"digital")==1) 
      {
        //Turn of motor A
        Cing.RunMotor("A", 0, "digital");
        //Turn on motor B
        Cing.RunMotor("B", 1, "digital");
      }
    else 
      {
        //Turn of motor B
        Cing.RunMotor("B", 0, "digital");
        //Turn on motor A
        Cing.RunMotor("A", 1, "digital");
      }
}

