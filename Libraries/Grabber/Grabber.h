/*
    Grabber method 
    Kas Burgers
*/

#ifndef Grabber_h
#define Grabber_h
#include <Servo.h>
class Grabber
{
  public:
    static void open();
    static void close();
    static int status();
  private:
    static Servo grabberServo;
};

#endif
