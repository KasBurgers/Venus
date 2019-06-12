#include "Definitions_move.h"
#include "Movement.h"
#include <Servo.h>
#include "Grabber.h"
#include "Sensors.h"
bool ir_left = false;
bool ir_right = false;
bool z;
bool cond=false;
//DEFINE

//define grabber
Grabber myGrabber;
int back_at_lab=1;
float d_ramp=3.6;
float d_on_ramp=0.5;
float dist=0;

//define movement
Move movement;


//testing setup
void setup() {
//myGrabber.close();
Serial.begin(9600);
delay(1000);
int z=myGrabber.status();
}

//LOOP
void loop() {
    
    
    int z=myGrabber.status();
   
   //loop itself
  if (back_at_lab==1 & z==0){ //back_at_lab condition should be taken from mapping code
    
    //testing code
    myGrabber.close();
    float d_droven=0;
  
    //define ir sensors
    ir_left = Sensors::ir_ground_left();
    ir_right = Sensors::ir_ground_right();
        
    //now testing that it is alligned with blacked lines
    while (dist<(d_ramp*1.2)){
          
          ir_left = Sensors::ir_ground_left();
          ir_right = Sensors::ir_ground_right();

          movement.drive(0.04);
          dist=dist+0.04;
          
          if (ir_left==true & ir_right==false){
            movement.stop_drive();
            movement.turn(20);
            //delay(500);
            }
                   
          if (ir_left==false & ir_right==true){
            movement.stop_drive();
            movement.turn(-20);
            //delay(500);
            }
          
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
