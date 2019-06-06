#include <Servo.h>
#include <Sensors.h>
#include <Movement.h>
bool ir_left = false;
bool ir_right = false;
int rotation = 0;

void setup() {
  Serial.begin(9600);
  Move::stop_drive();
  Move::head(90);
  Move::drive_c();

}

void loop() {
  ir_left = Sensors::ir_ground_left();
  ir_right = Sensors::ir_ground_right();
  
  if(ir_left == true & ir_right == true){
    Move::stop_drive();
    Move::drive(-1);
    rotation = Move::turn(90);
    rotation = rotation + 90;
    //save to memory
    Move::drive_c();
  }
  if(ir_left == true & ir_right == false){
    Move::stop_drive();
    rotation = Move::turn(45);
    rotation = rotation + 45;
    //save to memory
    Move::drive_c();
  }
    if(ir_right == true & ir_left == false){
    Move::stop_drive();
    rotation = Move::turn(-45);
    rotation = rotation - 45; 
    //save to memory
    Move::drive_c();
  }

}