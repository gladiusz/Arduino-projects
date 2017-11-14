#include <PCF8574.h>
#include <Wire.h>

PCF8574 expander;

void setup() {
expander.begin(0x20);
expander.pinMode(0, OUTPUT);
}

void loop() {
expander.digitalWrite(0, LOW);
}
