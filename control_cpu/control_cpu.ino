#define motor_pin 11

void setup() {
  // put your setup code here, to run once:
  pinMode(motor_pin,OUTPUT);
  analogWrite(motor_pin,0);
  Serial.begin(9600);
  Serial.write("Enter a number between 0 to 9");

}

void loop() {
  // put your main code here, to run repeatedly:

//  if(Serial.available()){
//
//  char ch = Serial.read();
//
//   if(ch>='0' && ch<='9'){
//    int speed = ch - '0';
//    Serial.print(speed);
//    analogWrite(motor_pin,map(speed,0,9,0,255));
//    }
//    
//    }


    analogWrite(motor_pin, 1023);
delay(3000);
analogWrite(motor_pin, 0);
delay(3000);
analogWrite(motor_pin, 512);
delay(3000);
analogWrite(motor_pin, 0);
delay(3000);

}
