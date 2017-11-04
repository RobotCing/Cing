#include <Attiny85_IO_basic.h>
Attiny attiny;
void setup() {}
void loop() 
  {
    attiny.motor("AB",1, "digital");
    delay (1000);
    attiny.motor("AB", 0, "digital");
    attiny.motor("B", 1, "digital");
    delay (800);
    attiny.motor("B", 0, "digital");
}
