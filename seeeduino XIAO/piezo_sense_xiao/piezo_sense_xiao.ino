//OUT <===> PIN 2
const int ledPin=13;
void setup() {
    Serial.begin(9600);
    pinMode(ledPin,OUTPUT);
}
 
void loop() {
    int sensorState = analogRead(2);
    Serial.println(sensorState);
    delay(100);
    if(sensorState == HIGH)
    {
        digitalWrite(ledPin,HIGH);
    }
    else
    {
        digitalWrite(ledPin,LOW);
    }
}
