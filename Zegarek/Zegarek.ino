#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define ONE_WIRE_BUS 8 // Data wire is plugged into port 2 on the Arduino

OneWire oneWire(ONE_WIRE_BUS); // Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
DallasTemperature sensors(&oneWire); // Pass our oneWire reference to Dallas Temperature. 

LiquidCrystal_I2C lcd(0x20,16,2); // set the LCD address to 0x20 for a 16 chars and 2 line display

int h = 13;
int m = 58;

void setup()
{
  sensors.begin(); // Start up the library
   
  lcd.init(); // initialize the lcd 
  lcd.backlight();
}

void loop()
{
  for (h; h<24; h++){
    lcd.clear();
    for(m; m<60; m++){
      lcd.clear();
      for(int s=0; s<60; s++){
        lcd.setCursor(0, 0);
        lcd.print(h);
        lcd.print(":");
        lcd.print(m);
        lcd.print(":");
        lcd.print(s);
        
        sensors.requestTemperatures(); // Send the command to get temperatures
        lcd.setCursor(12, 1);
        int tempC = sensors.getTempCByIndex(0);
        lcd.print(tempC);
        lcd.print((char) 223); // znak stopnia w ASCII
        lcd.print("C");
        delay(1000);      
      }
    }
    m=0;
  }
  h=0;
}

