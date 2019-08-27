#include "SwitchButton.h"

SwitchButton leftBtn(2);
SwitchButton rightBtn(4);

void setup() {
  Serial.begin(115200);
}
void loop() {
  // put your main code here, to run repeatedly:
  unsigned long leftCounts = leftBtn.getStateChangeCount();  
  Serial.print("leftCount:");
  Serial.println(leftCounts);

  unsigned long rightCounts = rightBtn.getStateChangeCount();
  Serial.print("rightCount:");
  Serial.println(rightCounts);
  delay(100);
}
