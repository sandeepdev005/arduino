
#define redLED 8
#define greenLED 9
#define yellowLED 10
#define pushBUTTON 2

int timesOn[] = {100,250,400,500};
int delayTimes[] = {250,500,1000,1500};


//Declaring volatile variable so they can accessed/changed within the ISR
volatile boolean redLEDLit = false;
volatile boolean isWinner = false;


void setup() {
  // put your setup code here, to run once:
    pinMode(redLED,OUTPUT);
    pinMode(greenLED,OUTPUT);
    pinMode(yellowLED,OUTPUT);
    pinMode(pushBUTTON,INPUT_PULLUP);
    attachInterrupt(0,checkWinner,FALLING);
    Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  

  int LEDToLight = random(1,4);
  int periodLEDLit = timesOn[random(4)];

  //light the respective LED
  lightLED(LEDToLight,periodLEDLit);

  turnOffLEDS();


  int delayTime = delayTimes[random(4)];
  delay(delayTime);

  if(isWinner){
    isWinner = false;
    winner();
    }
}

void lightLED(int ledLight, int duration){
  switch(ledLight){

    case 1: 
          digitalWrite(greenLED,HIGH);
         break;

    case 2 :
          redLEDLit=true;
          digitalWrite(redLED,HIGH);
          break;

    case 3:
          digitalWrite(yellowLED,HIGH);
          break;  

    default :
    break;               
    }


    delay(duration);
    redLEDLit = false;
    
}


void turnOffLEDS(){
  digitalWrite(greenLED, LOW);
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, LOW);
  }



  void winner(){

    for(int i=0 ; i<3 ;i++){
       digitalWrite(greenLED, HIGH);
       digitalWrite(redLED, HIGH);
       digitalWrite(yellowLED, HIGH);

       delay(250);

      digitalWrite(greenLED, LOW);
      digitalWrite(redLED, LOW);
      digitalWrite(yellowLED, LOW);
      }

      delay(3000);
    
    }



    void checkWinner(){
      Serial.println("Intruppt occured");
      if(redLEDLit){
        isWinner =true;
        }
      
      }
