#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define ONE_WIRE_BUS 8 // Data wire is plugged into port 2 on the Arduino

OneWire oneWire(ONE_WIRE_BUS); // Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
DallasTemperature sensors(&oneWire); // Pass our oneWire reference to Dallas Temperature. 

LiquidCrystal_I2C lcd(0x20,16,2); // set the LCD address to 0x20 for a 16 chars and 2 line display

int h = 15;
int m = 54;
int s = 0;

int year = 2017;
int month = 9;
int day = 28;

void setup()
{
  sensors.begin(); // Start up the library
   
  lcd.init(); // initialize the lcd 
  lcd.backlight();
}

void loop()
{
  for(year; ;year++){
    lcd.clear();
    for(month; month<=12; month++){
      lcd.clear();
      for(day; day<=ilosc_dni(month, year); day++){
        lcd.clear(); 
        for (h; h<24; h++){
          lcd.clear();
          for(m; m<60; m++){
            lcd.clear();
            for(s; s<60; s++){
              lcd.setCursor(0, 1);
              lcd.print(day);
              lcd.print("/");
              lcd.print(month);
              lcd.print("/");
              lcd.print(year);
              
              lcd.setCursor(0, 0);
              lcd.print(h);
              lcd.print(":");
              lcd.print(m);
              lcd.print(":");
              lcd.print(s);
        
              sensors.requestTemperatures(); // Send the command to get temperatures
              lcd.setCursor(10, 1);
              float tempC = sensors.getTempCByIndex(0);
              lcd.print(tempC, 1);
              lcd.print((char) 223); // znak stopnia w ASCII
              lcd.print("C");
              delay(1000);      
              }
              s=0;
          }
          m=0;
        }
        h=0;
      }
      day=1;
    }
    month=1;
  }
}


int ilosc_dni(int miesiac, int rok)
{
  if(miesiac == 1 || 3 || 5 || 7 || 8 || 10 || 12)
  {
    return 31; 
  }
  if(miesiac == 4 || 6 || 9 || 11)
  {
    return 30;
  }
  if(miesiac == 2)
  {
    if(rok%4 == 0)
    {
      return 29;
    }
    else
    {
      return 28;
    }
  }
}



