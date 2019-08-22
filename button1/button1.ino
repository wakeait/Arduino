#define BtnPin 2
#define RedPin 13
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(BtnPin,INPUT);
  pinMode(RedPin,OUTPUT);
}

void loop() {
  Serial.println(digitalRead(BtnPin));
  if (digitalRead(BtnPin)==1){
    digitalWrite(RedPin,HIGH);
  }else{
    digitalWrite(RedPin,LOW);
  }
  delay(100);
}
