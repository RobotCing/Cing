/*
Created by RobotCing Team
*/
#ifndef Attiny85_IO_basic
#define Attiny85_IO_basic
#include "Arduino.h"
//--------------------------------------------
//              Creating Class
//--------------------------------------------
class Cing
{
  public:
    //constructor
    Cing();
    void RunMotor(String motor,int speed= 100,String mode = "digital");
    int ReadLightSensor(int sensor = 1,String mode = "digital");
    int ReadUltrasonicSensor();
    int ReadShineSensor();
    int ReadPotentiometerExternal();
  private:

};
#endif
