//Library import
#include <Attiny84_IO_basic.h>
//Constructor
Cing Cing;
void setup(){

}
void loop(){
  Cing.RunMotor("AB", 1, "digital");
  delay(1000);
  Cing.RunMotor("AB", -1, "digital");
  delay(1000);
}