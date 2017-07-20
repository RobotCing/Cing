/*
Vytvorene Teamom GalejeNextGen pre sutaz RBA
*/
#ifndef Attiny84_IO_basic
#define Attiny84_IO_basic
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
    int UltrasonicSensor();
    int ShineSensor();
// local variables
  private:

};
#endif
