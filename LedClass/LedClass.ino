class Led{
  private:
    byte _pinNum;
  public:
    Led(byte pin){
      _pinNum = pin;
    }
};

Led firstLed(13);
Led secondLed(12);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
