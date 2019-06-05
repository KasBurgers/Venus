#include <Servo.h>
#include <math.h>

Servo right;
Servo left;
int pinLE = 7;
int pinRE = 8;
int rotation = 0;

void setup() {
 
  pinMode(pinLE, INPUT);
  pinMode(pinRE, INPUT);
  Serial.begin(9600);
   
}

void loop() {

}

void drive(float amount) {
  int count1 = 0;
  int count2 = 0;
  int prev_value1 = digitalRead(7);
  int prev_value2 = digitalRead(8);
  int value_now1;
  int value_now2;
  float calculation1 = abs(round(amount*15));
  left.attach(12);
  right.attach(13);
  while((count1 < calculation1) and (count2 < calculation1)) {
    value_now1 = digitalRead(7);
    value_now2 = digitalRead(8);
    if(amount >= 0) {
      left.write(1700);
      right.write(1300);
    }
    else {
      left.write(1300);
      right.write(1700);
    }
    if (value_now1 != prev_value1) {
      count1++;
      prev_value1 = value_now1;
    }
    if (value_now2 != prev_value2) {
      count2++;
      prev_value2 = value_now2;
    }
  }
  left.detach();
  right.detach();
}

void turn(float Degrees){
  int count1 = 0;
  int count2 = 0;
  int prev_value1 = digitalRead(7);
  int prev_value2 = digitalRead(8);
  int value_now1;
  int value_now2;
  float calculation2 = abs(round((((Degrees/360)*10*3.14)/20.73)*15));
  left.attach(12);
  right.attach(13);
  while((count1 < calculation2) or (count2 < calculation2)) {
      value_now1 = digitalRead(7);
      value_now2 = digitalRead(8);
      if(Degrees >= 0) {
        left.write(1700);
        right.write(1700);
      }
      else {
        left.write(1300);
        right.write(1300);
      }
      if (value_now1 != prev_value1) {
        count1++;
        prev_value1 = value_now1;
      }
      if (value_now2 != prev_value2) {
        count2++;
        prev_value2 = value_now2;
      }
    }
  left.detach();
  right.detach();

  int DegreesINT = (int) Degrees;
  rotation = rotation + DegreesINT;
  if (rotation >= 360) {
    rotation = rotation%360;
  }
  else if (rotation <= -360) {
    rotation = rotation%(-360);
  }
}