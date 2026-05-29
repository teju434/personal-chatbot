#include <Servo.h>
Servo lockServo;
const int servoPin = 9;
const int ledPin = 13;
void setup()
{
  Serial.begin(9600);
  lockServo.attach(servoPin);
  pinMode(ledPin, OUTPUT);
}
void loop()
{
  if (Serial.available())
  {
    char command = Serial.read();
    if (command == '1')
    {
      lockDoor();
      Serial.println("Door locked");
    }
    else if (command == '0')
    {
      unlockDoor();
      Serial.println("Door unlocked");
    }
  }
}
void unlockDoor()
{
  lockServo.write(90);
  digitalWrite(ledPin, HIGH);
}
void lockDoor()
{
  lockServo.write(0);
  digitalWrite(ledPin, LOW);
}