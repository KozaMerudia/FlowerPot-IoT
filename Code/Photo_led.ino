#include <LiquidCrystal.h>

#define photoPin A1   
#define lamp 7

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int photo_val = 0;
int photo_percents=0;
int i = 0;

void setup() {
  pinMode(photoPin , INPUT);
  pinMode(lamp , OUTPUT);
  digitalWrite(lamp,LOW);
  Serial.begin(9600);

  lcd.begin(8, 2);
  lcd.setCursor(0,0); 
  
}
void loop() {
  photo_val = analogRead(photoPin);
  photo_percents = filter(photo_val);
  Serial.print("Light Intensity ");
  Serial.print(photo_percents);
  Serial.println(" %");
 delay (1000);
  
  if (photo_percents < 50){
    digitalWrite(lamp,HIGH);
    //digitalWrite(lamp,LOW);
    delay(700);
    }
  else{
    digitalWrite(lamp,LOW);
    //digitalWrite(lamp,HIGH);
    delay(700);
    }
 
  lcd.setCursor(0,0);
  lcd.print("Light Intensity :");
  lcd.setCursor(0,1);
  lcd.print(photo_percents);
  lcd.print("%");
 }
int filter(int values){
    int percents;
    i = 0;
    if (i%2 == 0){
      percents = map(values, 0, 255, 0, 100);
      return percents;
      }
    else  i += 1;
  }
