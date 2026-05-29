#include<Servo.h>
Servo myservo;
#define TRIG_PIN 9
#define ECHO_PIN 10
long duration=0;
int distance=0;
void setup() 
{
  myservo.attach(7);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}
void loop() 
{
  ultrasonic();
  Serial.println(distance);
  myservo.write(0);
  if (distance<=9) 
  {
    Serial.write(90);
  }
}
void ultrasonic()
{
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2; 
}
