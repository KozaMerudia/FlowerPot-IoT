#define photoPin A1
#define lamp 7

int photo_value=0;
int val = 0;

void setup() {
  pinMode(photoPin , INPUT);
  pinMode(lamp , OUTPUT);
  Serial.begin(9600);
}
void loop() {
  photo_value = analogRead(photoPin);
  //val = map(photo_value, 0, 1023, 0, 255);
  //analogWrite(lamp, val);
  delay(100);
  Serial.print("Svetlina: ");
  Serial.print(photo_value);
  Serial.print("\n");
  int photo = photo_value;
  if (photo<300){
    digitalWrite(lamp,HIGH);
    delay(700);}
  else{
    digitalWrite(lamp,LOW);
    delay(700);}
}

/*const int sensorPin = A1;
const int ledPin = 7;

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
    digitalWrite(7, HIGH);

  //else, it is bright, turn pin 7 LOW
  else
    digitalWrite(7, LOW);
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
  lightVal = analogRead(sensorPin);
  val = map(lightVal , 0, 1023, 0, 255);
  analogWrite(ledPin , val);
  delay(100);
  Serial.print("Svetlina: ");
  Serial.println(val);
  delay(500);
  
  if (val<80)
    {digitalWrite(ledPin, HIGH);}

  //else, it is bright, turn pin 7 LOW
  else
    {digitalWrite(ledPin, LOW);}
}*/
