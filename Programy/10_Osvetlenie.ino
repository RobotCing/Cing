#include "Attiny85_IO_basic.h"
Attiny attiny;
void setup() {

}

void loop() 
{
  if (attiny.ShineSensor()>20)
    {
          attiny.motor("AB", 1, "digital");              
    }  
 
  else
    {
      attiny.motor("AB", 0, "digital");
    }
}
