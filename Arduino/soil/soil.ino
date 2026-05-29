#define SENSOR_PIN A0   
#define RELAY_PIN 7    
int moisture_threshold = 500; 
void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  int moisture_reading = analogRead(SENSOR_PIN);
  Serial.print("Moisture reading: ");
  Serial.println(moisture_reading);
  if (moisture_reading > moisture_threshold) {
    digitalWrite(RELAY_PIN, LOW);
    Serial.println("Soil is Wet. Turn off the pump...");
  } else {
    digitalWrite(RELAY_PIN, HIGH);
    Serial.println("Soil is dry. Turn on the pump.");
  }
  delay(1000); 
}
