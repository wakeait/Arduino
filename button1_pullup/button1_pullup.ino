#define BtnPin 2
#define RedPin 13
boolean LedState = false;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(BtnPin,INPUT_PULLUP);
  pinMode(RedPin,OUTPUT);
}

void loop() {
  Serial.println(digitalRead(BtnPin));
  int ct =0;
  if (LedState==true){
    digitalWrite(RedPin,HIGH);
  }else {
    digitalWrite(RedPin,LOW);
  }
  if (digitalRead(BtnPin)==0&&ct==0){
    LedState = !LedState; 
    ct+=1;
  }else {
    ct=0;
  }
  //delay(200);
}
