/*
Created by RobotCing Team
*/


//--------------------------------------------
//            Library import
//--------------------------------------------
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Adafruit_NeoPixel.h>
#include <SoftwareSerial.h>
//--------------------------------------------
#include "Arduino.h"
#include "Atmega328_IO.h"
//--------------------------------------------
Cing::Cing(){}
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
								digitalWrite(motorA,speed_set);
							}
						else if (speed == -1)
							{
								digitalWrite(INA1,LOW);
								digitalWrite(INA2,HIGH);
								digitalWrite(motorA,speed_set);
							}
						else if (speed == 0)
							{
								digitalWrite(INA1,LOW);
								digitalWrite(INA2,LOW);
								digitalWrite(motorA,LOW);
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
								digitalWrite(motorB,speed_set);
							}
						  else if (speed == -1)
							{
								digitalWrite(INB1,LOW);
								digitalWrite(INB2,HIGH);
								digitalWrite(motorB,speed_set);
							}
						  else if (speed == 0)
							{
								digitalWrite(INB1,LOW);
								digitalWrite(INB2,LOW);
								digitalWrite(motorB,LOW);
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
								digitalWrite(motorA,speed_set);
								digitalWrite(motorB,speed_set);
							}
						else if (speed == -1)
							{
								digitalWrite(INA1,LOW);
								digitalWrite(INA2,HIGH);
								digitalWrite(INB1,LOW);
								digitalWrite(INB2,HIGH);
								digitalWrite(motorA,speed_set);
								digitalWrite(motorB,speed_set);
							}
						else if (speed == 0)
							{
								digitalWrite(INA1,LOW);
								digitalWrite(INA2,LOW);
								digitalWrite(INB1,LOW);
								digitalWrite(INB2,LOW);
								digitalWrite(motorA,LOW);
								digitalWrite(motorB,LOW);
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
int Cing::ReadShineSensor(int sensor)
	{
		#define ShineSensor 13
		#define LDR_1 A6
		#define LDR_2 A7
		pinMode(ShineSensor,INPUT);
		int shine_value;
		if(sensor == 0)
			{
				int shine_value = map(digitalRead(ShineSensor),0,1,0,100);
				return shine_value;
			}
		else if(sensor == 1)
			{
				int shine_value = map(analogRead(LDR_1),0,1023,100,0);
				return shine_value;
			}
		else if(sensor == 2)
			{
				shine_value = map(analogRead(LDR_2),0,1023,100,0);
				return shine_value;
			}
	}
//--------------------------------------------
//               Button
//--------------------------------------------
bool Cing::ReadButton()
	{
		#define Button A6
		pinMode(Button,INPUT);
		bool button_value = digitalRead(Button);
		return button_value;
	}
//--------------------------------------------
//          ButtonExternal
//--------------------------------------------
bool Cing::ReadButtonExternal()
  {
		#define button_external 13
		pinMode(button_external,INPUT);
		bool button_external_value = digitalRead(button_external);
		return button_external_value;
  }
//--------------------------------------------
//          Potentiometer
//--------------------------------------------
int Cing::ReadPotentiometer()
  {
		#define potentiometer A1
		int potentiometer_value = map(analogRead(potentiometer),0,1023,0,100);
		return potentiometer_value;
	}
//--------------------------------------------
//            TemperatureSensors
//--------------------------------------------
float Cing::ReadTempSensor(int sensor)
	{
		float Temp;
		sensors.requestTemperatures();
		Temp = sensors.getTempCByIndex(sensor);
		delay(50);
		return Temp;
	}
//--------------------------------------------
//            IR
//--------------------------------------------
int Cing::ReadIRSensor()
	{
		#define IR_pin 4
		int code;

	}

//--------------------------------------------
//            LED WS2812
//--------------------------------------------
void Cing::LedStart()
	{
		pixels.begin();
	}
void Cing::SetLedColor(int led,int red,int green,int blue)
	{
		if(led>0)
			{
				pixels.setPixelColor(led-1,pixels.Color(map(green,0,100,0,255),map(red,0,100,0,255),map(blue,0,100,0,255)));
			}
		else
			{
				pixels.setPixelColor(0,pixels.Color(map(green,0,100,0,255),map(red,0,100,0,255),map(blue,0,100,0,255)));
			}
	}
void Cing::LedShow()
	{
		pixels.show();
	}

//--------------------------------------------
//                  ColorSensor
//--------------------------------------------
/*
void StartColorSensor(){
	SoftwareSerial mySerial(A3, A2);
	int ACK = 0x04; // Acknowledge byte
	int NACK = 0x02; // Not acknowledge byte
	int SensorDisconnected = 0;
	int lastRefresh = millis();
	int SerialValue [] = {0,0,0,0};
	int refreshTime = 250;
	long lastupdate = millis();
	mySerial.begin(2400);
	//Sensor setup
	while (true){
  int value = mySerial.read();
  if(value==-1 && value==0 && value==255){
    mySerial.read();
  }
  if(value!=-1){
    SerialValue[1] = SerialValue[0];
    SerialValue[0] = value;
  }

  if(SerialValue[0]==128 && SerialValue[1]==144){
    while (true){
      if(mySerial.read()==4){
        break;
      }
    }
    mySerial.write(ACK);
    delay(60);
    mySerial.end();
    mySerial.begin(57600);
    break;
  }
  }
}

int ReadColorSensor(){
	if (millis() - lastRefresh > refreshTime){
      SensorMode(2);
      lastRefresh = millis();
    }
    SerialValue[2] = mySerial.read();
    if(SerialValue[2]==-1 && SerialValue[2]==255){
      SensorDisconnected ++;
      mySerial.read();
    }
    if(SerialValue[2]!=-1 && SerialValue[2] <= 7 && SerialValue[3]==0){
      SensorDisconnected = 0;
      SerialValue[3] = 1;
      Serial.print(SerialValue[2]);
      Serial.print("          ");
      Serial.print((millis()-lastupdate));
      Serial.println("ms");
      lastupdate = millis();
      for(int x=1;x<5;x++){
        //Blue
        if(SerialValue[2]==2){
          Cing.SetLedColor(x,0,0,255);
        }
        //Green
        else if(SerialValue[2]==3){
          Cing.SetLedColor(x,255,0,0);
        }
        //Red
        else if(SerialValue[2]==5){
          Cing.SetLedColor(x,0,255,0);
        }
        //White
        else if(SerialValue[2]==6){
          Cing.SetLedColor(x,255,255,255);
        }
        //None or unmatched
        else{
          Cing.SetLedColor(x,0,0,0);
        }
      }
      Cing.LedShow();
    }
    else{
      SerialValue[3] = 0;
    }
    if(SensorDisconnected > 10){
      Serial.println("Sensor Disconnected");
    }
}

void SensorMode(int newMode){
  if (newMode <= 5 && newMode >= 0){
    sendMessage(0x44, 0x11);
    for (int n;n<3;n++){
      sendMessage(0x43, newMode & 0x7);
      mySerial.write(NACK);
    }
  }
}
void sendMessage(int cmd,int data){
  int cSum = 0xff ^ cmd ^ data;
  mySerial.write(cmd);
  mySerial.write(data);
  mySerial.write(cSum);
}
*/
