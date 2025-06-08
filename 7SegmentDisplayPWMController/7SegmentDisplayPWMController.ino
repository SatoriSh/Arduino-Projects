
int counter = 0;

int lastStatus = LOW;
int currentStatus = LOW;

float brightness = 0;

void setup() {
 
 for (int i = 2; i <= 8; i ++){
  pinMode(i, OUTPUT);
 }

  pinMode(9, INPUT);
  pinMode(10, OUTPUT);
}

void showNumber(int number){

  const byte numbers[10][7] = {
    {1,1,1,1,1,1,0}, // 0
    {0,1,1,0,0,0,0}, // 1
    {1,1,0,1,1,0,1}, // 2
    {1,1,1,1,0,0,1}, // 3
    {0,1,1,0,0,1,1}, // 4
    {1,0,1,1,0,1,1}, // 5
    {1,0,1,1,1,1,1}, // 6
    {1,1,1,0,0,0,0}, // 7
    {1,1,1,1,1,1,1}, // 8
    {1,1,1,1,0,1,1}  // 9
  };

  digitalWrite(2, numbers[number][0]);
  digitalWrite(3, numbers[number][1]);
  digitalWrite(4, numbers[number][2]);
  digitalWrite(5, numbers[number][3]);
  digitalWrite(6, numbers[number][4]);
  digitalWrite(7, numbers[number][5]);
  digitalWrite(8, numbers[number][6]);
}

void loop() {

  analogWrite(10,brightness);
  showNumber(counter);

  if (digitalRead(9) == 1){
    currentStatus = HIGH;
  }else{
    currentStatus = LOW;
  }

  if (currentStatus == HIGH && lastStatus == LOW){
    delay(35);
    if (digitalRead(9) == 1){
      counter++;
      brightness += 25.5;
    }
  }

  if (counter == 10){
     counter = 0;
     brightness = 0;
  }
  lastStatus = currentStatus;
}
