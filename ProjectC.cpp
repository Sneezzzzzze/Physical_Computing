int count = 0;
int num1 = 0; int num2 = 0;
int x[10][8] = {
  {1, 1, 1, 1, 1, 1, 0, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1, 0}, // 2
  {1, 1, 1, 1, 0, 0, 1, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1, 0}, // 4
  {1, 0, 1, 1, 0, 1, 1, 0}, // 5
  {1, 0, 1, 1, 1, 1, 1, 0}, // 6
  {1, 1, 1, 0, 0, 1, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1, 0}, // 8
  {1, 1, 1, 1, 0, 1, 1, 0}  // 9
};
int segPin[8] = {13, 12, 11, 10, 9, 8, 7};
int segPinx[8] = {6, 5, 4, 14, 15, 16, 17};
int switchs = 18;
void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);   //Trig
  pinMode(2, INPUT);    // Echo
  pinMode(switchs, INPUT);

  for(int i=0;i<10;i++){
    pinMode(segPin[i], OUTPUT);
    pinMode(segPinx[i], OUTPUT);
  }
}

void loop() {
  digitalWrite(3, HIGH);
  delayMicroseconds(10);
  digitalWrite(3, LOW);

  int pulseWidth = pulseIn(2, HIGH);
  long distance = pulseWidth/29/2;
  Serial.println(distance);

  if ((distance >= 30) && distance <= 39) {
    count++;
  }
  if (digitalRead(switchs) == HIGH) {
    count = 0;
    for (int i = 0; i < 8; i++) {
      digitalWrite(segPin[i], x[0][i]);
    }
  }
  if (count <= 9) {
    for (int i = 0; i < 8; i++) {
      digitalWrite(segPin[i], x[0][i]);
    }
    for (int i = 0; i < 8; i++) {
      digitalWrite(segPinx[i], x[count][i]);
    }
  } 
  if (count >= 10) {
    int ten = ceil((count % 100) / 10);
    for (int i = 0; i < 8; i++) {
      digitalWrite(segPin[i], x[ten][i]);
    }
    int digit = count % 10;
    for (int i = 0; i < 8; i++) {
      digitalWrite(segPinx[i], x[digit][i]);
    }
  }
  delay(1000);

  

}
