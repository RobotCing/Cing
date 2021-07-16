//Library import
#include <Attiny85_IO_basic.h>
//Constructor
Cing Cing;
void setup() {}
void loop(){
  if (Cing.ReadLightSensor(2,"analog")>50){
    Cing.RunMotor("A", 0, "digital");
    Cing.RunMotor("B", 1, "digital");
  }
  else{
    Cing.RunMotor("B", 0, "digital");
    Cing.RunMotor("A", 1, "digital");
  }
}
