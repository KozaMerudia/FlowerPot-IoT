#define sensorPin A5

int water_val = 0;
int water_lvl = 0;
int redLED = 9;
int minlvl = 470;
int maxlvl = 525;

void setup() {
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
  
  pinMode(redLED, OUTPUT);
  digitalWrite(redLED, LOW);
}

void loop() {
  water_val = analogRead(sensorPin);
  water_lvl = water_val;
  
  int level = water_lvl;
  if (level == 0) {
    Serial.println("Water Level: Empty");
      digitalWrite(redLED, HIGH);
  }
  else if (level > 0 && level <= minlvl) {
    Serial.println("Water Level: ");
    Serial.println(water_lvl);
      digitalWrite(redLED, HIGH);
      delay(700);
      digitalWrite(redLED, LOW);
      delay(700);

  }
  else if (level > minlvl && level <= maxlvl) {
    Serial.println("Water Level: ");
    Serial.println(water_lvl);
    digitalWrite(redLED, LOW);
  }
  else if (level > maxlvl) {
    Serial.println("Water Level: ");
    Serial.println(water_lvl);
    digitalWrite(redLED, HIGH);
    delay(50);
    digitalWrite(redLED, LOW);
    delay(50);
    digitalWrite(redLED, HIGH);
    delay(50);
    digitalWrite(redLED, LOW);
    delay(50);
    digitalWrite(redLED, HIGH);
    delay(50);
    digitalWrite(redLED, LOW);
    delay(50);
  }
  delay(500);
}
