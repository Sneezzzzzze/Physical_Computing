#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 columns and 2 rows
int squatCount = 0;
int prevDistance = 0; // Variable to store the previous distance
char input = '\0'; // Declare the input variable

bool isCounting = false;

void setup() 
{
  Serial.begin(9600);
  pinMode(7, INPUT);
  lcd.init();
  lcd.backlight();
  pinMode(3, OUTPUT); // Trig
  pinMode(2, INPUT);  // Echo
  lcd.setCursor(0, 0);
  lcd.print("Welcome to");
  lcd.setCursor(0, 1);
  lcd.print("MiniGYM Counter");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("--Press Start--");
}

void loop() 
{
  digitalWrite(3, HIGH);
  delayMicroseconds(10);
  digitalWrite(3, LOW);

  int pulseWidth = pulseIn(2, HIGH);
  long distance = pulseWidth / 29 / 2;
  /*Serial.print("Pulse Width: ");
  Serial.println(pulseWidth);
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(1000);*/

  if (digitalRead(7) == LOW) {
      isCounting = true;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Squat Count: ");
      lcd.print(squatCount);
    } if ((squatCount >= 1) && (digitalRead(7) == LOW)) {
      isCounting = false;
      squatCount = 0;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Welcome to");
      lcd.setCursor(0, 1);
      lcd.print("MiniGYM Counter");
      delay(2000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("--Press Start--");
    }
    
    if (isCounting) {
    if (distance >= 70 && distance <= 79 && prevDistance < 70) {
        squatCount++;
        lcd.setCursor(13, 0);
        lcd.print(squatCount);
    }
  }

  prevDistance = distance; // Update the previous distance

  delay(800);
}