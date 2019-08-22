#define BtnPin 2
#define RedPin 13
boolean btnState;
unsigned int switchCount = 0;

void setup() { 
  Serial.begin(115200);
  pinMode(BtnPin,INPUT_PULLUP);
  pinMode( RedPin,OUTPUT);
  btnState = digitalRead(BtnPin);
}

void loop() {
  boolean nowState = digitalRead(BtnPin);
  if(btnState != nowState){
    btnState = nowState;
    switchCount++;
  }

  if ((switchCount/2)%2==0){
    digitalWrite(RedPin,HIGH);
  }else {
    digitalWrite(RedPin,LOW);
  }
  Serial.println(switchCount);
  delay(10);
}
