#include "Definitions_sensor.h"
#include "Sensors.h"
#include "Arduino.h"

// create construct
int Sensors::ultrasoundReturn;
static int Sensors::voltage_ir;

int Sensors::ultrasound() 		// send ultrasound chirp & receive too (copied from Dwahni (20 May)
{
	// define variable
	unsigned int T;
	
	pinMode(pin_ultrasound, OUTPUT);	 //Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
	digitalWrite(pin_ultrasound, LOW);
	delayMicroseconds(2); //!!!!!!!!!!!!!!!!!!!!! we need to find another way for the delay function

	digitalWrite(pin_ultrasound, HIGH);  // The PING is triggered by a HIGH pulse of 2 or more microseconds.
	delayMicroseconds(5); 				// See above for delay function
	digitalWrite(pin_ultrasound, LOW);

	pinMode(pin_ultrasound, INPUT);            // The same pin is used to read the signal from the PING))): a HIGH pulse whose duration is the time (in microseconds)
	T = pulseIn(pin_ultrasound, HIGH);

	Sensors::ultrasoundReturn = ( T / 29 / 2 );		// conversion of ms to cm is ' /29 /2 '
  return(Sensors::ultrasoundReturn);
}

// IR functions copied on 20 May

int Sensors::ir_voltage(int pin)
{
	// activate pin
	pinMode(pin, INPUT);

  //define constants
  int VOLTAGE_MAX = 5000;
  int VOLTAGE_STEP = VOLTAGE_MAX/1024;

  //return
  return( analogRead(pin) * VOLTAGE_STEP );
	
	
}


bool Sensors::ir_ground() // returns TRUE for black ground 
{
	//define black level
	int black_max = 600; 
  if (Sensors::ir_voltage(pin_ir_ground_1) < black_max or Sensors::ir_voltage(pin_ir_ground_2) < black_max){
    return true;
  }
  else{
    return false;
  }
}


	
	
	
