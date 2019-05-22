#include <Servo.h>
#include <math.h>
#include "Definitions.h"
#include "Movement.h"
#include "Arduino.h"
#include "Servo.h"

//create construct

//Attach servos
Servo Move::wheel_right;
Servo Move::wheel_left;
Servo Move::head;

//Create int
int Move::LEstatus;
int Move::state1, Move::state2;
int Move::i = 0;
float Move::distance = 0;



void Move::drive(float amount){    //amount = the amount of rotations of the wheels

   //enable encoders
  pinMode(pin_encoder_left, INPUT);
  pinMode(pin_encoder_right, INPUT);
  Serial.begin(9600);
  
  //define variables
  int count1 = 0;
  int count2 = 0;
  int prev_value1 = digitalRead(pin_encoder_left);
  int prev_value2 = digitalRead(pin_encoder_right);
  int value_now1;
  int value_now2;
  float calculation1 = abs(round(amount*15));   //calculates the amount of value-changes
	
	//attach wheels
	wheel_left.attach(pin_wheel_left);
	wheel_right.attach(pin_wheel_right);
  	
  while((count1 < calculation1) and (count2 < calculation1)) {  
    value_now1 = digitalRead(7);
    value_now2 = digitalRead(8);
    if(amount >= 0) {
      wheel_left.write(1700);   //drive forwards
      wheel_right.write(1300);  //drive backwards
    }
    else {
      wheel_left.write(1300);
      wheel_right.write(1700);
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
  wheel_left.detach();
  wheel_right.detach();
}


void Move::turn(float Degrees){
  //enable encoders
  pinMode(pin_encoder_left, INPUT);
  pinMode(pin_encoder_right, INPUT);
  Serial.begin(9600);

  //define variables
  int count1 = 0;
  int count2 = 0;
  int prev_value1 = digitalRead(pin_encoder_left); // save the starting value
  int value_now1;
  int prev_value2 = digitalRead(pin_encoder_right); // save the starting value
  int value_now2;
  float d1 = (Degrees/360)*10*3.14;
  float calculation2 = abs(round((d1/20.73)*15));
 
  wheel_left.attach(pin_wheel_left);
  wheel_right.attach(pin_wheel_right);
  while((count1 < calculation2) and (count2 < calculation2)) {  //if one of the encoders counted the amount of value-changes requested, the turn stops 
      value_now1 = digitalRead(pin_encoder_left);
      value_now2 = digitalRead(pin_encoder_right);
      if(Degrees >= 0) {  //turns to the right
        wheel_left.write(1700);
        wheel_right.write(1700);
      }
      else {              //turns to the left
        wheel_left.write(1300);
        wheel_right.write(1300);
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
  wheel_left.detach();
  wheel_right.detach();
}

void Move::head(int angle)	//forward is 90 degree angle, range is from 0 -> 180
{
	//attach servo
	head.attach(pin_servo_head);
	
	// move the head
	head.write(angle);
	
	// disengage
	head.detach();
}

void Move::stop()
{
	//detach servo
	wheel_left.detach();
  	wheel_right.detach();
}
