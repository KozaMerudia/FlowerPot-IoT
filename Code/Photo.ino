#define photoPin A1
#define lamp 7

int photo_value=0;
void setup() {
  pinMode(photoPin , INPUT);
  pinMode(lamp , OUTPUT);
  Serial.begin(9600);
}
void loop() {
  photo_value = analogRead(photoPin);
  Serial.print("Svetlina: ");
  Serial.print(photo_value);
  Serial.print("\n");
  delay(700);
  int photo = photo_value;
  if (photo<300){
    digitalWrite(lamp,HIGH);}
  else{
    digitalWrite(lamp,LOW);}
 
}
/*
void loop() {
  int  photo_value = analogRead(photoPin);
   delay(500);
if ( photo_value<300){
  digitalWrite(lamp,LOW);

  Serial.print("Svetlina: ");
  Serial.print(photo_value );
  Serial.print('\n');
   delay(1000);
}
else if ( photo_value>300){
  digitalWrite(lamp,HIGH);
  Serial.print("Svetlina: ");
  Serial.print(photo_value);
  Serial.print('\n');
  delay(1000);
}
}*/
/*
#define sensorPin A1
#define lamp 7

void setup() {
  Serial.begin(9600);
  pinMode(lamp, OUTPUT);
  digitalWrite(lamp, LOW);
}

void loop() {
  int photo_value = analogRead(A1);
  Serial.println("Analog value : ");
  Serial.println(photo_value);
  digitalWrite(lamp, HIGH);
  delay(700);
}*/

/*#define photoPin A7
const int lamp = 6;
int photo_value;

void setup() {
  Serial.begin(9600);
  pinMode(lamp , OUTPUT);
  pinMode(photoPin, INPUT);
  
}

void loop() {
  photo_value = analogRead(photoPin);
  if (photo_value<300){
    digitalWrite(lamp,HIGH);
    Serial.print("Svetlina: ");
    Serial.print(photo_value );
    Serial.print('\n');
    delay(1000);
  }
  else if ( photo_value>300){
    digitalWrite(lamp,LOW);
    Serial.print("Svetlina: ");
    Serial.print(photo_value);
    Serial.print('\n');
    delay(1000);
  }

    delay(500);
}*/

/*const int sensorPin = A6;
const int ledPin = 6;

int lightCal;
int lightVal;

void setup()
{
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  lightCal = analogRead(sensorPin);
}


void loop()
{
  int val = map(lightVal , 0, 1023, 0, 255);
  analogWrite(ledPin , val);
  lightVal = analogRead(sensorPin);

  //The (-50) part of the statement sets the sensitivity. 
  if (lightVal < lightCal - 10)
    digitalWrite(6, HIGH);

  //else, it is bright, turn pin 9 LOW
  else
    digitalWrite(6, LOW);
    Serial.print("Svetlina: ");
    Serial.print(lightVal );
    Serial.print('\n');
     delay(1000);
}
*/
/*
#define sensorPin A1
#define ledPin 7

int lightVal=0;
int val=0;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(ledPin, LOW);
  delay(100);
  digitalWrite(ledPin, HIGH);
  delay(100);
  
  lightVal = analogRead(sensorPin);
  val = map(lightVal , 0, 1023, 0, 255);
  //analogWrite(ledPin , val);

  Serial.print("Svetlina: ");
  Serial.println(val);
  delay(500);
  
  if (val<128)
    digitalWrite(ledPin, HIGH);

  //else, it is bright, turn pin 7 LOW
  else
    digitalWrite(ledPin, LOW);

}*/
