#define redPin 6
#define potPin A0
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(redPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int anV = analogRead(potPin);
  int valueof8bit = (float)anV/1023*255;
  analogWrite(redPin,valueof8bit);
  Serial.println(valueof8bit);
  delay(100);
}
