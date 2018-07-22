/*
Program for line following using AVR programing language
*/
//Library import
#include <avr/io.h>
//Defining MCU frequency
#define F_CPU 8000000UL

void setup()
  {
    //Setting pins
    DDRB = 0b00000011;
  }

void loop()
  {
    //Read value from sensor 2
    if (PIND & (1<<3)==1) 
      {
        //Turn of motor A
        PORTB &= ~(1<<1);
        //Turn on motor B
        PORTB |= ~(1<<0);
      }
    else 
      {
        //Turn of motor B
        PORTB &= ~(1<<0);
        //Turn on motor A
        PORTB |= ~(1<<1);
      }
  }
