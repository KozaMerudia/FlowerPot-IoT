#include <dht.h>
#include <LiquidCrystal.h>

//LiquidCrystal(RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define dht_apin 10  

dht DHT;
 
void setup(){
  pinMode(dht_apin, INPUT);
  Serial.begin(9600);
  
  lcd.begin(8, 2);
  delay(500);
  lcd.setCursor(0,0); 
  delay(500);//Delay to let system boot
  
}//end "setup()"
 
void loop(){
  //Start of Program 

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
      
    delay(5000);//Wait 5 seconds before accessing sensor again.
  //Fastest should be once every two seconds.
 
}
