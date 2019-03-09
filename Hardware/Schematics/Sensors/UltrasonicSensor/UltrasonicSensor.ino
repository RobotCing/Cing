/*
Attiny85 8mhz only
*/

#include <TinyWire.h>                        
#include <NewPing.h>


#define TRIGGER_PIN  4
#define ECHO_PIN     3
#define MAX_DISTANCE 255
#define ultrasonic_address  0x11

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

uint8_t response;
void setup(){
  pinMode(1,OUTPUT);
  TinyWire.begin(ultrasonic_address);
  TinyWire.onRequest(requestEvent);
}
void loop(){
    response = sonar.ping_cm();
    if(response > MAX_DISTANCE || response < 2){
      response = MAX_DISTANCE-1;  
    }
    if(response < 20){
      digitalWrite(1,HIGH);  
    }
    else{
      digitalWrite(1,LOW);
    }
}
void requestEvent()
{
  TinyWire.send(response);
}
