#include "SevenSegmented.h"

SevenSegmented::SevenSegmented(byte* pins){
  _mapArdiuinoPin = pins;
  Serial.begin(115200);
  Serial.print(_mapArdiuinoPin[0]);  
};
