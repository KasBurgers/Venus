#include <Servo.h>
#include <Sensors.h>
#include <Movement.h>

void setup() {
 Serial.begin(9600);
 
 Move::drive_c();
 delay(4000);
 Move::stop_drive();
}

void loop() {
//  head(180);
}
