/*
Created by RobotCing Team
*/


//--------------------------------------------
//            Library import
//--------------------------------------------
#include "Arduino.h"
#include "Atmega8_IO_basic.h"
//--------------------------------------------
Cing::Cing(){}
//--------------------------------------------
//              Motors
//--------------------------------------------
void Cing::RunMotor(String motor,int speed,String mode)
  {
     #define motorA 12
     #define motorB 11
     #define INA1 10
     #define INA2 9
     #define INB1 8
     #define INB2 7
     pinMode(motorA,OUTPUT);
     pinMode(motorB,OUTPUT);
     //---------------------
     pinMode(INA1,OUTPUT);
     pinMode(INA2,OUTPUT);
     pinMode(INB1,OUTPUT);
     pinMode(INB2,OUTPUT);
     if(mode=="digital")
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
    #define LightSensor1 A2
    #define LightSensor2 A3
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
    #define UltrasonicSensor 13
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
//             ShineSensors
//--------------------------------------------
int Cing::ReadShineSensor()
  {
    #define ShineSensor 13
    int shine_value;
    pinMode(ShineSensor,INPUT);
    shine_value = map(digitalRead(ShineSensor),0,1,0,100);
    return shine_value;
  }
//--------------------------------------------
//               Button
//--------------------------------------------
int Cing::ReadButton(int button)
  {
    if (button == 0)
    {
      #define Button A6
      pinMode(Button,INPUT);
      int button_value = analogRead(Button);
      return button_value;
    }
  }
  //--------------------------------------------
  //          Potentiometer
  //--------------------------------------------
int Cing::ReadPotentiometerExternal()
    {
      #define Potentiometer 13
      pinMode(Potentiometer,INPUT);
      int Potentiometer_value = map(digitalRead(Potentiometer),0,1,0,100);
      return Potentiometer_value;
    }
