/*
  Grabber.cpp
  Kas Burgers
*/
#include "Arduino.h"
#include "Grabber.h"
#include <Servo.h>


Servo Grabber::grabberServo;


void Grabber::open()
{
    grabberServo.attach(10);
    grabberServo.write(0);   // Rotate Gribber up
 
}

void Grabber::close()
{
    grabberServo.attach(10);
    grabberServo.write(180);   // Rotate Gribber down
  }

int Grabber::status()
{
  
 if (grabberServo.read()==0){
  return 1;
 }
 else {return 0;}
}
