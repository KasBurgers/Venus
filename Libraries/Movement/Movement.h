#ifndef Move_h
#define Move_h
#include "Definitions.h"



class Move{
	public:
		void turn(float amount);
		void drive(float amount);
		void head(int angle);
		void stop_drive();
		void drive_c();

	private:
		static Servo wheel_right;
		static Servo wheel_left;
		static Servo Head;
		static int LEstatus;
		static int state1, state2;
		static int i;
		static float distance;
		
		
};
#endif
