//Library import
#include <Attiny85_IO_basic.h>
//Constructor
Cing Cing;
void setup() {}
void loop(){
  //Read value from sensor 2
  if (Cing.ReadShineSensor()>50){
    Cing.RunMotor("AB", 1, "digital");
  }
  else{
    Cing.RunMotor("AB", 0, "digital");
  }
}
