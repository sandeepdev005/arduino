#include <Bounce2.h>

#define buzzer1 11
#define buzzer2 10
#define buzzer3 9


#define button1 3
#define button2 2
#define button3 1


//Instantiate a bounce objects

Bounce debounce1 = Bounce();
Bounce debounce2 = Bounce();
Bounce debounce3 = Bounce();

int noteSequnce[4];
int numNotes = sizeof(noteSequnce)/sizeof(int);
int currentNote = 0;
boolean challengePlayed = false;


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  pinMode(button1,INPUT_PULLUP);
  pinMode(button2,INPUT_PULLUP);
  pinMode(button3,INPUT_PULLUP);

  debounce1.attach(button1);
  debounce1.interval(5);

   debounce2.attach(button2);
  debounce2.interval(5);

   debounce3.attach(button3);
  debounce3.interval(5);

  randomSeed(analogRead(0));
  generateRandomPlaySequece();
  
}

void loop() {
  // put your main code here, to run repeatedly:

  if(!challengePlayed){
      challengePlayed = true;
      currentNote = 0;
      playSequence(noteSequnce);
    }

    //Update the bounce instance
    debounce1.update();
    debounce2.update();
    debounce3.update();

    //getting updated value
    int value1 = debounce1.read();
    int value2 = debounce2.read();
    int value3 = debounce3.read();

    if(debounce1.fell()){
      Serial.println("Button1 Pressed");
      playNote(1);
      verifyNotePlayedIsCorrect(1);
      }

  if ( debounce2.fell()  ) {
     Serial.println("Button2 Pressed");
    playNote(2);   
    verifyNotePlayedIsCorrect(2);
  }

   if ( debounce3.fell()  ) {
     Serial.println("Button3 Pressed");
    playNote(3);
    verifyNotePlayedIsCorrect(3);
  }


}


void verifyNotePlayedIsCorrect(int note){

        if(currentNote < numNotes){

          if(noteSequnce[currentNote] == note){
            currentNote++;

            if(currentNote == numNotes){
                 winner();
              }
            
            }else{
               looser();
              }
          
          }
  }


void winner(){
    currentNote =0;
    challengePlayed = false;
    generateRandomPlaySequece();

    for(int i = 0; i<3;i++){
      tone(buzzer3,4000);
       delay(250);
       noTone(buzzer3);
       delay(250);
      }
      delay(2000);
  
  }


  void looser(){
    currentNote =0;
    challengePlayed = false;
    tone(buzzer1, 200);
    delay(1000);
    noTone(buzzer1);
    delay(2000);
    }




void playSequence(int notes[]){

    for(int i=0;i<numNotes ;i++){
      playNote(notes[i]);
      }
  
  }

void playNote(int note){

    switch(note){

      case 1:
       tone(buzzer1,2000);
       delay(750);
       noTone(buzzer1);
       delay(500);
      break;


      case 2:
      tone(buzzer2,4000);
       delay(750);
       noTone(buzzer2);
       delay(500);
      break;

      case 3:
       tone(buzzer3,6000);
       delay(750);
       noTone(buzzer3);
       delay(500);
       break;

    default:
      break;   
      
    }
  
  }
  


void generateRandomPlaySequece(){

  for(int i=0; i < numNotes; i++){
        int num = random(1,4);
        Serial.print(num);
        noteSequnce[i] = num; 
    }
  
  }
