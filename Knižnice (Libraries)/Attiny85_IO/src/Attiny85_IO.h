/*
Vytvorene Teamom GalejeNextGen pre sutaz RBA
*/
#ifndef Attiny85_IO
#define Attiny85_IO
#include "Arduino.h"
//--------------------------------------------
//              Creating Class
//--------------------------------------------
class Attiny
{
// public variables
  public:
//constructor
    Attiny();
    void motor(String motor,int speed= 100,String mode = "digital");
    int LightSensor(int sensor = 1,String mode = "digital");
    float Temp(int senzor = 0);
    int UltrasonicSensor();
	int ShineSensor();
    int PotentiometerExternal();
// local variables
  private:
};
#endif
