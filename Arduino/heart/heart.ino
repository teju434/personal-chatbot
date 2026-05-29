const int heartbeatSensorPin = A0;
void setup() 
{
  pinMode(heartbeatSensorPin, INPUT);
  Serial.begin(9600);
}
void loop() 
{
  int heartbeatValue = analogRead(heartbeatSensorPin);
  int heartbeatRate = map(heartbeatValue, 0, 1023, 60, 100);
  Serial.print("Heartbeat Rate (BPM): ");
  Serial.println(heartbeatRate);
  delay(1000);
}