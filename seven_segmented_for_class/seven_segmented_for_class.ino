#include "SevenSegmented.h"

byte mapArdiuinoPin[] = {2, 3, 4, 5, 6, 7, 8};
SevenSegmented s1(mapArdiuinoPin);
void setup() {
  // put your setup code here, to run once:
  s1.displayDigit(7);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=9;i>=0;i--){
  s1.displayDigit(i);
  delay(50);
 }
}
