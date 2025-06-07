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
    digitalWrite(i,HIGH);
    if(i != 2) delay(speed);
    digitalWrite(i,LOW);
  }

  for (int i = 7; i >= 2; i--){
    digitalWrite(i,HIGH);
    if(i != 7) delay(speed);
    digitalWrite(i,LOW);
  }
}
