#include "Attiny85_IO.h"
Attiny attiny;
void setup() {


}
void ()
  {
    pinMode(, OUTPUT);
    pinMode(echoPin, INPUT);
  }
void loop() 
{
  if (attiny.Temp(0)>30){attiny.motor ("A", 1, "digital");}
  else {attiny.motor("A", 0, "digital");}
}
