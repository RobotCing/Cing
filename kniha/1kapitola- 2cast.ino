#include "Attiny85_IO_basic.h"
Attiny attiny;
void setup() {


}
void loop() 
  {
    for (int x=0;x<100;x++)
      {
        attiny.motor("AB",x,"analog");
        delay(10);
      }
    delay (1000);
    
    for (int x=100;x>0;x--)
      {
        attiny.motor("AB",x,"analog");
        delay(10);
      }
}



