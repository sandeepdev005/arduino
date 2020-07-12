

#define trigPIN 8
#define echoPIN 9
#define redLED 4
#define greenLED 2
#define alaram 5


int range =2 ;
void setup() {
  // put your setup code here, to run once:
  pinMode(trigPIN,OUTPUT);
  pinMode(echoPIN, INPUT);

  pinMode(redLED,OUTPUT);
  pinMode(greenLED,OUTPUT);

  digitalWrite(greenLED,HIGH);
  digitalWrite(redLED,LOW);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  long duration, inches, cms;

  digitalWrite(trigPIN, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPIN,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPIN,LOW);

  duration = pulseIn(echoPIN,HIGH);

  inches = microsecondsToInches(duration);
  cms = microsecondsToCentimeters(duration);

  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cms);
  Serial.print("cm");
  Serial.println();


  if(range > inches){
    Serial.println("DANGER");
    digitalWrite(redLED,HIGH);
    digitalWrite(greenLED,LOW);
    tone(alaram, 10000);
    delay(100);
    
    }else{
      
    Serial.println("GOOD");
    digitalWrite(redLED,LOW);
    digitalWrite(greenLED,HIGH);
    noTone(alaram);
    delay(100);
      
      }

      delay(200);
  

}


long microsecondsToInches(long microseconds)
{
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}
