#include "Definitions_move.h"
#include "Movement.h"
#include <Servo.h>
#include "Grabber.h"
#include "Sensors.h"

//DEFINE
//define grabber
Grabber myGrabber;
int back_at_lab=1;

//define movement
Move movement;
int headStatus = 90;
int turn = 0;
int i=0;
int leftcorner;
int rightcorner;

Sensors mySensor;

void setup() {
  Serial.begin(9600);

}

void loop() {

Serial.println("Stop");
movement.stop_drive();
Serial.println("check");
checking();
Serial.println("wait");
delay(10000);

}
void checking() {
Serial.println("start checking");
i=0;
movement.head(i);
while(i<=180){
  movement.head(i);
  headStatus=i;
  i=i+5;
  delay(100);
  bool irSensor = mySensor.ir_trunk();
  delay(100);
  if(irSensor==1){
    Serial.print("run detected method");
    
      while(i<=200){
      movement.head(headStatus);
      i=i+1;
      movement.head(i);
      delay(100);
      bool irSensor = mySensor.ir_trunk();
      delay(100);
      if(irSensor==0){
        leftcorner = i;
        while(i<=200){
           i=i-1;
           movement.head(i);
           delay(100);
           bool irSensor = mySensor.ir_trunk();
           delay(100);
           if(irSensor==0){
           rightcorner = i;
           break;
           }
        }
        break;
      }
   }
    headStatus=(leftcorner+rightcorner)/2;
    delay(200);
    sampleDetected(); 
    delay(1000);
    break;    
}
}
movement.head(90);

delay(200);

}

void sampleDetected(){
  Serial.println("start detect");
  movement.stop_drive();
  myGrabber.close();
  delay(1000);
  
  if (headStatus >= 90){ // its needed to turn left
    int turn = -(headStatus-90);  // a negative movement.turn() will cause the robot to turn left
    delay(200);
    movement.head(0);
    delay(200);
    Serial.println("left");
    Serial.println(turn);
    movement.turn(turn);
    delay(200);
    movement.drive(0.6);
    delay(200);
    myGrabber.open();
    delay(200);
    movement.drive(-0.6);
    delay(200);
    movement.turn(-turn);
    delay(200);
    Serial.println(-turn);
    delay(200);
    movement.head(90);
  }
    
  else {  //its needed to turn right
  int turn = (90-headStatus);  // a positve movement.turn() will cause the robot to right left
    delay(200);
    movement.head(179);
    delay(200);
    Serial.println("right");
    Serial.println(turn);
    movement.turn(turn);
    delay(200);
    movement.drive(0.6);
    delay(200);
    myGrabber.open();
    delay(200);
    movement.drive(-0.6);
    delay(200);
    movement.turn(-turn);
    delay(200);
    Serial.println(-turn);
    delay(200);
    movement.head(90);
  }
  }

 void returnToBase(){ // we first need the grid system and the variables which indicate the base
    return 0; 
  }
  
    
