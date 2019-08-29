#include "SevenSegmented.h"
#include "SwitchButton.h"
byte mapArdiuinoPin[] = {2, 3, 4, 5, 6, 7, 8};
SevenSegmented s1(mapArdiuinoPin);
SwitchButton rightBtn(12);
void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long rightCounts = rightBtn.getStateChangeCount();
  unsigned long getDigit = rightCounts%4;
  if(getDigit==0){
  for(int i=9;i>=0;i--){
  s1.displayDigit(i);
  delay(50);
 }
  }
}
