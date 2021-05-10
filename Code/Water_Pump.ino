#define relay_pin 6

void setup() {
  // Set RelayPin as an output pin
  pinMode(relay_pin, OUTPUT);
}

void loop() {
  // Let's turn on the relay...
  digitalWrite(relay_pin, LOW);
  delay(5000);
  
  // Let's turn off the relay...
  digitalWrite(relay_pin, HIGH);
  delay(5000);
}
