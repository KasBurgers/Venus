#include "Definitions.h"
#include "Sensor.h"
#include "Arduino.h"

// create construct

int Sensor::ultrasound() 		// send ultrasound chirp & receive too (copied from Dwahni (20 May)
{
	// define variable
	unsigned int T;
	
	pinmode(pin_ultrasound, OUTPUT);	 //Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
	digitalWrite(pin_ultrasound, LOW);
	delayMicroseconds(2); //!!!!!!!!!!!!!!!!!!!!! we need to find another way for the delay function

	digitalWrite(pin_ultrasound, HIGH);  // The PING is triggered by a HIGH pulse of 2 or more microseconds.
	delayMicroseconds(5); 				// See above for delay function
	digitalWrite(pin_ultrasound, LOW);

	pinMode(pin_ultrasound, INPUT);            // The same pin is used to read the signal from the PING))): a HIGH pulse whose duration is the time (in microseconds)
	T = pulseIn(pin_ultrasound, HIGH);

	return( T / 29 / 2 );		// conversion of ms to cm is ' /29 /2 '
}

// IR functions copied on 20 May

int Sensor::ir_voltage(int pin)
{
	// define constants
	int VOLTAGE_MAX = 5000;
	int VOLTAGE_STEP = VOLTAGE_MAX/1024;
	
	return( analogRead(pin) * VOLTAGE_STEP );
}


bool Sensor::ir_ground() // returns TRUE for black ground 
{
	int black_max = 600 // under this value the ground is percieved black
	
	if(Sensor::ir_voltage(pin_IR_ground) < black_max){
		return TRUE;
	}
	else{
		return FALSE;
	}
}


	
	
	