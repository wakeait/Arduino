#include <arduino.h>

class SwitchButton {
  private:
    byte _pinNum;
    unsigned long _stateChangeCount;
    boolean _state;

  public:
    SwitchButton(byte);
    unsigned long getStateChangeCount();
};
