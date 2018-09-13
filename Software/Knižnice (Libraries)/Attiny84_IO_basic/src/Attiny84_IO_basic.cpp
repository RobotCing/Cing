/*
Created by RobotCing Team
*/


//--------------------------------------------
//            Library import
//--------------------------------------------
#include "Arduino.h"
#include "Attiny84_IO_basic.h"
//--------------------------------------------
Cing::Cing(){}
//--------------------------------------------
//              Motors
//--------------------------------------------
void Cing::RunMotor(String motor,int speed,String mode)
  {
     #define motorA A5
     #define motorB A6
     #define INA1 7
     #define INA2 8
     #define INB1 9
     #define INB2 10
     pinMode(motorA,OUTPUT);
     pinMode(motorB,OUTPUT);
     //---------------------
     pinMode(INA1,OUTPUT);
     pinMode(INA2,OUTPUT);
     pinMode(INB1,OUTPUT);
     pinMode(INB2,OUTPUT);
     if(mode=="analog")
     {
        int speed_set = map(speed,0,100,0,255);
        if(motor=="A")
        {
          if (speed = 0)
          {
            digitalWrite(INA1,HIGH);
            digitalWrite(INA2,LOW);
            analogWrite(motorA,speed_set);
          }
          else if (speed < 0)
          {
            digitalWrite(INA1,LOW);
            digitalWrite(INA2,HIGH);
            analogWrite(motorA,speed_set);
          }
        }
        else if(motor=="B")
        {
          if (speed = 0)
          {
            digitalWrite(INB1,HIGH);
            digitalWrite(INB2,LOW);
            analogWrite(motorB,speed_set);
          }
          else if (speed < 0)
          {
            digitalWrite(INB1,LOW);
            digitalWrite(INB2,HIGH);
            analogWrite(motorB,speed_set);
          }
        }
        else if(motor=="AB")
        {
          if (speed = 0)
          {
            digitalWrite(INA1,HIGH);
            digitalWrite(INA2,LOW);
            digitalWrite(INB1,HIGH);
            digitalWrite(INB2,LOW);
            analogWrite(motorA,speed_set);
            analogWrite(motorB,speed_set);
          }
          else if (speed < 0)
          {
            digitalWrite(INA1,LOW);
            digitalWrite(INA2,HIGH);
            digitalWrite(INB1,LOW);
            digitalWrite(INB2,HIGH);
            analogWrite(motorA,speed_set);
            analogWrite(motorB,speed_set);
          }
        }
        else
        {
          analogWrite(motorA,0);
          analogWrite(motorB,0);
        }
     }
     else if(mode=="digital")
     {
        int speed_set;
        if (speed == 1 || speed == -1)
        {
          speed_set = HIGH;
        }
        else if (speed == 0)
        {
          speed_set = LOW;
        }
        //--------------------------
        //           A
        //--------------------------
        if(motor=="A")
        {
          if (speed == 1)
          {
            digitalWrite(INA1,HIGH);
            digitalWrite(INA2,LOW);
            digitalWrite(motorA,speed);
          }
          else if (speed == -1)
          {
            digitalWrite(INA1,LOW);
            digitalWrite(INA2,HIGH);
            digitalWrite(motorA,speed);
          }
          else if (speed == 0)
          {
            digitalWrite(INA1,LOW);
            digitalWrite(INA2,LOW);
            digitalWrite(motorA,speed);
          }
        }
        //--------------------------
        //            B
        //--------------------------
        else if(motor=="B")
        {
          if (speed == 1)
          {
            digitalWrite(INB1,HIGH);
            digitalWrite(INB2,LOW);
            digitalWrite(motorB,speed);
          }
          else if (speed == -1)
          {
            digitalWrite(INB1,LOW);
            digitalWrite(INB2,HIGH);
            digitalWrite(motorB,speed);
          }
          else if (speed == 0)
          {
            digitalWrite(INB1,LOW);
            digitalWrite(INB2,LOW);
            digitalWrite(motorB,speed);
          }
        }
        //--------------------------
        //            AB
        //--------------------------
        else if(motor=="AB")
        {
          if (speed == 1)
          {
            digitalWrite(INA1,HIGH);
            digitalWrite(INA2,LOW);
            digitalWrite(INB1,HIGH);
            digitalWrite(INB2,LOW);
            digitalWrite(motorA,speed);
            digitalWrite(motorB,speed);
          }
          else if (speed == -1)
          {
            digitalWrite(INA1,LOW);
            digitalWrite(INA2,HIGH);
            digitalWrite(INB1,LOW);
            digitalWrite(INB2,HIGH);
            digitalWrite(motorA,speed);
            digitalWrite(motorB,speed);
          }
          else if (speed == 0)
          {
            digitalWrite(INA1,LOW);
            digitalWrite(INA2,LOW);
            digitalWrite(INB1,LOW);
            digitalWrite(INB2,LOW);
            digitalWrite(motorA,speed);
            digitalWrite(motorB,speed);
          }
        }
        else
        {
          digitalWrite(motorA,LOW);
          digitalWrite(motorB,LOW);
        }
     }
  }
//--------------------------------------------
//                  Sensors
//--------------------------------------------

//--------------------------------------------
//                  LightSensor
//--------------------------------------------

int Cing::ReadLightSensor(int sensor,String mode)
  {
    #define LightSensor1 A1
    #define LightSensor2 A0
    pinMode(LightSensor1,INPUT);//1
    pinMode(LightSensor2,INPUT);//2
    if (mode=="analog")
    {
      if (sensor == 1)
      {
        int value;
        value = map(analogRead(LightSensor1),0,255,0,100);
        return value;
      }
      else if (sensor == 2)
      {
        int value;
        value = map(analogRead(LightSensor2),0,255,0,100);
        return value;
      }
    }
    else if(mode=="digital")
    {
      if (sensor == 1)
      {
        int value;
        value = digitalRead(LightSensor1);
        return value;
      }
      else if (sensor == 2)
      {
        int value;
        value = digitalRead(LightSensor2);
        return value;
      }
      else
      {
        int value;
        value = digitalRead(LightSensor1);
        return value;
      }
    }
  }
//--------------------------------------------
//           UltrasonicSensor
//--------------------------------------------

int Cing::ReadUltrasonicSensor()
  {
    #define UltrasonicSensor 4
    int duration;
    int distance;
    pinMode(UltrasonicSensor, OUTPUT);
    digitalWrite(UltrasonicSensor, LOW);
    delayMicroseconds(2);
    digitalWrite(UltrasonicSensor, HIGH);
    delayMicroseconds(10);
    digitalWrite(UltrasonicSensor, LOW);
    delayMicroseconds(10);
    pinMode(UltrasonicSensor, INPUT);
    duration = pulseIn(UltrasonicSensor, HIGH);
    distance = duration/58.2;
    return distance;
  }

//--------------------------------------------
//          Potentiometer
//--------------------------------------------
int Cing::ReadPotentiometerExternal()
  {
    #define Potentiometer A4
    pinMode(Potentiometer,INPUT);
    int Potentiometer_value = map(analogRead(Potentiometer),0,1023,0,100);
    return Potentiometer_value;
  }
  //--------------------------------------------
  //             ShineSensor
  //--------------------------------------------
int Cing::ReadShineSensor()
  {
    #define ShineSensor A4
    int shine_value;
    pinMode(ShineSensor,INPUT);
    shine_value = map(analogRead(ShineSensor),50,700,0,100);
    return shine_value;
  }
