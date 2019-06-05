#include "Definitions_sensor.h"
#include "Sensors.h"
#include "Movement.h"

Move move_t;
Sensors sensor_t;
int z;


void setup() {

Serial.begin(9600);
}

void loop() {


if(sensor_t.ir_trunk()==true){
  move_t.drive_c();
  delay(500);
  move_t.stop_drive();
}

//z=sensor_t.ir_voltage(pin_ir_trunk);
//Serial.println(z);
}
