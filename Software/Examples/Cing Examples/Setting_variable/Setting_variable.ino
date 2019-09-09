//Library import
#include <Attiny85_IO_basic.h>
//Constructor
Cing Cing;
//variables
int x;
void setup() {}
void loop(){
  x = Cing.ReadPotentiometerExternal();
  if(x>50){
    Cing.RunMotor("AB",1,"digital");
  }
  else{
    Cing.RunMotor("AB",0,"digital");
  }
}