#include "Attiny85_IO_basic.h"
Attiny attiny;
void setup() {

}

void loop() 
{
  if (attiny.PotentiometerExternal()>50)
    {
          attiny.motor("AB", 1, "digital");              
    }  
 
  else
    {
      attiny.motor("AB", 0, "digital");
    }
}
