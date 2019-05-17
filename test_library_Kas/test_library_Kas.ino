//#include <Servo.h>
#include <Grabber.h>

Grabber grabber();

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  Grabber::open();
  delay(5000);
  Grabber::close();
  delay(5000);
}
