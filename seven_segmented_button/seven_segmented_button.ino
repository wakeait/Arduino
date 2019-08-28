#include "SwitchButton.h"
SwitchButton rightBtn(12);
byte digits[10][7] = {
  { 1, 1, 1, 1, 1, 1, 0 }, // = 0
  { 0, 1, 1, 0, 0, 0, 0 }, // = 1
  { 1, 1, 0, 1, 1, 0, 1 }, // = 2
  { 1, 1, 1, 1, 0, 0, 1 }, // = 3
  { 0, 1, 1, 0, 0, 1, 1 }, // = 4
  { 1, 0, 1, 1, 0, 1, 1 }, // = 5
  { 1, 0, 1, 1, 1, 1, 1 }, // = 6
  { 1, 1, 1, 0, 0, 0, 0 }, // = 7
  { 1, 1, 1, 1, 1, 1, 1 }, // = 8
  { 1, 1, 1, 0, 0, 1, 1 }  // = 9
};

byte mapArdiuinoPin[] = {2, 3, 4, 5, 6, 7, 8};

void setup() {
  Serial.begin(115200);
  for (byte i = 0; i < 7; i++) {
    pinMode(mapArdiuinoPin[i], OUTPUT);
  }
}

void loop() {
  unsigned long rightCounts = rightBtn.getStateChangeCount();  
  unsigned long getDigit = (rightCounts%20)/2;
  displayDigit(getDigit);
}

void displayDigit(int displayDigit){
  int displayIndex = (int)displayDigit;
  for(int i=0; i<7 ; i++){
    bool onePinState = digits[displayIndex][i];
    byte pinNum = mapArdiuinoPin[i];
    digitalWrite(pinNum, onePinState);
  }
}
