/*
Created by RobotCing Team
*/
#ifndef Attiny85_IO
#define Attiny85_IO
#include "Arduino.h"
//--------------------------------------------
//              Creating Class
//--------------------------------------------
class Cing
{
// public variables
  public:
//constructor
    Cing();
    void RunMotor(String motor,int speed= 100,String mode = "digital");
    int ReadLightSensor(int sensor = 1,String mode = "digital");
    float ReadTempSensor(int senzor = 0);
    int ReadUltrasonicSensor();
    int ReadShineSensor();
    int ReadPotentiometerExternal();
// local variables
  private:
};
#endif
