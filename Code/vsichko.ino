#include <dht.h>
#include <LiquidCrystal.h>

//LiquidCrystal(RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define dht_apin 10  
#define water_pin A5
#define soil_pin A0
#define relay_pin 6

dht DHT;

int water_val = 0;
int water_lvl = 0;
int redLED = 9;
int minlvl = 470;
int maxlvl = 700;

void setup(){  
  pinMode(dht_apin, INPUT);
  pinMode(water_pin, INPUT);
  Serial.begin(9600);
  
  pinMode(redLED, OUTPUT);
  digitalWrite(redLED, LOW);

  pinMode(relay_pin, OUTPUT);
  digitalWrite(relay_pin, HIGH);
  
  lcd.begin(8, 2);
  delay(500);
  lcd.setCursor(0,0); 
  delay(500);//Delay to let system boot
  
}//end "setup()"
 
void loop(){
//Start of Water Level Sensor
  water_val = analogRead(water_pin);
  water_lvl = water_val;
  int level = water_lvl;
  
  lcd.clear();
  lcd.setCursor(0,0); 
  
  if (level == 0) {
    Serial.println("Water Level: Empty");
      lcd.print("WL Empty");
      digitalWrite(redLED, HIGH);
  }
  else if (level > 0 && level <= minlvl) {
    Serial.println("Water Level: ");
    lcd.print("WL ");
    lcd.print(water_lvl);
    Serial.println(water_lvl);
     digitalWrite(redLED, HIGH);
      delay(700);
      digitalWrite(redLED, LOW);
      delay(700);
  }
  else if (level > minlvl && level <= maxlvl) {
    lcd.print("WL ");
    lcd.print(water_lvl);
    Serial.println("Water Level: ");
    Serial.println(water_lvl);
    digitalWrite(redLED, LOW);
  }
  else if (level > maxlvl) {
    lcd.print("WL ");
    lcd.print(water_lvl);
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
                             //End of Water Level Sensor

//Start of Soil Moisture Sensor
  lcd.setCursor(0,1);
  float moisture;
  int sensor_value;
  sensor_value = analogRead(soil_pin);
  moisture = ( 100 - ( (sensor_value/1023.00) * 100 ) );
  lcd.print("SM ");
  lcd.print(moisture);
  lcd.print("%");
  Serial.print("Moisture: ");
  Serial.print(moisture);
  Serial.print("% \n");
  delay(4000);               //End of Soil Moisture Sensor

//Start of Water Pump
  if (moisture < 35){
  digitalWrite(relay_pin, LOW);
  delay(5000);
  digitalWrite(relay_pin, HIGH);
    }                        //End of Water Pump
   
  lcd.clear();
  
//Start of Temperature-Humidity Sensor
    DHT.read11(dht_apin);

    Serial.print("Humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("Temperature = ");
    Serial.print(DHT.temperature);
    Serial.println("C  ");

    lcd.setCursor(0,0); 
    lcd.print("T ");
    lcd.print(DHT.temperature);
    lcd.print((char)223);
    lcd.print("C");
    lcd.setCursor(0,1);
    lcd.print("H ");
    lcd.print(DHT.humidity);
    lcd.print("%");
    delay(1000);
      
    delay(3000);//Wait 5 seconds before accessing sensor again.
  //Fastest should be once every two seconds.
                          //End of Temperature-Humidity Sensor
}
