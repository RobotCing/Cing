/*
Created by RobotCing Team
*/
#ifndef Atmega328_IO
#define Atmega328_IO
#include "Arduino.h"
//#include <DallasTempature.h>


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
    int ReadShineSensor();
    int ReadButton(int button = 0);
    int ReadProtentiometerExternal();
    float ReadTempSensor(int sensor = 0);
    void LedStart(int numberofleds = 6);
	void LedColor(int led = 1,int red = 100,int green = 100,int blue = 100);
	void LedShow();
// local variables
  private:
};
#endif
