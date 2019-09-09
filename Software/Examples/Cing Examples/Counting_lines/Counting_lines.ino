//Library import
#include <Attiny85_IO_basic.h>
//Constructor
Cing Cing;
//variables
int x;
void setup() {}
void loop(){
  if(x<=10){
    Cing.RunMotor("AB", 1, "digital");
    if(Cing.ReadLightSensor(2,"digital")==1){
      x++;
      delay(200);
    }
  }
  else{
    Cing.RunMotor("B", 0, "digital");
    Cing.RunMotor("A", 1, "digital");
    delay(800);
    Cing.RunMotor("AB", 0, "digital");
  }
}