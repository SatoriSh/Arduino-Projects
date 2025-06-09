void setup() {
  Serial.begin(9600);

  for (int i = 2; i <= 8; i++){
    pinMode(i, OUTPUT);
  }

  pinMode(A0, INPUT);
}

void showNum(int number){

  byte nums[10][7] = {
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

  digitalWrite(2, nums[number][0]);
  digitalWrite(3, nums[number][1]);
  digitalWrite(4, nums[number][2]);
  digitalWrite(5, nums[number][3]);
  digitalWrite(6, nums[number][4]);
  digitalWrite(7, nums[number][5]);
  digitalWrite(8, nums[number][6]);
}


void loop() {

  int value = map(analogRead(A0), 0, 1023, 0, 9);

  Serial.println(value);

  showNum(value);

  delay(50);
}
