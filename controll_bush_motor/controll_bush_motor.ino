
int motor_left[] ={3,5};
int motor_right[] ={9,6};
int command = 0;
int PWMSpeed = 125;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:

  //Configure Bluetooth Reciver RX

  pinMode(0,INPUT_PULLUP);

  for(int i=0;i<2;i++){
    pinMode(motor_left[i],OUTPUT);
    pinMode(motor_right[i],OUTPUT);
  }

  motor_stop();
}

void loop() {
  // put your main code here, to run repeatedly:
 

  if(Serial.available() > 0){
      command = Serial.read();

      Serial.print(command);

     switch(command){

        case '1' :
          drive_forward();
          break;
        
        case '2' :
       drive_backward();
          break; 

          case '3' :
            turn_right();
          break; 

          case '4' :
         turn_left();
          break;

           case '0' :
         motor_stop();
          break; 

         default :
         motor_stop();
         break;
        
        }
        
    }

//drive_backward();
//forwardLeft();
//forwardRight();
//
//backwardRight();
//backwardLeft();


   


}

void motor_stop(){
  Serial.print("Motor -- Stop \n");
    digitalWrite(motor_left[0],LOW);
    digitalWrite(motor_left[1],LOW);

    digitalWrite(motor_right[0], LOW);
    digitalWrite(motor_right[1], LOW);
  }


  void turn_right(){
   
    Serial.print("Motor :  RIGHT\n");

    digitalWrite(motor_right[0], LOW); 
    analogWrite(motor_right[1], PWMSpeed);
    
    digitalWrite(motor_left[0], PWMSpeed);
    analogWrite(motor_left[1], LOW);
  }


  void drive_forward(){
      Serial.print("Motor- Drive Farward");


      digitalWrite(motor_left[0], LOW);
      digitalWrite(motor_left[1], HIGH);

      digitalWrite(motor_right[0], LOW);
      digitalWrite(motor_right[1], HIGH);
    
    }

    void turn_left() { 
      //left
    Serial.print("Motor :  LEFT\n");
      digitalWrite(motor_left[0], LOW); 
    analogWrite(motor_left[1], PWMSpeed);
    
    digitalWrite(motor_right[0], PWMSpeed);
    analogWrite(motor_right[1], LOW);

}


    void drive_backward(){
      Serial.print("Motor- Drive Farward");


      digitalWrite(motor_left[0], HIGH);
      digitalWrite(motor_left[1], LOW);

      digitalWrite(motor_right[0], HIGH);
      digitalWrite(motor_right[1], LOW);
    
    }



   void forwardLeft(){
    
      Serial.print("Motor- Drive Farward Left");
      digitalWrite(motor_left[0], LOW);
      digitalWrite(motor_left[1], HIGH);

    }


    void backwardLeft(){
    
      Serial.print("Motor- Drive BackWard Left");
      digitalWrite(motor_left[0], HIGH);
      digitalWrite(motor_left[1], LOW);

    }
    

   void forwardRight(){
      Serial.print("Motor- Drive Farward Right");
      digitalWrite(motor_right[0], LOW);
      digitalWrite(motor_right[1], HIGH);
    }

  void backwardRight(){
      Serial.print("Motor- Drive Backward Right");
      digitalWrite(motor_right[0], HIGH);
      digitalWrite(motor_right[1], LOW);
    }


    
