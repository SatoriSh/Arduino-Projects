const int pins[] = {8, 9, 10, 11, 12, 13};

const int numPins = 6;

void setup() {

  Serial.begin(9600);

  pinMode(A0, INPUT);

  for (int i = 0; i < numPins; i++){
    pinMode(pins[i], OUTPUT);
  }
  
}

void loop() {

  int value = map(analogRead(A0), 0, 1023, 0, 6);

  for (int i = 0; i < numPins; i++){
    digitalWrite(pins[i], value >= i + 1 ? HIGH : LOW);
  }

  Serial.println(value);
}
