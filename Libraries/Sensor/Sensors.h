#ifndef Sensors_h
#define Sensors_h
#include "Definitions_sensor.h"

class Sensors{
	public:
 //functions
	static int ultrasound();
	static bool ir_ground_left();
	static bool ir_ground_right();
  static bool ir_trunk();

  //variables
    static int ultrasoundReturn;
    //static bool ir_ground_return_left;
    //static bool ir_ground_return_right;
	private:
	static int ir_voltage(int pin);
    static int voltage_ir;
    static bool ir_trunk_return;
};

#endif
