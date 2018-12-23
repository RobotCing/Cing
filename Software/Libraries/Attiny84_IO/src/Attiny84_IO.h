/*
Created by RobotCing Team
*/
#ifndef Attiny84_IO
#define Attiny84_IO
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
    float ReadTempSensor(int sensor = 0);
    int ReadUltrasonicSensor();
    int ReadShineSensor();
    bool ReadButtonExternal()
    int ReadPotentiometerExternal();
// local variables
  private:
};
#endif
