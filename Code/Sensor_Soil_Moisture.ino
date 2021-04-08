const int sensor_pin = A0;  

void setup() {
  Serial.begin(9600); 
}

void loop() {
  float moisture;
  int sensor_value;
  sensor_value = analogRead(sensor_pin);
  moisture = ( 100 - ( (sensor_value/1023.00) * 100 ) );
  Serial.print("Moisture: ");
  Serial.print(moisture);
  Serial.print("% \n");
  delay(1000);
}
