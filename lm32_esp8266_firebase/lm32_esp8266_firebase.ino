#include "Timer.h"
#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>
#define tempPin A0
#define pin0 D1
#define pin1 D2
#define pin2 D3
#define pin3 D4
#define dataPin D5
#define latchPin D6
#define clockPin D7
Timer t;
FirebaseData firebaseData;
float tempC;

//共陽
const byte LEDs[10] = {
  B10000001, //0
  B11001111, //1
  B10010010, //2
  B10000110, //3
  B11001100, //4
  B10100100, //5
  B10100000, //6
  B10001111, //7
  B10000000, //8
  B10001100  //9
};


void setup()
{
  Serial.begin(115200); //opens serial port, sets data rate to 9600 bps
  pinMode(pin0, OUTPUT);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  t.every(1000, oneSecondRun);
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
}

void loop()
{
  t.update();
  displayLED(tempC);
}

void oneSecondRun(){
  tempC = getTemperature();
  Serial.println(tempC);;
  Firebase.setFloat(firebaseData,"/iot0624/temperature",tempC);
}

float getTemperature() {
  float temp;
  temp = analogRead(tempPin);           //read the value from the sensor
  temp = (temp / 1024 * 3.3 / 0.01);
  return temp;
}

void displayLED(float numbers) {
  //numbers = 25.73;
  int num0=(int)(numbers*100)%10;
  int num1=(int)(numbers*10)%10;
  int num2=(int)numbers%10;
  int num3= (int)numbers/10;
  byte dotNumber;
  for (int i = 0; i <= 3; i++) {
    //處理位數
    switch (i) {
      case 0:
        digitalWrite(pin0, HIGH);
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, LOW);
        digitalWrite(latchPin, LOW);
        shiftOut(dataPin, clockPin, LSBFIRST, LEDs[num0]);
        digitalWrite(latchPin, HIGH);
        break;
      case 1:
        digitalWrite(pin0, LOW);
        digitalWrite(pin1, HIGH);
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, LOW);
        digitalWrite(latchPin, LOW);
        shiftOut(dataPin, clockPin, LSBFIRST, LEDs[num1]);
        digitalWrite(latchPin, HIGH);
        break;
      case 2:
        digitalWrite(pin0, LOW);
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, HIGH);
        digitalWrite(pin3, LOW);
        dotNumber=B01111111 & LEDs[num2];
        digitalWrite(latchPin, LOW);
        shiftOut(dataPin, clockPin, LSBFIRST, dotNumber);
        digitalWrite(latchPin, HIGH);
        break;
      case 3:
        digitalWrite(pin0, LOW);
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, HIGH);
        digitalWrite(latchPin, LOW);
        shiftOut(dataPin, clockPin, LSBFIRST, LEDs[num3]);
        digitalWrite(latchPin, HIGH);
        break;
    }
    delay(4);
  }
}
