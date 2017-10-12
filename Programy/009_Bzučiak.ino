#include <Attiny84_IO_basic.h>
Attiny attiny;
void setup() {
}

void loop() {
  attiny.Buzzer(1);
  delay(1000);
  attiny.Buzzer(0);
  delay(1000);
}
