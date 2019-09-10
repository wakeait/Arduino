#define tempPin A0
#define pin0 D1
#define pin1 D2
#define pin2 D3
#define pin3 D4
#define dataPin D5
#define latchPin D6
#define clockPin D7
int index1 = 0;
const byte LEDs[10] = {
  B10000001,
  B11001111,
  B10010010,
  B10000110,
  B11001100,
  B10100100,
  B10100000,
  B10001111,
  B10000000,
  B10001100
};

void setup()
{
  Serial.begin(115200); //opens serial port, sets data rate to 9600 bps
  pinMode(pin0,OUTPUT);
  pinMode(pin1,OUTPUT);
  pinMode(pin2,OUTPUT);
  pinMode(pin3,OUTPUT);

  pinMode(dataPin,OUTPUT);
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
}

void loop()
{
 float tempC = getTemperature();
 Serial.println(tempC);
  digitalWrite(pin0,HIGH);
  digitalWrite(pin1,HIGH);
  digitalWrite(pin2,HIGH);
  digitalWrite(pin3,HIGH);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin,LSBFIRST,LEDs[index1]);
  digitalWrite(latchPin, HIGH);
  index1++;
  delay(1000);
  if (index1>=10){
    index1=0;
  }
}

float getTemperature(){
  float tempC;
  tempC = analogRead(tempPin);           //read the value from the sensor
  tempC = (tempC / 1024 * 3.3 / 0.01)-2;
  return tempC;
}
