#define BtnPin 2
#define RedPin 6
boolean btnState;
unsigned int switchCount = 0;
unsigned int stateChangeCount = 0;

void setup() { 
  Serial.begin(115200);
  pinMode(BtnPin,INPUT_PULLUP);
  pinMode(RedPin,OUTPUT);
  btnState = digitalRead(BtnPin);
}

void loop() {
  boolean nowState = digitalRead(BtnPin);
  if (btnState != nowState) {
    delay(10);
    if (nowState == digitalRead(BtnPin)) {
      btnState = nowState;
      stateChangeCount++;
      switch (stateChangeCount % 2) {
        case 0:
          switchCount++;
          break;
      }
    }
  }
  switch (switchCount%4){
    case 0 :
      Serial.println("關燈檔位");
      digitalWrite(RedPin,LOW);
      break;
    case 1:
      digitalWrite(RedPin,HIGH);
      Serial.println("高亮度檔位");
      break;
    case 2:
      analogWrite(RedPin,20);
      Serial.println("低亮度檔位");
      break;
    case 3:
      Serial.println("閃爍檔位");
      unsigned long currentTime = millis();
      if((currentTime%600)>=300){
        digitalWrite(RedPin,HIGH);
      }else{
        digitalWrite(RedPin,LOW);
      }    
      break;
  }
}
