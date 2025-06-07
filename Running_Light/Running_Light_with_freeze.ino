int speed = 50;

void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
}

void loop() {

  for (int i = 2; i <= 7; i++){
    delay(speed);
    digitalWrite(i,HIGH);
  }

  for (int i = 2; i <= 7; i++){
    delay(speed);
    digitalWrite(i,LOW);
  }
}