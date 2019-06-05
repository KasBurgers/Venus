#include "Definitions_move.h"
#include "Movement.h"
#include <Servo.h>
#include "Grabber.h"

//DEFINE
//define grabber
Grabber myGrabber;
int back_at_lab=1;
float d=3.6;

//define movement
Move movement;


void setup() {
//myGrabber.close();
delay(1000);
int z=myGrabber.status();
}

void loop() {

  //testing code
  myGrabber.close();
  delay(1000); 
  int z=myGrabber.status();

   //loop itself
  if (back_at_lab==1 & z==0){
    movement.drive(d);
    myGrabber.open(); 
    delay(1000); 
    myGrabber.close();
    delay(1000);
    movement.drive(-d);
    back_at_lab=0;
    
 }

}
