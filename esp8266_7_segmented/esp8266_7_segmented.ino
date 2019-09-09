#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>

FirebaseData firebaseData;
#define dataPin D2
#define latchPin D3
#define clockPin D4

const byte LEDs[10] = {
  B01111110, //0
  B00110000, //1
  B01101101, //2
  B01111001, //3
  B00110011, //4
  B01011011, //5
  B01011111, //6
  B01110000, //7
  B01111111, //8
  B01110011  //9
};
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
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}
void loop() {
  if (Firebase.getInt(firebaseData, "/iot0624/sevenSeg")) {
    if (firebaseData.dataType() == "int") {
      int num = firebaseData.intData();
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin,LSBFIRST,LEDs[num]);
      digitalWrite(latchPin, HIGH);
      Serial.println(firebaseData.intData());
    }
  } else {
    Serial.println(firebaseData.errorReason());
  }
  //delay(500);
}
