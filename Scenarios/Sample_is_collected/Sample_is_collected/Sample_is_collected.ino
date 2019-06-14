#include "Definitions_move.h"
#include "Movement.h"
#include <Servo.h>
#include "Grabber.h"
#include "Sensors.h"

//testing setup
void setup() {
Serial.begin(9600);
delay(1000);
}

void loop(){

drop_sample();

}
//LOOP
void drop_sample() {
    
    //DEFINE
    
    //define objects
    Move movement;
    Grabber myGrabber;
    
    //define variables
    bool ir_left = false;
    bool ir_right = false;
    bool cond=false;
    int back_at_lab=1;
    float d_ramp=3.7;
    float d_on_ramp=0.5;
    float dist=0;
    float d_droven=0;
    bool z=myGrabber.status();
   
   //loop itself
  if (back_at_lab==1 & z==0){ //back_at_lab condition should be taken from mapping code
    
    //testing code
    myGrabber.close();
  
    //define ir sensors
    ir_left = Sensors::ir_ground_left();
    ir_right = Sensors::ir_ground_right();
        
    //now testing that it is alligned with blacked lines
    while (dist<(d_ramp*1.2)){
          
          ir_left = Sensors::ir_ground_left();
          ir_right = Sensors::ir_ground_right();

          movement.drive(0.04);
          dist=dist+0.04;

          //turn left
          if (ir_left==true & ir_right==false){
            movement.stop_drive();
            movement.turn(20);
            //delay(500);
            }

          //turn right
          if (ir_left==false & ir_right==true){
            movement.stop_drive();
            movement.turn(-20);
            //delay(500);
            }

          //stop
          if (ir_left==true & ir_right==true){
            movement.stop_drive();
            cond=true;
          }
          
          //d_droven=d_droven+0.1;
    }
    myGrabber.open(); 
    delay(1000); 
    myGrabber.close();
    delay(1000);
    //movement.drive(-0.2);
    //movement.turn(200);
    movement.drive(-d_ramp);
    //movement.turn(200);
    back_at_lab=0;
    
    
 }

}
