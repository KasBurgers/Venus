#include <Servo.h>

Servo right;
Servo left;

void setup() {
 
  Serial.begin(9600);
  
}

void loop() {
  right.attach(13);
  left.attach(12);
  left.writeMicroseconds(1700);        
  right.writeMicroseconds(1300); 
  delay(2000);
  left.detach();       
  right.detach();
  delay(5000);  
  }
