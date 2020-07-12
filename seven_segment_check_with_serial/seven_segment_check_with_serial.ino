
//                  a,b, c,d,e,f, g
int segmentPins[] = {11,10,7,8,9,12,13};

byte digits[10][8] ={
  //  a  b  c  d  e  f  g  .
  { 1, 1, 1, 1, 1, 1, 0, 0}, // 0
  { 0, 1, 1, 0, 0, 0, 0, 0}, // 1
  { 1, 1, 0, 1, 1, 0, 1, 0}, // 2
  { 1, 1, 1, 1, 0, 0, 1, 0}, // 3
  { 0, 1, 1, 0, 0, 1, 1, 0}, // 4
  { 1, 0, 1, 1, 0, 1, 1, 0}, // 5
  { 1, 0, 1, 1, 1, 1, 1, 0}, // 6
  { 1, 1, 1, 0, 0, 0, 0, 0}, // 7
  { 1, 1, 1, 1, 1, 1, 1, 0}, // 8
  { 1, 1, 1, 1, 0, 1, 1, 0} //  9
  };

void setup() {
  // put your setup code here, to run once:

  for(int i =0 ; i < 8; i++){
     pinMode(segmentPins[i],OUTPUT);
     digitalWrite(segmentPins[i],LOW);
    }

    Serial.begin(9600);
    Serial.println("Enter the Number from 0 to 9");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    char ch = Serial.read();
      if(ch >= '0' && ch <= '9'){
        int number = ch - '0';
        updateDisplay(number);
        }    
    }
}



 void updateDisplay(int value){
     setSegment(value);
  }

 void setSegment(int value){
  for(int i=0; i< 8;i++){
     digitalWrite(segmentPins[i], digits[value][i]);
    }
  }


  
