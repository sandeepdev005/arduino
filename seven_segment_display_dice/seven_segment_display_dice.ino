
#define buttonPin 4
//                  a,b, c,d,e,f, g
int segmentPins[] = {11,10,7,8,9,12,13};

//byte digits[10][8] ={
//  //  a  b  c  d  e  f  g  .
//  { 1, 1, 1, 1, 1, 1, 0, 0}, // 0
//  { 0, 1, 1, 0, 0, 0, 0, 0}, // 1
//  { 1, 1, 0, 1, 1, 0, 1, 0}, // 2
//  { 1, 1, 1, 1, 0, 0, 1, 0}, // 3
//  { 0, 1, 1, 0, 0, 1, 1, 0}, // 4
//  { 1, 0, 1, 1, 0, 1, 1, 0}, // 5
//  { 1, 0, 1, 1, 1, 1, 1, 0}, // 6
//  { 1, 1, 1, 0, 0, 0, 0, 0}, // 7
//  { 1, 1, 1, 1, 1, 1, 1, 0}, // 8
//  { 1, 1, 1, 1, 0, 1, 1, 0} //  9
//  };

  byte digits[10][7] ={
  //  a  b  c  d  e  f  g  .
  { 1, 1, 1, 1, 1, 1, 0}, // 0
  { 0, 1, 1, 0, 0, 0, 0}, // 1
  { 1, 1, 0, 1, 1, 0, 1}, // 2
  { 1, 1, 1, 1, 0, 0, 1}, // 3
  { 0, 1, 1, 0, 0, 1, 1}, // 4
  { 1, 0, 1, 1, 0, 1, 1}, // 5
  { 1, 0, 1, 1, 1, 1, 1}, // 6
  { 1, 1, 1, 0, 0, 0, 0}, // 7
  { 1, 1, 1, 1, 1, 1, 1}, // 8
  { 1, 1, 1, 1, 0, 1, 1} //  9
  };


byte spinDigits [6][8] = {
  //  a  b  c  d  e  f  g
  { 1, 0, 0, 0, 0, 0, 0, 0}, // a
  { 0, 1, 0, 0, 0, 0, 0, 0}, // b
  { 0, 0, 1, 0, 0, 0, 0, 0}, // c
  { 0, 0, 0, 1, 0, 0, 0, 0}, // d
  { 0, 0, 0, 0, 1, 0, 0, 0}, // e
  { 0, 0, 0, 0, 0, 1, 0, 0}  // f
};



void setup() {
  // put your setup code here, to run once:

  for(int i =0 ; i < 8; i++){
     pinMode(segmentPins[i],OUTPUT);
     digitalWrite(segmentPins[i],LOW);
    }

    Serial.begin(9600);
    pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:


    if(digitalRead(buttonPin) == LOW){
        spin();
        roll();
        delay(500);
      }
  
}

 void roll(){
  int roll = random(1,7);
  updateDisplay(roll);
  }

  void spin(){
      for(int j=0; j< 6; j++){
          for(int i =0 ;i<7 ;i++){
             digitalWrite(segmentPins[i],spinDigits[j][i]); 
            }
            delay(250);
        }
    }



 void updateDisplay(int value){
     setSegment(value);
  }

 void setSegment(int value){
  for(int i=0; i< 7;i++){
     digitalWrite(segmentPins[i], digits[value][i]);
    }
  }


  
