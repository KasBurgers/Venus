#ifndef Sensors_h
#define Sensors_h
#include "Definitions_sensor.h"

class Sensors{
	public:
		static int ultrasound();
		static bool ir_ground();
    static int ultrasoundReturn;
    static bool ir_groundReturn;
	private:
		static int ir_voltage(int pin);
    static int voltage_ir;
};

#endif
