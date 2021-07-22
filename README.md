# FlowerPot-IoT
The smart FlowerPot takes care of the health of the flowers
 
# Features
- Мeasure the soil moisture in real time

- Мeasure the ambient temperature in real time

- Мeasure the air humidity in real time

- Мeasure the intensity of light on the flowerpot in real time

- Мeasure the water level in the tank once a day

- Display sensors data on the screen

- Indicator light for tank level condition

- Watering the flowerpot when it's needed

- Turning on additional lighting when it's needed

# How to use it 
1. Put the soil moisture sensor in the soil of the pot.

2. Add water to the tank and the FlowerPot will take care of the rest

# How it works
```ruby
#include <dht.h>                  //Temperature-Humidity Sensor library
#include <LiquidCrystal.h>        //Liquid Crystal library

//Define Liquid Crystal Display
//LiquidCrystal(RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define dht_apin 10               //Temperature-Humidity Sensor Pin
#define water_pin A5              //Water Level Sensor Pin
#define soil_pin A0               //Soil Moisture Sensor Pin
#define relay_pin 6               //Water Pump Controller Pin
#define photoPin A1               //Light Intensity Sensor Pin

// Create an instance of the dht class called DHT
dht DHT;

int i = 0;                        //Counter variable
int water_redLED = 9;             //LED to indicate water level
int water_val = 0;                //Water Level in analog value
int water_level = 0;              //Water Level value in percents
int water_minlvl = 10;            //Water Level in the tank 10%
int water_maxlvl = 90;            //Water Level in the tank 90%

float soil_value=0;               //Soil Druness in analog value
int soil_dryness=0;               //Soil Druness value in percents
int soil_moisture=0;              //Soil Moisture value in percents

boolean pump = true;              //Indicates if there is water in the tank

int photo_val = 0;                //Light Intensity in analog value
int photo_percents=0;             //Light Intensity value in percents
int lamp = 7;                     //LED for additional lighting

//Variables for time counting
unsigned long time_pump = - 86400000;    // 24 hours 
unsigned long time_lcd = 0;
unsigned long time_redLED = 0;
unsigned long time_soil = 0;
unsigned long time_light = 0;

//Function for time counting
void wait(int interval, unsigned long time_millis){
  while(millis() < time_millis + interval){
  }
}

void setup(){  
  Serial.begin(9600);
  // Initialize sensors pins as INPUT 
  // Initialize LED pins as OUTPUT in state LOW
  pinMode(dht_apin, INPUT);
  
  pinMode(photoPin , INPUT);
  pinMode(lamp , OUTPUT);
  digitalWrite(lamp,LOW);
 
  pinMode(water_pin, INPUT);
  pinMode(water_redLED, OUTPUT);
  digitalWrite(water_redLED, LOW);

  // Initialize the relay module controling the pump as OUTPUT in state HIGH
  pinMode(relay_pin, OUTPUT);
  digitalWrite(relay_pin, HIGH);

  // Setting up the LCD
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
  // Read Water Leve Sensor data
  water_val = analogRead(water_pin);
  water_level = map(water_val,470,735,0,100);
  
  // When water tank is empty the redLED turn on 
  if (water_level <= 0) {
      Serial.println("Water Level: Empty");
      lcd.print("WL Empty");
      digitalWrite(water_redLED, HIGH);
      pump = false;
      }
  // When water level is below 10% full redLED start blinking slowly
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
  // When water level is between 10 and 90% full redLED turn off
  else if (water_level > water_minlvl && water_level <= water_maxlvl) {
      Serial.println("Water Level: ");
      Serial.println(water_level);
      Serial.println(water_val);
      lcd.print("WL ");
      lcd.print(water_level);
      lcd.print(" %");
      
      digitalWrite(water_redLED, LOW);
      pump = true;
      }
  // When water level is over 90% full redLED start blinking quickly
  else if (water_level > water_maxlvl) {
      Serial.println("Water Level: ");
      Serial.println(water_level);
      Serial.println(water_val);
      lcd.print("WL ");
      lcd.print(water_level);
      lcd.print(" %");

      time_redLED = millis();
      blinking_led(10,50,time_redLED);
      pump = true;
      }
                               //End of Water Level Sensor
  lcd.setCursor(0,1);
  time_lcd = millis();
  wait(100,time_lcd);

//Start of Soil Moisture Sensor
  // Read Soil Moisture Sensor data
  soil_value = analogRead(soil_pin);
  soil_dryness = map(soil_value, 0, 1023, 0, 100);
  soil_moisture = 100 - soil_dryness;
  
  Serial.print("Moisture: ");
  Serial.print(soil_moisture);
  Serial.print("% \n");

  lcd.print("SM ");
  lcd.print(soil_moisture);
  lcd.print(" %");
  
  time_soil = millis();
  wait(3000,time_soil);         //End of Soil Moisture Sensor

//Start of Water Pump
  // Checks if there is water in the tunk
  if(pump == true){
    // Checks if the flower need water once a day
    if(millis() > time_pump + 86400000){
      time_pump = millis();
      if (soil_moisture < 35){
        digitalWrite(relay_pin, LOW);
        time_pump = millis();
        wait(3000,time_pump); 
        digitalWrite(relay_pin, HIGH);
        }
      }
    }                            //End of Water Pump

  // Clear the LCD screen
  lcd.setCursor(0,0); 
  lcd.clear();
  lcd.setCursor(0,1); 
  lcd.clear();
  time_lcd = millis();
  wait(100,time_lcd);

//Start of Temperature-Humidity Sensor
  // Read Temperature-Humidity Sensor data
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

//Start of Light Intensity Sensor
  // Read Light Intensity Sensor data
  photo_val = analogRead(photoPin);
  photo_percents = filter(photo_val);
  
  // Turn on additional lighting when needed
  if (photo_percents < 50){
    digitalWrite(lamp,HIGH);
    //digitalWrite(lamp,LOW);
    time_light = millis();
    wait(500,time_light);
    }
  else{
    digitalWrite(lamp,LOW);
    //digitalWrite(lamp,HIGH);
    time_light = millis();
    wait(500,time_light);
    }
    
  Serial.print("Light Intensity ");
  Serial.print(photo_percents);
  Serial.println(" %");
  
  lcd.setCursor(0,0);
  lcd.print("Light Intensity :");
  lcd.setCursor(0,1);
  lcd.print(photo_percents);
  lcd.print("%");               //End of Light Intensity Sensor
}               
 
//Function for filtering bugs
int filter(int values){
    int percents;
    i = 0;
    if (i % 2 == 0){
      percents = map(values, 0, 255, 0, 100);
      return percents;
      }
    else  i += 1;
}

//Blinking LED function
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
```
