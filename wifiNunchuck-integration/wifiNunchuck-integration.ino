
#include <Wire.h>
#include <ArduinoNunchuk.h>

#define BAUDRATE 19200

ArduinoNunchuk nunchuk = ArduinoNunchuk();

void setup() {
  // put your setup code here, to run once:
   Serial.begin(BAUDRATE);
   nunchuk.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  nunchuk.update();
  Serial.print("X: ");
  Serial.print(nunchuk.analogX, DEC);
  Serial.print("  | ");

  Serial.print("Y: ");
  Serial.print(nunchuk.analogY, DEC);
  Serial.print("  | ");

  Serial.print("Accel - X: ");
  Serial.print(nunchuk.accelX, DEC);
  Serial.print("  | ");

  Serial.print("Accel - Y: ");
  Serial.print(nunchuk.accelY, DEC);
  Serial.print("  | ");


  Serial.print("Accel - Z: ");
  Serial.print(nunchuk.accelZ, DEC);
  Serial.print("  | ");

  Serial.print("Z - Button ");
  Serial.print(nunchuk.zButton, DEC);
  Serial.print("  | ");

  Serial.print("C - Button ");
  Serial.print(nunchuk.cButton, DEC);
  Serial.println("  | ");
  
  


  
}
