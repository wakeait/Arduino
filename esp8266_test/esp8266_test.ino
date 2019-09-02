#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>

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
}
void loop() {}