/*
Vytvorene Teamom GalejeNextGen pre sutaz RBA
*/
#ifndef Atmega8_IO_basic
#define Atmega8_IO_basic
#include "Arduino.h"
//--------------------------------------------
//              Creating Class
//--------------------------------------------
class Atmega
{
// public variables
  public:
//constructor
    Atmega();
    void motor(String motor,int speed= 100,String mode = "digital");
    int LightSensor(int sensor = 1,String mode = "digital");
    int UltrasonicSensor();
    int ShineSensor();
    void Buzzer(int state=2,int Buzzer_time = 1000);
    int Button(int button = 0);
    int PotentiometerInternal();
    int PotentiometerExternal();
// local variables
  private:
};
#endif
