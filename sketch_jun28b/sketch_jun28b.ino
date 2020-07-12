#include <Bounce2.h>

#define BUTTON_PIN1 1
#define BUTTON_PIN 2
#define BUTTON_PIN3 3

#define LED_PIN 13

int ledState = LOW;


Bounce debouncer1 = Bounce(); // Instantiate a Bounce object
Bounce debouncer2 = Bounce(); 
Bounce debouncer3 = Bounce(); 

void setup() {
    Serial.begin(9600);
  debouncer2.attach(BUTTON_PIN,INPUT_PULLUP); // Attach the debouncer to a pin with INPUT_PULLUP mode
  debouncer2.interval(25); // Use a debounce interval of 25 milliseconds

  debouncer1.attach(BUTTON_PIN1,INPUT_PULLUP); // Attach the debouncer to a pin with INPUT_PULLUP mode
  debouncer1.interval(25);


  debouncer3.attach(BUTTON_PIN3,INPUT_PULLUP); // Attach the debouncer to a pin with INPUT_PULLUP mode
  debouncer3.interval(25);
  
  
  pinMode(LED_PIN,OUTPUT); // Setup the LED
  digitalWrite(LED_PIN,ledState);
 
}

void loop() {

   debouncer1.update();
   debouncer2.update();
   debouncer3.update();// Update the Bounce instance
   
   if ( debouncer1.fell() ) {  // Call code if button transitions from HIGH to LOW
    
     Serial.print("Button Pressed !!!");
     ledState = !ledState; // Toggle LED state
     digitalWrite(LED_PIN,ledState); // Apply new LED state
   }

   if ( debouncer2.fell() ) {  // Call code if button transitions from HIGH to LOW
    
     Serial.print("Button Pressed !!!");
     ledState = !ledState; // Toggle LED state
     digitalWrite(LED_PIN,ledState); // Apply new LED state
   }

   if ( debouncer3.fell() ) {  // Call code if button transitions from HIGH to LOW
    
     Serial.print("Button Pressed !!!");
     ledState = !ledState; // Toggle LED state
     digitalWrite(LED_PIN,ledState); // Apply new LED state
   }
}
