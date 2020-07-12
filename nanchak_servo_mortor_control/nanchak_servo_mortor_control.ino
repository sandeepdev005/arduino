
#include <Wire.h>
#include <Servo.h>
#include <ArduinoNunchuk.h>

#define BAURDRATE 19200


Servo servo1;
Servo servo2;
ArduinoNunchuk nunchuk = ArduinoNunchuk();
int pos1 = 90;
int pos2 = 90;


void setup() {
  // put your setup code here, to run once:

  servo1.attach(9);
  servo2.attach(10);
  Serial.begin(BAURDRATE);
  nunchuk.init();
  servo1.write(pos1);
  servo2.write(pos2);

  delay(15);
  

}

void loop() {
  // put your main code here, to run repeatedly:
   nunchuk.update();

   Serial.print("X -");
   Serial.print(nunchuk.analogX);
   Serial.print("Y - ");
    Serial.println(nunchuk.analogY);

   pos1 = map(nunchuk.analogX, 212,24,0,180);
   pos2 = map(nunchuk.analogY, 38,220,0,180);

   servo1.write(pos1);
   delay(15);
   servo2.write(pos2);
   delay(15);
   
}
