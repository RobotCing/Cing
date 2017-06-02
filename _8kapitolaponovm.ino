#include "Attiny85_IO_basic.h"
Attiny attiny;
#dafine ciara 0
void setup() {


}
void sledovanie_ciary()
  {
    if (attiny.LightSensor(2, "digital")==ciara) 
      {
        attiny.motor("B", 1, "digital");
      }
    else 
      {
        attiny.motor("A", 1, "digital");
      }
  }
void loop() 
{
 
if (attiny.ShineSensor()<20)
   {
    attiny.motor("AB", 0, "digital");
   }
else 
   {
      sledovanie_ciary()
   }
}
