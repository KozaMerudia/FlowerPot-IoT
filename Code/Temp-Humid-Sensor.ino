#include <LiquidCrystal.h>


#define lcdrs 8
#define lcde 9
#define lcd2 2
#define lcd3 3
#define lcd4 4
#define lcd5 5  

//LiquidCrystal lcd(RS, E, D4, D5, D6, D7);
LiquidCrystal lcd(8, 9, 2, 3, 4, 5);      // put your pin numbers here

void setup()
  {
  lcd.begin(8, 2);    // put your LCD parameters here
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("hello,");
  lcd.setCursor(0,1);
  lcd.print("world!");
  }

void loop()
  {
  }


/*#include <dht.h>
#include <LiquidCrystal.h>

//LiquidCrystal lcd(8, 9, 2, 3, 4, 5);

const int rs = 8, en = 9, d2 = 2, d3 = 3, d4 = 4, d5 = 5;
LiquidCrystal lcd(rs, en, d2, d3, d4, d5);

#define dht_apin 12  
#define lcd1 2
#define lcd2 3
#define lcd3 4
#define lcd4 5

dht DHT;
 
void setup(){
  pinMode(dht_apin, INPUT);
  pinMode(lcd1, OUTPUT);
  pinMode(lcd2, OUTPUT);
  pinMode(lcd3, OUTPUT);
  pinMode(lcd4, OUTPUT);
  Serial.begin(9600);
  lcd.begin(8, 2);
  lcd.setCursor(0,0); 
  lcd.print("proba");
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
 
}//end "setup()"
 
void loop(){
  //Start of Program 

    DHT.read11(dht_apin);
    
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
    
    delay(5000);//Wait 5 seconds before accessing sensor again.
 
  //Fastest should be once every two seconds.
 
}

/*#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 2, 3, 4, 5);

void setup() {
  lcd.begin(8, 2);
  lcd.print("hello, world!");
}

void loop() {
}

/*#include <dht.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 2, 3, 4, 5);

dht DHT;

#define DHT11_PIN 12

void setup(){
  Serial.begin(9600);
  lcd.begin(8, 2);
  lcd.print("proba");
}

void loop(){
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("proba ");
  Serial.print(chk);
  Serial.print(DHT.temperature);
    Serial.print(DHT.humidity);
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);
  lcd.print("%");
  delay(1000);
} */

/*#include <LiquidCrystal.h>
#include <SimpleDHT.h>

int pinDHT11 = A7;
SimpleDHT11 dht11;

const int rs = 8, en = 9, d2 = 2, d3 = 3, d4 = 4, d5 = 5;
LiquidCrystal lcd(rs, en, d2, d3, d4, d5);

void setup() 
{
  Serial.begin(9600);
  lcd.begin(8, 2);
}

void loop() 
{
  Serial.println("=================================");
  Serial.println("DHT11 readings...");

  byte temperature = 0;

  Serial.print("Readings: ");
  Serial.print((int)temperature); 
  Serial.print(" Celcius, ");
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print((int)temperature); 
 
  delay(750);
} */


/*#include <dht.h>
int pinDHT11 = A7;
dht DHT;

void setup() 
{
  Serial.begin(9600);
 // DHT.begin();
}

void loop()
{
    int temp = read
    DHT.read(pinDHT11);
    Serial.print(DHT.temperature);
      delay(1000);
  }*/

/* #include <dht.h>


#define dht_apin A7 // Analog Pin sensor is connected to
 
dht DHT;
 
void setup(){
 
  Serial.begin(9600);
  pinMode(dht_apin, INPUT);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
 
}//end "setup()"
 
void loop(){
  //Start of Program 
 
    DHT.read11(dht_apin);

    
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
    
    delay(5000);//Wait 5 seconds before accessing sensor again.
 
  //Fastest should be once every two seconds.
 
}// end loop(*/
