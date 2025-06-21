#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define TOUCHPIN 8

LiquidCrystal_I2C lcd(0x27, 16, 2);

long currentMillis = 0;
long lastMillis = 0;

String text = "Scanning";
int time = 130;

void setup()
{
  Serial.begin(9600);

  pinMode(TOUCHPIN, INPUT);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
}

void loop()
{
  bool value = digitalRead(TOUCHPIN);

  if (!value)
  {
    currentMillis = 0;
    lastMillis = 0;
    time = 20;
    text = "Scanning";
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("Apply your");
    lcd.setCursor(1, 1);
    lcd.print("finger to scan");
  }
  else
  {
    currentMillis += millis() - (millis() - 30);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(text);

    if (text.indexOf("...") != -1)
    {
      currentMillis = 0;
      lastMillis = 0;
      time = 130;
      text = "Scanning";
    }
    if (currentMillis - lastMillis >= time)
    {
      lastMillis = currentMillis;
      text += ".";
      time += 40;
    }
    while (currentMillis >= 500)
    {
      lcd.clear();
      lcd.setCursor(5, 0);
      lcd.print("DONE!");
      lcd.setCursor(0, 1);
      lcd.print("YOU ARE 100\% GAY!");
      delay(3000);
      break;
    }
  }

  Serial.println(currentMillis);
  delay(300);
}
