#define LED_PIN 8
const int PUSH_PIN = 10;

int pinNumber = 7;
char letter ='A';
boolean isLit = false;

int pinout[] = {1,2,3,5,6};
int pinIn[3];

char tempDisplay[] ="Temperature is 75. degree fharenheat.";

byte digits[5][6]={
    {1,0,1,0,1,0},
    {1,0,1,0,1,0},
    {1,0,1,0,1,0},
    {1,0,1,0,1,0},
    {1,0,1,0,1,0},
  };


struct joystrick_reading {
  int x_position;
  int  y_position;
  boolean isButtonPressed;
};

joystrick_reading joyStick;
void setup() {
  // put your setup code here, to run once:
 joyStick.x_position = 122;
 joyStick.y_position = 453;
 joyStick.isButtonPressed = true;

 pinIn[1] =10;
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(isLEDLIT());
}

boolean isLEDLIT(){
  return (digitalRead(LED_PIN)== HIGH);
  }

void conditions(){
     switch(1){
      case 1:
      Serial.println("1");
      break;

      case 2:
      Serial.println("2");
      break;

      case 3:
      Serial.println("3");
      break;
      }
    }
