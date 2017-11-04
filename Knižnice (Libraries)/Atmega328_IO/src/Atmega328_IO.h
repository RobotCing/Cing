/*
Vytvorene Teamom GalejeNextGen pre sutaz RBA
*/
#ifndef Atmega328_IO
#define Atmega328_IO
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
    float Temp(int sensor = 0);
    void LedStart(int numberofleds = 6);
	void LedColor(int led = 1,int red = 100,int green = 100,int blue = 100);
	void LedShow();
// local variables
  private:
};
#endif
