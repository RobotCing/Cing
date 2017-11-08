#include <Atmega8_IO.h>
Atmega atmega;
void setup(){}
void loop() 
  {
    if(atmega.Button()==1)
      {
        atmega.Buzzer(1);
        delay(500);
        atmega.Buzzer(0);
        delay(500);
      }
  }

