#include "SwitchButton.h"
#include "Led.h"

SwitchButton leftBtn(2);
SwitchButton rightBtn(4);
Led redLed(8);
Led yellowLed(9);
Led greenLed(10);

void setup() {
  Serial.begin(115200);
}
void loop() {
  // put your main code here, to run repeatedly:
  unsigned long leftCounts = leftBtn.getStateChangeCount();
  unsigned long rightCounts = rightBtn.getStateChangeCount();  
  if (leftCounts>0){
  switch (leftCounts % 8){
    case 0:
      redLed.off();
      yellowLed.off();
      greenLed.off();
      break;
    case 2:
      switch (rightCounts % 6){
        case 0:
          redLed.on();
          yellowLed.off();
          greenLed.off();
          break;
        case 2:
          redLed.off();
          yellowLed.on();
          greenLed.off();
          break;
        case 4:
          redLed.off();
          yellowLed.off();
          greenLed.on();
          break;
      }
      break;
    case 4:
       if (rightCounts % 6 == 0){
          redLed.on();
          yellowLed.on();
          greenLed.off();
          break;
       }
       else if (rightCounts % 6 == 2){
          redLed.on();
          yellowLed.off();
          greenLed.on();
          break;
        }
       else {
          redLed.off();
          yellowLed.on();
          greenLed.on();
          break;
        }
        break;
    case 6:
       redLed.on();
       yellowLed.on();
       greenLed.on();
       break;
       
  }
  }
  
}
