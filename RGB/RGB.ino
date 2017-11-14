#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20,16,2);

int dioda = 9;

void setup() {
  pinMode(9, OUTPUT); // CZERWONY
  pinMode(10, OUTPUT); // ZIELONY
  pinMode(11, OUTPUT); // NIEBIESKI

  pinMode(0,INPUT_PULLUP); // PRZYCISK
 
  lcd.init();
  lcd.backlight();
  lcd.print("Napiecie: ");
  pinMode(A1, OUTPUT);
  pinMode(A0, INPUT);
}

void loop() {
  lcd.setCursor(10, 0);
  float odczyt = analogRead(A0);
  analogWrite(kolor(), analogRead(A0)/4);
  lcd.print(odczyt/1024.00*5);
  lcd.print('V');
  lcd.setCursor(3, 1);
  lcd.print("Dioda nr.");
  lcd.print(dioda);
  lcd.print(" ");
}

int kolor()
{
  if(digitalRead(0) == HIGH)
  {
    return dioda;
  }
  if(digitalRead(0) == LOW)
  {
    delay(500);
    switch (dioda)
    {
     case 11:
       dioda = 9;
       return 9;
       delay(500);
       break;

     case 10:
      dioda = 11;
      return 11;
      delay(500);
      break;

      case 9:
       dioda = 10;
       return 10;
       delay(500);
       break;

     default:
       break;
    }
  }
}

