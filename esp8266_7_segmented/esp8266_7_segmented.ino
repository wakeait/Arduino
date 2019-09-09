#define dataPin 2
#define latchPin 3
#define clockPin 4
#define inputPin A0
#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>
byte index = 0;
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

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(inputPin, INPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  index = firebaseData.intData();
  Serial.println(index);
  //digitalWrite(latchPin, LOW);
  //shiftOut(dataPin, clockPin,LSBFIRST,LEDs[index]);
  //digitalWrite(latchPin, HIGH);
  delay(500);
}
