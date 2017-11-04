#ifndef Attiny85_IO_basic
#define Attiny85_IO_basic
#include "Arduino.h"
//--------------------------------------------
//              Creating Class
//--------------------------------------------
class Attiny
{
  public:
    //constructor
    Attiny();
    void motor(String motor,int speed= 100,String mode = "digital");
    int LightSensor(int sensor = 1,String mode = "digital");
    int UltrasonicSensor();
    int ShineSensor();
    int PotentiometerExternal();
  private:

};
#endif
