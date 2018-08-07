/*
Program for line following using Arduino code
*/
void setup() 
  {
    //Setting pins
    pinMode(0,OUTPUT);
    pinMode(1,OUTPUT);
    pinMode(3,INPUT);
  }
void loop() 
  {
    //Read value from sensor 2
    if (digitalRead(3)==1) 
      {
        //Turn of motor A
        digitalWrite(1,LOW);
        //Turn on motor B
        digitalWrite(0,HIGH);
      }
    else 
      {
        //Turn of motor B
        digitalWrite(0,LOW);
        //Turn on motor A
        digitalWrite(1,HIGH);
      }
  }
