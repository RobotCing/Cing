//Library import
#include <Attiny85_IO.h>
//Constructor
Cing Cing;
void setup() {}
void loop(){
  if (Cing.ReadTempSensor()>30){
    Cing.RunMotor("AB", 1, "digital");
  }
  else{
    Cing.RunMotor("AB", 0, "digital");
  }
}
