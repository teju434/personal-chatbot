#define TRIG_PIN 9
#define ECHO_PIN 10
const int tankHeight = 30; 
void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600);
  Serial.println("Ultrasonic Water Level Measurement");
}
void loop() {
  long duration;
  int distance;
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2; 
  int waterLevel = tankHeight - distance;
  Serial.print("Distance from sensor: ");
  Serial.print(distance);
  Serial.println(" cm");
  if (waterLevel >= 0)
 {
    Serial.print("Water Level: ");
    Serial.print(waterLevel);
    Serial.println(" cm");
  } else {
    Serial.println("Tank Empty");
  }
  Serial.println("--------------------");
  delay(1000);
}
