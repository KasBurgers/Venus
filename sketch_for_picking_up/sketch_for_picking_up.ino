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
int headStatus = 0;
int turn = 0;

Sensors mySensor;

void setup() {
}

void loop() {
delay(5000);
sampleDetected(); 

}

void sampleDetected(){
  movement.stop_drive();
  headStatus = movement.headStatus;
  myGrabber.open();
  delay(1000);
  if (headStatus <= 90){ // its needed to turn left
    int turn = -(90-headStatus);  // a negative movement.turn() will cause the robot to turn left
    movement.turn(turn);
    movement.drive(1);
    myGrabber.close();
    movement.drive(-1);
    movement.turn(-turn);
  }
    
  else {  //its needed to turn right
  int turn = (headStatus-90);  // a positve movement.turn() will cause the robot to right left
    movement.turn(turn);
    movement.drive(1);
    myGrabber.close();
    movement.drive(-1);
    movement.turn(-turn);
  }
  }

 void returnToBase(){ // we first need the grid system and the variables which indicate the base
    return 0; 
  }
  
    
