#include "Attiny84_IO_basic.h"
Attiny attiny;
void setup() {}
void loop() 
{
  if (attiny.Button()==1)
    {
      while (true)
        {
          attiny.motor("AB", 1, "digital");
          delay (1000);
          attiny.motor("AB", 0, "digital");
          attiny.motor("A", 1, "digital");
          delay (1000);
        }      
    }  
  else
    {
      attiny.motor("AB", 0, "digital");
    }
}
