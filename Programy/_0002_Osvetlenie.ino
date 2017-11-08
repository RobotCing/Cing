#include <Atmega8_IO.h>
Atmega atmega;
void setup() {}
void loop() 
  {
    if (atmega.ShineSensor()>1) 
      {
        atmega.motor("AB", 0, "digital");
      }
    else
      {
        atmega.motor("AB", 1, "digital");
        atmega.Buzzer(1);
      }
}
