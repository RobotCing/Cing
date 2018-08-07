#include <Atmega8_IO.h>
Atmega atmega;
void setup() {}
void loop() 
  {
    atmega.motor("AB",1, "digital");
    delay (1000);
    atmega.motor("AB", 0, "digital");
    atmega.motor("B", 1, "digital");
    delay (800);
    atmega.motor("B", 0, "digital");
}
