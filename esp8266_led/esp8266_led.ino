#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>
#define LED D4
bool ledState = false;
FirebaseData firebaseData;

void setup()
{
  Serial.begin(115200);
  Serial.println();
  WiFi.begin("robert_hsu", "1234567890");
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());

  Firebase.begin("iotwilly.firebaseio.com", "O4sQ98sdnxVyKmts0ZQ6VG8LtQIcChnCqvBgDW05");
  Firebase.reconnectWiFi(true);
  Firebase.setMaxRetry(firebaseData, 3);
  Firebase.setMaxErrorQueue(firebaseData, 30);

  pinMode(LED,OUTPUT);
}
void loop() {
  if (Firebase.getBool(firebaseData, "/iot0624/LED")) {
    if (firebaseData.dataType() == "boolean") {
      ledState =firebaseData.boolData();
      Serial.println(firebaseData.boolData());
      digitalWrite(LED,ledState);
    }
  } else {
    Serial.println(firebaseData.errorReason());
  }
  delay(500);
}
