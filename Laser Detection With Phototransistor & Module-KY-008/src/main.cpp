#include <Arduino.h>

#define laserPIN 8
#define buzzer 9
#define phototransistorPIN A0

int LRP_Value;

int brightness_limit = 200;

long currentMillis = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(laserPIN, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(phototransistorPIN, INPUT);
}

void alarm()
{
  currentMillis += 50;

  if (currentMillis <= 200)
  {
    tone(buzzer, 250);
  }
  else
  {
    noTone(buzzer);
    if (currentMillis >= 400) currentMillis = 0;
  }
}

void loop()
{
  digitalWrite(laserPIN, HIGH);

  LRP_Value = analogRead(phototransistorPIN);

  Serial.println(LRP_Value);

  if (LRP_Value >= 200) alarm();
  else
  {
    currentMillis = 0;
    noTone(buzzer);
  }

  delay(50);
}
