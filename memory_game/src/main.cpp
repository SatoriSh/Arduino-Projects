#include <Arduino.h>

const int LEDSCOUNT = 4;
const int timeToNextLvl = 850;
const int buzzer = 8;

const int leds[] = { 2,3,4,5 };
const int buttons[] = { A0,A1,A2,A3 };
const int buzzerSound[] = { 1400,1450,1500,1650 };
const int buzzerLossSound = 100;
const int buzzerWinSound = 3250;

int duration = 0;

int randomSequence[10];
int playerChoice[10];

void SetSequence();
void ShowSequence();
void PlayerInputHandle();
void CheckPlayerAnswer();
void Win();
void GameOver();
bool ArraysTheSame();

void aaa();
void aaa()
{
  while (true)
  {
    for (int i = 0; i < LEDSCOUNT; i++)
    {
      if (digitalRead(buttons[i]) == LOW)
      {
        digitalWrite(leds[i], HIGH);
      }
      else
      {
        digitalWrite(leds[i], LOW);
      }
    }
  }
}

void setup()
{
  for (int i = 0; i < LEDSCOUNT; i++)
  {
    pinMode(leds[i], OUTPUT);
    pinMode(buttons[i], INPUT_PULLUP);
  }

  randomSeed(analogRead(A4));
}

void loop()
{
  //aaa();

  SetSequence();

  ShowSequence();

  PlayerInputHandle();

  CheckPlayerAnswer();

  delay(timeToNextLvl);
}

void SetSequence()
{
  randomSequence[duration] = random(0, LEDSCOUNT);
  duration++;
}

void ShowSequence()
{
  for (int i = 0; i < duration; i++)
  {
    digitalWrite(leds[randomSequence[i]], HIGH);
    tone(buzzer, buzzerSound[randomSequence[i]]);

    delay(750);

    digitalWrite(leds[randomSequence[i]], LOW);
    noTone(buzzer);

    delay(650);
  }
}

void PlayerInputHandle()
{
  int countOfChoice = 0;

  while (countOfChoice < duration)
  {
    for (int i = 0; i < LEDSCOUNT; i++)
    {
      if (digitalRead(buttons[i]) == LOW)
      {
        playerChoice[countOfChoice] = i;
        countOfChoice++;

        digitalWrite(leds[i], HIGH);
        tone(buzzer, buzzerSound[i]);
        delay(750);

        digitalWrite(leds[i], LOW);
        noTone(buzzer);
        delay(200);
      }
    }
  }
}

void CheckPlayerAnswer()
{
  if (ArraysTheSame())
  {
    Win();
  }
  else
  {
    GameOver();
  }
}

void Win()
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < LEDSCOUNT; j++)
    {
      digitalWrite(leds[j], HIGH);
    }
    tone(buzzer, buzzerWinSound);
    delay(150);

    for (int j = 0; j < LEDSCOUNT; j++)
    {
      digitalWrite(leds[j], LOW);
    }
    noTone(buzzer);
    delay(150);
  }
}

void GameOver()
{
  for (int i = 0; i < 4; i++)
  {
    digitalWrite(leds[0], HIGH);
    tone(buzzer, buzzerLossSound);
    delay(200);

    digitalWrite(leds[0], LOW);
    noTone(buzzer);
    delay(200);
  }

  duration = 0;
}

bool ArraysTheSame()
{
  for (int i = 0; i < duration; i++)
  {
    if (playerChoice[i] != randomSequence[i])
    {
      return false;
    }
  }

  return true;
}
