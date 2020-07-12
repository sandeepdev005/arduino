#define LED_PIN 8
#define PUSH_BUTTON 9

void setup() {
  // put your setup code here, to run once:

  pinMode(LED_PIN, OUTPUT);
  pinMode(PUSH_BUTTON, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

//   digitalWrite(LED_PIN,HIGH);

  if(digitalRead(PUSH_BUTTON)==LOW){
     digitalWrite(LED_PIN,LOW);
    }else{
      digitalWrite(LED_PIN,HIGH);
    }

}
