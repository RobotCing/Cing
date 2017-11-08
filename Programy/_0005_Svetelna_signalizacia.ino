#include <Atmega8_IO.h>
Atmega atmega;
void setup()
  {
    atmega.LedStart();
  }
void loop() 
  {
   for(int x;x<6;x++)
     {
        atmega.LedColor(x-1,0,0,0);
        atmega.LedColor(x,100,0,0);
        atmega.LedShow();
        delay(500);
     }
   for(int x = 6;x>0;x--)
     {
        atmega.LedColor(x+1,0,0,0);
        atmega.LedColor(x,100,0,0);
        atmega.LedShow();
        delay(500);
     }
}

