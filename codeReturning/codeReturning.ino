#include <Movement.h>;

/*-------------------------------comments----------------------------------
*function 'drive': in this function searching for lines should be built in
 - if it returns true if a border is found, it can be used to determine focusY
 - when a border is found, it should drive back to its starting position (position where it got the command to drive)
 	- still needs to be made into the code
*var mountain: this needs to be true or false -> true=mountain between 12 and 40 cm, else=false
*is it necessary to include variables when calling Xblocked or Yblocked?
*when the quadrant of the robot is completely blocked towards the lab, the robot fails and gets stuck.

for Mark:
this code works in almost all situations (one kind of situation has no possible way to go to the lab). the var mountain still needs to be made, but I don't 
know how to include the libraries properly. the functions Xblocked and Yblocked maybe should be placed in the main code as well, because it uses a lot of variables
of the main code. the function direction can be placed in the library (I think). If you have any questions about the code, ask me.

*mountain function should be checked if the distance is correct
*if the code is fully integrated to the library, we can test it

used functions:
 - drive()
 - turn()
 - 
---------------------------------------------------------------------------*/
/*int coor[] = {0, 0, 0};	//{x, y, dir}
bool focusY = false;
int Xcoor = coor[0];
int Ycoor = coor[1];
int dir;
int blockedStatus = 0;
int blockedTurn;

void setup() {
	dir = direction(Xcoor, Ycoor, false);	
	Move::turn(dir-coor[2]);
	coor[2] = dir;
}

void loop() {
	if (focusY == false) {
		if (Xcoor > 0) {
			if (mountain() == true) {
				Xblocked();
			}
			else {
				Move::drive(1.35);	//in this function the searching for lines also needs to be implemented
				blockedStatus = 0;
				Xcoor--;
			}
		}
		else if (Xcoor < 0) {
			if (mountain() == true) {
				Xblocked();
			}
			else {
				Move::drive(1.35);
				blockedStatus = 0;
				Xcoor++;
			}
		}
		else if (Xcoor == 0) {
			if (Ycoor == 0) {
				//at the lab
				dir=0;
				Move::turn(dir-coor[2]);
				coor[2] = dir;
				//done
			}
			else {
				Xblocked();
				blockedStatus = 0;	//this will make sure the zero line won't look like a mountain or a black line.
			}
		}
	}


	else {	//focusY == true
		if (Ycoor > 0) {
			if (mountain() == true) {
				Yblocked();
			}
			else {
				Move::drive(1.35);
				blockedStatus = 0;
				Ycoor--;
			}
		}
		else if (Ycoor < 0) {
			if (mountain() == true) {
				Yblocked();
			}
			else {
				Move::drive(1.35);
				blockedStatus = 0;
				Ycoor++;
			}
		}
		else if (Ycoor == 0) {
			if (Xcoor == 0) {
				//at the lab
				dir=0;
				Move::turn(dir-coor[2]);
				coor[2] = dir;
				//done
			}
			else {
				Yblocked();
				blockedStatus = 0;
			}
		}
	}
}


void Xblocked() {
	switch (blockedStatus) {
	    case 0:		//first time blocked;
	    	focusY = true;
	    	blockedStatus++;
	    	dir = direction(Xcoor, Ycoor, focusY);
	    	blockedTurn = dir-coor[2];
	    	Move::turn(blockedTurn);
	    	coor[2] = dir;
	    	break;
	    case 1:		//second time blocked
		    blockedStatus++;
		    Move::turn(blockedTurn);
		    
	    	while (case2 == true) {
	    		Move::drive(1.35);
	    		Move::turn(-blockedTurn);
	    		if (mountain() == true) {
	    			Move::turn(blockedTurn);
	    		}
	    		else {
	    			case2 = false;
	    		}
	    	}
	    	break;
	    default:
	     	break;
	}
	
}

void Yblocked() {
	switch (blockedStatus) {
	    case 0:		//first time blocked;
	    	focusY=false;
	    	blockedStatus++;
	    	dir = direction(Xcoor, Ycoor, focusY);
	    	blockedTurn = dir-coor[2];
	    	Move::turn(blockedTurn);
	    	coor[2] = dir;
	    	break;
	    case 1:		//second time blocked
		    turn(blockedTurn);
		    
	    	while (case2 == true) {
	    		Move::drive(1.35);
	    		Move::turn(-blockedTurn);
	    		if (mountain() == true) {
	    			Move::turn(blockedTurn);
	    		}
	    		else {
	    			case2 = false;
	    		}
	    	}
		    blockedStatus--;
	    	break;
	    default:
	     	break;
	}
}

int direction(int Xcoor, int Ycoor, bool focusY) {
	int dirX;
	int dirY;
	int randm;
	if (Xcoor > 0) {
		dirX = 270;
	}
	else if (Xcoor < 0) {
		dirX = 90;
	}
	else if (Xcoor == 0) {
		randm = random(0,2);
		if (randm == 0) {
			dirX = 270;
		}
		else {
			dirX = 90;
		}
	}

	if (Ycoor > 0) {
		dirY = 180;
	}
	else if (Ycoor < 0) {
		dirY = 0;
	}
	else if (Ycoor == 0) {
		randm = random(0,2);
		if (randm == 0) {
			dirY = 0;
		}
		else {
			dirY = 180;
		}
	}

	if (focusY == true) {
		return dirY;
	}
	else {
		return dirX;
	}
}

bool mountain() {
	int mountainDistance = ultrasound();
	if (mountainDistance < 40) {
		return true;
	}
	else {
		return false;
	}
}*/




//-----------------------------------------------------------------------------------------------------------------------------------------------//





//Version 2 with the improved drive function:
int coor[] = {0, 0, 0};	//{x, y, dir}
bool focusY = false;
int Xcoor = coor[0];
int Ycoor = coor[1];
int dir;
int blockedStatus = 0;
int blockedTurn;
bool driveReturn = false;
bool case2 = true;

void setup() {
	dir = direction1(Xcoor, Ycoor, false);	
	Move::turn(dir-coor[2]);
	coor[2] = dir;
}

void loop() {
	if (focusY == false) {
		if (Xcoor > 0) {
			if (mountain() == true) {
				Xblocked();
			}
			else {
				driveReturn = Move::drive_new(1.35);
				if (driveReturn == true) {
					Xblocked();
				}
				else {
					blockedStatus = 0;
					Xcoor--;
				}
			}
		}
		else if (Xcoor < 0) {
			if (mountain() == true) {
				Xblocked();
			}
			else {
				driveReturn = Move::drive_new(1.35);
				if (driveReturn == true) {
					Xblocked();
				}
				else {
					blockedStatus = 0;
					Xcoor++;
				}
			}
		}
		else if (Xcoor == 0) {
			if (Ycoor == 0) {
				//at the lab
				dir=0;
				Move::turn(dir-coor[2]);
				coor[2] = dir;
				//done
			}
			else {
				Xblocked();
				blockedStatus = 0;	//this will make sure the zero line won't look like a mountain or a black line.
			}
		}
	}


	else {	//focusY == true
		if (Ycoor > 0) {
			if (mountain() == true) {
				Yblocked();
			}
			else {
				driveReturn = Move::drive_new(1.35);
				if (driveReturn == true) {
					Yblocked();
				}
				else {
					blockedStatus = 0;
					Ycoor--;
				}
			}
		}
		else if (Ycoor < 0) {
			if (mountain() == true) {
				Yblocked();
			}
			else {
				driveReturn = Move::drive_new(1.35);
				if (driveReturn == true) {
					Yblocked();
				}
				else {
					blockedStatus = 0;
					Ycoor++;
				}
			}
		}
		else if (Ycoor == 0) {
			if (Xcoor == 0) {
				//at the lab
				dir=0;
				Move::turn(dir-coor[2]);
				coor[2] = dir;
				//done
			}
			else {
				Yblocked();
				blockedStatus = 0;	//this will make sure the zero line won't look like a mountain or a black line.
			}
		}
	}
}


void Xblocked() {
	bool case2 = true;
	//vars: blockedStatus (return), focusY, Xcoor/Ycoor/coor[2], blockedTurn
	switch (blockedStatus) {
	    case 0:		//first time blocked;
	    	focusY = true;
	    	blockedStatus++;
	    	dir = direction1(Xcoor, Ycoor, focusY);
	    	blockedTurn = dir-coor[2];
	    	Move::turn(blockedTurn);
	    	coor[2] = dir;
	    	break;
	    case 1:		//second time blocked
		    blockedStatus++;
		    Move::turn(blockedTurn);
		    
	    	while (case2 == true) {
	    		Move::drive(1.35);
	    		Move::turn(-blockedTurn);
	    		if (mountain() == true) {
	    			Move::turn(blockedTurn);
	    		}
	    		else {
	    			case2 = false;
	    		}
	    	}
	    	break;
	    default:
	     	break;
	}
	
}

void Yblocked() {
	switch (blockedStatus) {
	    case 0:		//first time blocked;
	    	focusY=false;
	    	blockedStatus++;
	    	dir = direction1(Xcoor, Ycoor, focusY);
	    	blockedTurn = dir-coor[2];
	    	Move::turn(blockedTurn);
	    	coor[2] = dir;
	    	break;
	    case 1:		//second time blocked
		    Move::turn(blockedTurn);
		    
	    	while (case2 == true) {
	    		Move::drive(1.35);
	    		Move::turn(-blockedTurn);
	    		if (mountain() == true) {
	    			Move::turn(blockedTurn);
	    		}
	    		else {
	    			case2 = false;
	    		}
	    	}
		    blockedStatus--;
	    	break;
	    default:
	     	break;
	}
}

int direction1(int Xcoor, int Ycoor, bool focusY) {
	int dirX;
	int dirY;
	if (Xcoor > 0) {
		dirX = 270;
	}
	else if (Xcoor < 0) {
		dirX = 90;
	}
	else if (Xcoor == 0) {
		int randm = random(0,2);
		if (randm == 0) {
			dirX = 270;
		}
		else {
			dirX = 90;
		}
	}

	if (Ycoor > 0) {
		dirY = 180;
	}
	else if (Ycoor < 0) {
		dirY = 0;
	}
	else if (Ycoor == 0) {
		int randm = random(0,2);
		if (randm == 0) {
			dirY = 0;
		}
		else {
			dirY = 180;
		}
	}

	if (focusY == true) {
		return dirY;
	}
	else {
		return dirX;
	}
}

bool mountain() {
	#include <Sensors.h>;

	int mountainDistance = Sensors::ultrasound();
	if (mountainDistance < 40) {
		return true;
	}
	else {
		return false;
	}
}
