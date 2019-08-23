#include "Led.h"
#define BtnPin 2

boolean btnState;
unsigned int switchCount = 0;
unsigned int stateChangeCount = 0;
Led redLed(13);
Led yellowLed(12);

void setup() {
  Serial.begin(115200);
  pinMode(BtnPin, INPUT_PULLUP);
  btnState = digitalRead(BtnPin);
  redLed.off();
}

void loop() {
  boolean nowState = digitalRead(BtnPin);
  if (btnState != nowState) {
    delay(10);
    if (nowState == digitalRead(BtnPin)) {
      btnState = nowState;
      stateChangeCount++;
      switch (stateChangeCount % 4) {
        case 0:
          redLed.off();
          yellowLed.off();
          break;
        case 2:
          redLed.on();
          yellowLed.on();
          break;
      }
    }
  }
}
