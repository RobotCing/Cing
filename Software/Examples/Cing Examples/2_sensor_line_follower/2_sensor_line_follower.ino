//Library import
#include <Attiny85_IO_basic.h>
//Constructor
Cing Cing;
void setup() {}
void loop(){
  if (Cing.ReadLightSensor(1,"analog")<50){
    Cing.RunMotor("A", 0, "digital");
  }
  else if (Cing.ReadLightSensor(2,"analog")<50){
    Cing.RunMotor("B", 0, "digital");
  }
  else{
    Cing.RunMotor("AB", 1, "digital");
  }
}
