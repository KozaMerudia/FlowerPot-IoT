#include <dht.h>
#include <LiquidCrystal.h>

//LiquidCrystal(RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define dht_apin 10               //Temperature-Humidity Sensor
#define water_pin A5              //Water Level Sensor
#define soil_pin A0               //Soil Moisture Sensor
#define relay_pin 6               //Water Pump Controller

dht DHT;

int water_redLED = 9;             //led on pin 9 indicate water level
int water_val = 0;                //water level in analog value
int water_level = 0;              //water level value in percents
int water_minlvl = 10;
int water_maxlvl = 90;
int i = 0;

float soil_value=0;
int soil_dryness=0;
int soil_moisture=0;

boolean pump = true;
unsigned long time_pump = - 86400000;    // 24 hours 
unsigned long time_lcd = 0;
unsigned long time_redLED = 0;
unsigned long time_soil = 0;

void wait(int interval, unsigned long time_millis){
  while(millis() < time_millis + interval){
  }
}

void setup(){  
  pinMode(dht_apin, INPUT);
  pinMode(water_pin, INPUT);
  Serial.begin(9600);
  
  pinMode(water_redLED, OUTPUT);
  digitalWrite(water_redLED, LOW);

  pinMode(relay_pin, OUTPUT);
  digitalWrite(relay_pin, HIGH);
  
  lcd.begin(8, 2);
  lcd.setCursor(0,0); 
  time_lcd = millis();
  wait(500,time_lcd);
  //Delay to let system boot
  
}//end "setup()"
 
void loop(){
  lcd.clear(); 
  time_lcd = millis();
  wait(100,time_lcd);
  lcd.setCursor(0,0);
  
//Start of Water Level Sensor
  water_val = analogRead(water_pin);
  water_level = map(water_val,470,735,0,100);
  if (water_level <= 0) {
      Serial.println("Water Level: Empty");
      lcd.print("WL Empty");
      digitalWrite(water_redLED, HIGH);
      pump = false;
  }
  else if (water_level > 0 && water_level <= water_minlvl) {
      Serial.println("Water Level: ");
      Serial.println(water_level);
      Serial.print(water_val);
      lcd.print("WL ");
      lcd.print(water_level);
      lcd.print(" %");
      time_redLED = millis();
      blinking_led(5,250,time_redLED);
      pump = true;
  }
  else if (water_level > water_minlvl && water_level <= water_maxlvl) {
      lcd.print("WL ");
      lcd.print(water_level);
      lcd.print(" %");
      Serial.println("Water Level: ");
      Serial.println(water_level);
      Serial.println(water_val);
      digitalWrite(water_redLED, LOW);
      pump = true;
  }
  else if (water_level > water_maxlvl) {
      lcd.print("WL ");
      lcd.print(water_level);
      lcd.print(" %");
      Serial.println("Water Level: ");
      Serial.println(water_level);
      Serial.println(water_val);
      time_redLED = millis();
      blinking_led(10,50,time_redLED);
      pump = true;
  }
                               //End of Water Level Sensor
  lcd.setCursor(0,1);
  time_lcd = millis();
  wait(100,time_lcd);

//Start of Soil Moisture Sensor
  soil_value = analogRead(soil_pin);
  soil_dryness = map(soil_value, 0, 1023, 0, 100);
  soil_moisture = 100 - soil_dryness;
  lcd.print("SM ");
  lcd.print(soil_moisture);
  lcd.print(" %");
  Serial.print("Moisture: ");
  Serial.print(soil_moisture);
  Serial.print("% \n");
  time_soil = millis();
  wait(3000,time_soil);        //End of Soil Moisture Sensor

//Start of Water Pump
  if(pump == true){
    if(millis() > time_pump + 86400000){   //Checks if the flower need water once every day
      time_pump = millis();
      if (soil_moisture < 35){
        digitalWrite(relay_pin, LOW);
        time_pump = millis();
        wait(3000,time_pump); 
        digitalWrite(relay_pin, HIGH);
      }
    }
  }                            //End of Water Pump
 
  lcd.setCursor(0,0); 
  lcd.clear();
  lcd.setCursor(0,1); 
  lcd.clear();
  time_lcd = millis();
  wait(100,time_lcd);

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
  time_lcd = millis();
  wait(3000,time_lcd);
  //Wait 3 seconds before accessing sensor again.
  //Fastest should be once every two seconds.
                               //End of Temperature-Humidity Sensor
}

void blinking_led(int repeat, int wait, unsigned long time_millis){
  for(i = 0; i <= repeat; i += 1){
    if(millis() > time_millis + wait){  
      digitalWrite(water_redLED, HIGH);
      time_millis = millis();
    }
    if(millis() > time_millis + wait){
      digitalWrite(water_redLED, LOW);
      time_millis = millis();
    }
  }
}
