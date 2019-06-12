#include "Definitions_sensor.h"
#include "Sensors.h"
//#include "Movement.h"

//Move move_t;
Sensors sensor_t;
int z;


void setup() {

Move::stop_drive();
Move::drive_c();

}

void loop() {

  if(ir_left == true & ir_right == false){
    Move::stop_drive();
    Move::turn(25);
    rotation = rotation + 45;
    //save to memory
    Move::drive_c();
  }
}
