/*


*/
#include "Arduino.h"
#include "Attiny85_IO_basic.h"

Attiny::Attiny(){}

void Attiny::motor(String motor,int speed,String mode)
  {
     if(mode=="analog")
     {
        pinMode(1,OUTPUT);//a
        pinMode(0,OUTPUT);//b
        int speed_set = map(speed,0,100,0,255);
        if(motor=="A")
        {
          analogWrite(1,speed_set);
        }
        else if(motor=="B")
        {
          analogWrite(0,speed_set);
        }
        else if(motor=="AB")
        {
          analogWrite(1,speed_set);
          analogWrite(0,speed_set);
        }
        else
        {
          analogWrite(1,0);
          analogWrite(0,0);
        }
     }
     else if(mode=="digital")
     {
        pinMode(1,OUTPUT);//a
        pinMode(0,OUTPUT);//b
        int speed_set;
        if (speed == 1)
        {
          speed_set = HIGH;
        }
        else if (speed == 0)
        {
          speed_set = LOW;
        }
        
        if(motor=="A")
        {
          digitalWrite(1,speed_set);
        }
        else if(motor=="B")
        {
          digitalWrite(0,speed_set);
        }
        else if(motor=="AB")
        {
          digitalWrite(1,speed_set);
          digitalWrite(0,speed_set);
        }
        else
        {
          digitalWrite(1,LOW);
          digitalWrite(0,LOW);
        }
     }
     
    
  }
int Attiny::LightSensor(int sensor,String mode)
  {
    if (mode=="analog")
    {
      pinMode(A2,INPUT_PULLUP);//1
      pinMode(A3,INPUT_PULLUP);//2
      if (sensor == 1)
      {
        int value;
        value = map(analogRead(A2),0,255,0,100);
        return value;
      }
      else if (sensor == 2)
      {
        int value;
        value = map(analogRead(A3),0,255,0,100);
        return value;
      }
    }
    else if(mode=="digital")
    {
      pinMode(3,INPUT_PULLUP);//1
      pinMode(4,INPUT_PULLUP);//2
      if (sensor == 1)
      {
        int value;
        value = digitalRead(A2);
        return value;
      }
      else if (sensor == 2)
      {
        int value;
        value = digitalRead(3);
        return value;
      }
      else
      {
        int value;
        value = digitalRead(4);
        return value;
      }
    }
  }

