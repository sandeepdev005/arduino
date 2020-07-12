
const int LedPin = 13;
const int PushButton = 2;
void setup() {
  // put your setup code here, to run once:
  pinMode(LedPin, OUTPUT);
  pinMode(PushButton,INPUT_PULLUP);
  attachInterrupt(0,buttonPressed,FALLING);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

}


void buttonPressed(){
  Serial.println("Inturrpt Occured..");
  if(digitalRead(LedPin)){
    digitalWrite(LedPin,LOW);
    }
  else{
    digitalWrite(LedPin,HIGH);
    }
  }
