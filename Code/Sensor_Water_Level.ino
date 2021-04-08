#define sensorPin A0
#define sensorPower 10

int water_val = 0;
int redLED = 11;
int minlvl = 470;
int maxlvl = 525;


void setup() {
  pinMode(sensorPower, OUTPUT);
  digitalWrite(sensorPower, LOW);
  Serial.begin(9600);
  
  pinMode(redLED, OUTPUT);
  digitalWrite(redLED, LOW);

}

void loop() {
  int water_lvl = readSensor();
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

int readSensor() {
  digitalWrite(sensorPower, HIGH);  
  delay(10);              
  water_val = analogRead(sensorPin);  
  digitalWrite(sensorPower, LOW); 
  return water_val;         
}
