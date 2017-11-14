#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20,16,2);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.print("Napiecie: ");
  lcd.setCursor(3, 1);
  lcd.print("Calgon Disco");
  pinMode(A1, OUTPUT);
  pinMode(A0, INPUT);
}

void loop() {
  lcd.setCursor(10, 0);
  float odczyt = analogRead(A0);
  analogWrite(A1, odczyt/4);
  lcd.print(odczyt/1024.00*5);
  lcd.print('V');
}
