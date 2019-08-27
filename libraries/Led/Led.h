#include <arduino.h>
class Led{
  private:
    byte _pinNum;
  public:
    Led(byte pin);
    byte getPinNum();
    void on();
    void off();
};
