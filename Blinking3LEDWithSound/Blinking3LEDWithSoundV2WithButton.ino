int buttonStatus = 0;

void setup() {
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, INPUT);
}

void loop() {
  buttonStatus = digitalRead(11);

  if (buttonStatus == 1){
    blinking();
  }
  else {
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
  }
}

void blinking(){
    tone(10, 200);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    delay(500);
    noTone(10);

    tone(10, 400);
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    delay(500);
    noTone(10);

    tone(10, 600);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    delay(500);
    noTone(10);
}
