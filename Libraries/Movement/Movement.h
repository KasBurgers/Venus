#ifndef Move_h
#define Move_h
#include "Definitions.h"

class Move{
	public:
		void turn(float amount);
		void drive(float amount);
		void head(int angle);
		void stop_d();

	private:
		static Servo wheel_right;
		static Servo wheel_left;
		static Servo head_s;
		static int rotation;
		static int i;
		static float distance;
		
		
};
#endif
