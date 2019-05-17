#include <Servo.h>

Servo right;
Servo left;
int pinLE = 7;
 int pinRE = 8;
 int LEstatus;
int state1, state2;
int i = 0;
float distance = 0;
float count;
float d1;

void setup() {
 
  pinMode(pinLE, INPUT);
  pinMode(pinRE, INPUT);
  right.attach(13);
  left.attach(12);
  Serial.begin(9600);
 
  
}

void loop() {
  Turn(45);
}

void Turn(float Degrees){
  if(Degrees > 0){
      left.writeMicroseconds(1700);        
  right.writeMicroseconds(1700); 
  state1 = digitalRead(pinLE);
  delay(10);
  state2 = digitalRead(pinLE);
  if(state1 != state2){
    i++;
  }
d1 = (Degrees/360)*10*3.14;
count = (d1/20.73)*15;
    Serial.println(d1);
    Serial.println(Degrees);
  
  if(i == count){
      left.detach();        
      right.detach();  
  }
  }
    if(Degrees < 0){
      left.writeMicroseconds(1300);        
  right.writeMicroseconds(1300); 
  state1 = digitalRead(pinLE);
  delay(10);
  state2 = digitalRead(pinLE);
  if(state1 != state2){
    i++;
  }
d1 = (Degrees/360)*10*3,14;
count = (d1/20,73)*15;
Serial.println(count);

  
  if(i == count){
      left.detach();        
      right.detach();  
  }
  }
}