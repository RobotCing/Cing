/*
Created by RobotCing Team
*/
#ifndef Atmega8_IO_basic
#define Atmega8_IO_basic
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
    int ReadUltrasonicSensor();
    int ReadShineSensor(int sensor = 0);
    bool ReadButton();
    bool ReadButtonExternal();
    int ReadPotentiometer();
// local variables
  private:
};
#endif
