#include "Led.h"
 
    Led::Led(byte pin){
      _pinNum = pin;
      pinMode(_pinNum,OUTPUT);
     }

     byte Led::getPinNum(){
        return _pinNum;
     }

     void Led::on(){
      digitalWrite(_pinNum,HIGH);
     }

     void Led::off(){
      digitalWrite(_pinNum,LOW);
     }
