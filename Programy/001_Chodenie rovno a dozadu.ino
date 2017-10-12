#include "Attiny84_IO_basic.h"
Attiny attiny;
void setup() { }
void loop() 
{
  attiny.motor("AB", 1, "digital");
  delay(1000);
  attiny.motor("AB", -1, "digital");
  delay(1000);
}
