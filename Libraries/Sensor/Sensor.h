#ifndef Sensor_h
#define Sensor_h
#include "Definitions.h"

class Sensor{
	public:
		int ultrasound();
		bool ir_ground();
	private:
		int ir_voltage(int pin);
};

#endif
