#define redPin 6
#define potPin A0
#define pot1Pin A1
unsigned long noteTime = millis();
unsigned long note1Time = millis();
boolean ledState = false;
int valueOf8bit;
int valueOf8bit1;
int anV;
int anV1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(redPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  blinkLed();
}

void doSomething(){
  unsigned long currentTime = millis();
  if((currentTime - noteTime)>=100){
    noteTime = currentTime;
    anV = analogRead(potPin);
    valueOf8bit = (float)anV/1023*255;
    analogWrite(redPin,valueOf8bit);
    Serial.println(valueOf8bit);
  }
}

void blinkLed(){
  unsigned long currentTime = millis();
  anV = analogRead(potPin);
  anV1 = analogRead(pot1Pin);
  valueOf8bit = (float)anV/1023*255;
  valueOf8bit1 = (float)anV1/1023*500;
  if((currentTime-note1Time) >= valueOf8bit1){   
    note1Time = currentTime;
      Serial.println(valueOf8bit1);
      if(ledState == false){
        analogWrite(redPin,valueOf8bit);
        ledState = true;
      }else{
        digitalWrite(redPin,LOW);
        ledState = false;
      }
  }
}
