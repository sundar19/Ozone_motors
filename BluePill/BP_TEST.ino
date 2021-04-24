void setup() {

    pinMode(PC13, OUTPUT);
    Serial.begin(9600);

}

void loop() {
  Serial.println("hello NANO");
  digitalWrite(PC13, HIGH);

  delay(250);

  digitalWrite(PC13, LOW);

  delay(250);           

}
