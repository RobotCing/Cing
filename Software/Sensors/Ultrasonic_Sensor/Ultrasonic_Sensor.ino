/*
Attiny84 8mhz only
*/
#include <TinyWire.h>                        
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <NewPing.h>


uint8_t address;
uint8_t triggerdistance;
uint8_t humidity;
uint8_t temperature;
uint8_t distance;

float duration;
float soundcm;
float soundsp;
DHT dht(10, DHT11);
NewPing sonar(3, 2);
void setup(){
  pinMode(0,INPUT_PULLUP);
  pinMode(8,INPUT_PULLUP);
  pinMode(9,INPUT_PULLUP);
  pinMode(7,OUTPUT);
  
  address = get_address();
  TinyWire.begin(address);
  TinyWire.onRequest(requestEvent);
  
}
void loop()
  {
    triggerdistance = map(analogRead(A1),0,1023,10,50);
    humidity = dht.readHumidity();
    temperature = dht.readTemperature();
    if (isnan(humidity) || isnan(temperature)) {
      soundsp = 331.4 + (0.606 * temperature) + (0.0124 * humidity);
    }
    else{
      soundsp = 331.4;
    }
    soundcm = soundsp / 10000;
    duration = sonar.ping_median(3);
    distance = (duration / 2) * soundcm;
    if (distance >= 100 || distance == 0){
      distance = 200;
    }
    if(distance < triggerdistance){
      digitalWrite(7,HIGH);
    }
    else{
      digitalWrite(7,LOW);
    }
    delay(30);
  }
void requestEvent()
{
  TinyWire.send(distance);
  TinyWire.send(temperature);
  TinyWire.send(humidity);
  TinyWire.send(triggerdistance);
}
uint8_t get_address(){
  uint8_t address = 16 + !digitalRead(0)*1+!digitalRead(8)*2+!digitalRead(9)*4;
  return address;
}
