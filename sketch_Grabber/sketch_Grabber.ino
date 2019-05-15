#include <Servo.h>    // Use Servo library, included with IDE

Servo myServo;        // Create Servo object to control the servo 

void setup() { 
  myServo.attach(10);  // Servo is connected to digital pin 9 
  
} 

void loop() { 
   myServo.write(0);   // Rotate Gribber up
  delay(4000);          // Wait 4 seconds
  myServo.write(180);   // Rotate Gribber down
  delay(4000);          // Wait 2 seconds


}
