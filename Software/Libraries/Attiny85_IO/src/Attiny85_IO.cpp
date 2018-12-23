/*
Created by RobotCing Team
*/


//--------------------------------------------
//            Library import
//--------------------------------------------
#include <OneWire.h>
#include <DallasTemperature.h>
//--------------------------------------------
#include "Arduino.h"
#include "Attiny85_IO.h"
//--------------------------------------------
Cing::Cing(){}
//--------------------------------------------
//            DS18B20 Setup
//--------------------------------------------
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
//--------------------------------------------
//              Motors
//--------------------------------------------
void Cing::RunMotor(String motor,int speed,String mode)
  {
     #define motorA 1
     #define motorB 0
     pinMode(motorA,OUTPUT);//a
     pinMode(motorB,OUTPUT);//b
     if(mode=="analog")
     {
        int speed_set = map(speed,0,100,0,255);
        if(motor=="A")
        {
          analogWrite(motorA,speed_set);
        }
        else if(motor=="B")
        {
          analogWrite(motorB,speed_set);
        }
        else if(motor=="AB")
        {
          analogWrite(motorA,speed_set);
          analogWrite(motorB,speed_set);
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
          digitalWrite(motorA,speed_set);
        }
        else if(motor=="B")
        {
          digitalWrite(motorB,speed_set);
        }
        else if(motor=="AB")
        {
          digitalWrite(motorA,speed_set);
          digitalWrite(motorB,speed_set);
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
        value = map(analogRead(LightSensor1),0,1023,100,0);
        return value;
      }
      else if (sensor == 2)
      {
        int value;
        value = map(analogRead(LightSensor2),0,1023,100,0);
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
    #define UltrasonicSensor 2
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
    #define ShineSensor A1
    int shine_value;
    pinMode(ShineSensor,INPUT);
    shine_value = map(analogRead(ShineSensor),50,700,0,100);
    return shine_value;
  }
//--------------------------------------------
//          Potentiometer
//--------------------------------------------
int Cing::ReadPotentiometerExternal()
  {
    #define Potentiometer A1
    pinMode(Potentiometer,INPUT);
    int Potentiometer_value = map(analogRead(Potentiometer),0,1023,0,100);
    return Potentiometer_value;
  }
//--------------------------------------------
//            TempSensors
//--------------------------------------------
float Cing::ReadTempSensor(int senzor)
  {
    float temp;
    sensors.requestTemperatures();
    temp = sensors.getTempCByIndex(senzor);
    delay(50);
    return temp;
  }
