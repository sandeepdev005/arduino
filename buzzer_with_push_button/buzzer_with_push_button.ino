#define BUZZER_PIN 8
#define PUSH_BUTTON 9

void setup() {
  // put your setup code here, to run once:

  pinMode(BUZZER_PIN,OUTPUT);
  pinMode(PUSH_BUTTON,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

   if(digitalRead(PUSH_BUTTON)==HIGH)
   {
     tone(BUZZER_PIN,10000);
    }else{
      noTone(BUZZER_PIN);
    }
  

}
