#include "DHT.h" 
#define DHTPIN 2 
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);
void setup() {
 Serial.begin(9600);
 dht.begin(); 
}
void loop() {
 float t = dht.readTemperature();  
 float h = dht.readHumidity(); 
 if (isnan(t) || isnan(h)) {
 Serial.println("Failed to read from DHT sensor!");
 return;
 }
 Serial.print("Temperature = ");
 Serial.print(t);
 Serial.println(" °C");
 Serial.print("Humidity = ");
 Serial.print(h);
 Serial.println(" %");
 delay(1000);
}