#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // rs, e, d4, d5, d6, d7

void setup() {
  lcd.begin(16, 2);
  lcd.print("Tylko");
  lcd.setCursor(6, 1);
  lcd.print("Calgon");

}

void loop() {
  // put your main code here, to run repeatedly:

}
