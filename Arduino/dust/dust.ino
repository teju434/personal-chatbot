#include <Servo.h>
const int trigPin = 9;
const int echoPin = 10;
const int servoPin = 6;
long duration;
int distance;
Servo myservo;
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(servoPin);
  myservo.write(0);  
  Serial.begin(9600);
}
void loop() 
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  if (distance > 0 && distance <= 15) {
    myservo.write(180);   
  } 
  else {
    myservo.write(0);     
  }
  delay(100);
}