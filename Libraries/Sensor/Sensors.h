#ifndef Sensors_h
#define Sensors_h
#include "Definitions.h"

class Sensors{
	public:
		static int ultrasound();
		bool ir_ground();
    static int ultrasoundReturn;
	private:
		int ir_voltage(int pin);
};

#endif
