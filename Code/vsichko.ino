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
int minlvl = 10;
int maxlvl = 90;

int pump = 0;
int lvl=0;

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
  lcd.clear(); 
  delay(100);
  

  
//Start of Water Level Sensor

  water_val = analogRead(water_pin);
  lvl = water_val;
  water_lvl = map(water_val,470,735,0,100);
  int level=0;
  level = water_lvl;
  
  lcd.setCursor(0,0);
  if (level <= 0) {
    Serial.println("Water Level: Empty");
      lcd.print("WL Empty");
      digitalWrite(redLED, HIGH);
      pump=pump+1;
  }
  else if (level > 0 && level <= minlvl) {
    Serial.println("Water Level: ");
    Serial.println(water_lvl);
    Serial.print(lvl);
    lcd.print("WL ");
    lcd.print(water_lvl);
    lcd.print(" %");
     digitalWrite(redLED, HIGH);
      delay(700);
      digitalWrite(redLED, LOW);
      delay(700);
      digitalWrite(redLED, HIGH);
      delay(700);
      digitalWrite(redLED, LOW);
      delay(700);
      digitalWrite(redLED, HIGH);
      delay(700);
  }
  else if (level > minlvl && level <= maxlvl) {
    lcd.print("WL ");
    lcd.print(water_lvl);
    lcd.print(" %");
    Serial.println("Water Level: ");
    Serial.println(water_lvl);
    Serial.println(lvl);
    digitalWrite(redLED, LOW);
  }
  else if (level > maxlvl) {
    lcd.print("WL ");
    lcd.print(water_lvl);
    lcd.print(" %");
    Serial.println("Water Level: ");
    Serial.println(water_lvl);
    Serial.println(lvl);
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
  }
                             //End of Water Level Sensor

//Start of Soil Moisture Sensor
  lcd.setCursor(0,1);
  delay(100);
  float soil_value=0;
  int dryness=0;
  int moisture=0;
  soil_value = analogRead(soil_pin);
  dryness = map(soil_value, 0, 1023, 0, 100);
  moisture = 100 - dryness;
  lcd.print("SM ");
  lcd.print(moisture);
  lcd.print(" %");
  Serial.print("Moisture: ");
  Serial.print(moisture);
  Serial.print("% \n");
  delay(3000);                   //End of Soil Moisture Sensor

//Start of Water Pump
if(pump==0){
  if (moisture < 35){
  digitalWrite(relay_pin, LOW);
  delay(10000);
  digitalWrite(relay_pin, HIGH);
  pump=pump+1;
  }
}                              
else{pump=pump+1;}
  if (pump>=5){
  pump=0;}                      //End of Water Pump
 
  lcd.setCursor(0,0); 
  lcd.clear();
  lcd.setCursor(0,1); 
  lcd.clear();
  delay(100);

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
      
    delay(3000);//Wait 3 seconds before accessing sensor again.
  //Fastest should be once every two seconds.
                          //End of Temperature-Humidity Sensor
}
