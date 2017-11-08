Atmega atmega;
void setup() {}
void loop() 
  {
    if (atmega.Temp()>30) 
      {
        atmega.motor("AB", 0, "digital");
        atmega.Buzzer(0);
      }
    else
      {
        atmega.motor("AB", 1, "digital");
        atmega.Buzzer(1);
      }
}

