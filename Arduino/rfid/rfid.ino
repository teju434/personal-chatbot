#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 53    
#define RST_PIN 5    
MFRC522 rfid(SS_PIN, RST_PIN); 
String knownUIDs[][2] = {
  {"A307DBD9", "Suhail"},
  {"BD202D5B", "Tharun"},
  {"FA01B3AB", "Ganesh"},
};
const int numUsers = sizeof(knownUIDs) / sizeof(knownUIDs[0]);
void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  Serial.println("=======================================");
  Serial.println("   RFID Attendance System Initialized   ");
  Serial.println("=======================================");
  Serial.println("Place your RFID card near the reader...");
  Serial.println();
}
void loop() {
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    return;
  }
  String uid = "";
  for (byte i = 0; i < rfid.uid.size; i++) {
    if (rfid.uid.uidByte[i] < 0x10) uid += "0";
    uid += String(rfid.uid.uidByte[i], HEX);
  }
  uid.toUpperCase();

  Serial.print("Card Detected! UID: ");
  Serial.println(uid);
  bool known = false;
  for (int i = 0; i < numUsers; i++) {
    if (uid == knownUIDs[i][0]) {
      known = true;
      Serial.print("✅ Welcome, ");
      Serial.println(knownUIDs[i][1]);
      Serial.print("Attendance marked at: ");
      printCurrentTime();
      break;
    }
  }
  if (!known) {
    Serial.println("❌ Unknown card. Access denied.");
  }
  Serial.println("---------------------------------------");
  delay(2000); 
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}
void printCurrentTime() {
  unsigned long currentMillis = millis();
  unsigned long seconds = currentMillis / 1000;
  unsigned long minutes = seconds / 60;
  seconds = seconds % 60;
  Serial.print(minutes);
  Serial.print(" min ");
  Serial.print(seconds);
  Serial.println(" sec since system start.");
