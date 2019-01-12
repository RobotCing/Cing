//Library import
#include <Attiny85_IO_basic.h>
//Constructor
Cing Cing;
void setup(){

}
void loop(){
  Cing.RunMotor("AB", 1, "digital");
  delay(1000);
  Cing.RunMotor("AB", 0, "digital");
  Cing.RunMotor("B", 1, "digital");
  delay(800);
  Cing.RunMotor("B", 0, "digital");
}
