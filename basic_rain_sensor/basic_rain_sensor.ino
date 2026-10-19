const int rainPin = 2;
const int ledPin = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(rainPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (digitalRead(rainPin) == LOW) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
  delay(100);
}