/*
Vytvorene Teamom GalejeNextGen pre sutaz RBA
*/
#ifndef Attiny84_IO
#define Attiny84_IO
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
    float Temp(int sensor = 0);
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
