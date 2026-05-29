#include <SoftwareSerial.h>
SoftwareSerial BT(10, 11); 
int pirPin = 2;
int ldrPin = A0;
int tempPin = A1;
int ledPin = 8;
int pirState = LOW;
int ldrValue;
int tempValue;
void setup()
{
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  BT.begin(9600);
  Serial.println("Home Automation System Started");
}
void loop()
{
  pirState = digitalRead(pirPin);
  ldrValue = analogRead(ldrPin);
  tempValue = analogRead(tempPin);
  Serial.print("PIR: ");
  Serial.print(pirState);
  Serial.print(" | LDR: ");
  Serial.print(ldrValue);
  Serial.print(" | Temp: ");
  Serial.println(tempValue);
  if (pirState == HIGH || ldrValue < 300 || tempValue > 500)
  {
    digitalWrite(ledPin, HIGH);
    BT.println("LIGHT ON (Auto Mode)");
  }
  else
  {
    digitalWrite(ledPin, LOW);
    BT.println("LIGHT OFF (Auto Mode)");
  }
  if (BT.available())
  {
    char command = BT.read();

    if (command == '1')
    {
      digitalWrite(ledPin, HIGH);
      BT.println("LIGHT ON (Manual)");
    }
    else if (command == '0')
    {
      digitalWrite(ledPin, LOW);
      BT.println("LIGHT OFF (Manual)");
    }
  }
  delay(500);
}