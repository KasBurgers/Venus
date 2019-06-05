#ifndef Move_h
#define Move_h
#include "Definitions_move.h"
#include "Servo.h"



class Move{
	public:
		static void turn(float amount);
		static void drive(float amount);
		static void head(int angle);
		static void stop_drive();
		static void drive_c();
		static int headStatus();

	private:
		static Servo wheel_right;
		static Servo wheel_left;
		static Servo Head;
    static int rotation;
		static int LEstatus;
		static int state1, state2;
		static int i;
		static float distance;
		static int headAngle;
		
		
};
#endif
