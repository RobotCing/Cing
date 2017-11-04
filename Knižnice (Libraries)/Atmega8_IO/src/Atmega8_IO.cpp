
/*
Vytvorene Teamom GalejeNextGen
*/


//--------------------------------------------
//            Library import
//--------------------------------------------
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Adafruit_NeoPixel.h>
//--------------------------------------------
#include "Arduino.h"
#include "Atmega8_IO.h"
//--------------------------------------------
Atmega::Atmega(){}
//--------------------------------------------
//            Neopixel setup
//--------------------------------------------
#define PIN 13
#define Neopixels 120
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(Neopixels, PIN, NEO_GRB + NEO_KHZ800);
//--------------------------------------------
//            DS18B20 Setup
//--------------------------------------------
#define ONE_WIRE_BUS 13
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
//--------------------------------------------
//              Motors
//--------------------------------------------
void Atmega::motor(String motor,int speed,String mode)
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

int Atmega::LightSensor(int sensor,String mode)
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

int Atmega::UltrasonicSensor()
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
int Atmega::ShineSensor()
	{
		#define ShineSensor 13
		int shine_value;
		pinMode(ShineSensor,INPUT);
		shine_value = map(digitalRead(ShineSensor),0,1,0,100);
		return shine_value;
	}
//--------------------------------------------
//               Buzzer
//--------------------------------------------
void Atmega::Buzzer(int state,int Buzzer_time)
  {
    #define Buzzer 3
    pinMode(Buzzer, OUTPUT);
    if (state == 2)
		{
			digitalWrite(Buzzer, HIGH);
			delay(Buzzer_time);
			digitalWrite(Buzzer, LOW);
			delay(Buzzer_time);
		}
    else if (state == 1)
		{
			digitalWrite(Buzzer, HIGH);
		}
    else if (state == 0)
		{
			digitalWrite(Buzzer, LOW);
		}
  }
//--------------------------------------------
//               Button
//--------------------------------------------
int Atmega::Button(int button)
  {
    if (button == 0)
    {
		#define Button A4
		pinMode(Button,INPUT);
		int button_value = digitalRead(Button);
		return button_value;
	}
  }
  //--------------------------------------------
  //          Potentiometer
  //--------------------------------------------
int Atmega::PotentiometerInternal()
	{
		#define Potentiometer A4
		pinMode(Potentiometer,INPUT);
		int Potentiometer_value = map(analogRead(Potentiometer),0,1023,0,100);
		return Potentiometer_value;
	}
int Atmega::PotentiometerExternal()
    {
		#define Potentiometer 13
		pinMode(Potentiometer,INPUT);
		int Potentiometer_value = map(digitalRead(Potentiometer),0,1,0,100);
		return Potentiometer_value;
    }
//--------------------------------------------
//            TempSensors
//--------------------------------------------
float Atmega::Temp(int sensor)
	{
		float temp;
		sensors.requestTemperatures();
		temp = sensors.getTempCByIndex(sensor);
		delay(50);
		return temp;
	}
//--------------------------------------------
//            LED WS2812
//--------------------------------------------
void Atmega::LedStart(int numberofleds)
	{
		pixels.begin();
	}
void Atmega::LedColor(int led,int red,int green,int blue)
	{
		pixels.setPixelColor(led-1,pixels.Color(map(green,0,100,0,255),map(red,0,100,0,255),map(blue,0,100,0,255)));
	}
void Atmega::LedShow()
	{
		pixels.show();
	}
  