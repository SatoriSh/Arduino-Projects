#define BLU 9
#define GRN 10
#define RED 11

int speed = 2;

void setup() {
  pinMode(BLU, OUTPUT);
  pinMode(GRN, OUTPUT);
  pinMode(RED, OUTPUT);
}

void blinking(int pin){
  for (int i = 0; i <= 255; i++) { analogWrite(pin, i); delay(speed); } 
  for (int i = 255; i >= 0; i--) { analogWrite(pin, i); delay(speed); } 
}

void loop() {
  blinking(RED);
  blinking(GRN);
  blinking(BLU);
}

