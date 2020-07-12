#define LED_PIN 8
#define POTENTIO_METER A0

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_PIN,OUTPUT);

}

void loop() {

  //converting the value between 0-255
  int reading =  map(analogRead(POTENTIO_METER),0,1023,0,225);
  Serial.print('\n');
  Serial.print(reading);
  analogWrite(LED_PIN,reading);
  delay(10);


}
