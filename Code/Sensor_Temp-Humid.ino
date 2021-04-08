#include <dht.h>
#include <LiquidCrystal.h>
//LiquidCrystal lcd(8, 9, 2, 3, 4, 5);
const int rs = 8, en = 9, d2 = 2, d3 = 3, d4 = 4, d5 = 5;
LiquidCrystal lcd(rs, en, d2, d3, d4, d5);
#define dht_apin 12  

dht DHT;
 
void setup(){
  pinMode(dht_apin, INPUT);
  Serial.begin(9600);
  
  lcd.begin(8, 2);
  lcd.clear();
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
    Serial.println(" C  ");
    
    delay(5000);//Wait 5 seconds before accessing sensor again.
 
  //Fastest should be once every two seconds.
 
}
