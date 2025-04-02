int button1Status = 0;
int button2Status = 0;
int button3Status = 0;

void setup() {
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
}

void loop() {

  button1Status = digitalRead(10);
  button2Status = digitalRead(11);
  button3Status = digitalRead(12);

  if (button1Status == 1){
    digitalWrite(7, HIGH);
  }
  else{
    digitalWrite(7, LOW);
  }

  if (button2Status == 1){
    digitalWrite(8, HIGH);
  }
  else{
    digitalWrite(8, LOW);
  }

  if (button3Status == 1){
    digitalWrite(9, HIGH);
  }
  else{
    digitalWrite(9, LOW);
  }
}