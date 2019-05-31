#include "Definitions_move.h"
#include "Movement.h"
#include <Servo.h>
#include "Grabber.h"

//DEFINE
//define grabber
Grabber myGrabber;
int back_at_lab=1;

//define movement
Move movement;

void setup() {
}

void loop() {
  
  if (back_at_lab==1 & myGrabber.status==0){
    movement.drive(1);
    myGrabber.open();  
    movement.drive(-1);
 }

}
