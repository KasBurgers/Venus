/*scan for mountain
if (no mountain) {
	drive forward one grid
	while driving keep scanning for black lines or cliff
}
if (mountain) {
	drive a bit back (n grids)
	look left and right
	decide to go left or right
	turn 90 degrees
	drive forward
	remember square with mountain
}




robot drives continuously
	counts squares passed
when it notices a line or mountain, drive back to the last square and turn 90 degrees to the left or right (after checking?)
	add count of squares driven in one direction and add it to an array
		coded like: int of 3 digits:
			first digit is direction (1=N, 2=E, 3=S, 4=W)
			two other digits are the square count
			example: 404 = 4 squares west		212 = 12 squares east
	this array can be used to find its way back

example:
[304; 211; 307; 410] = array searching
[210; 107; 411; 104] = array back to lab

square size is 28 cm, so this results in 28/20.73=1.35 full wheel rotations to drive one square

*/

//since north is towards the lab, the robot needs to turn first
turn(180);		//dir=3

while (no_mountain == true) {
	drive(1.35);	//drive one square
	squareCount++;
}




//count function
int count1 = 0;
int count2 = 0;
int prev_value1 = digitalRead(pin_encoder_left);
int prev_value2 = digitalRead(pin_encoder_right);
int value_now1;
int value_now2;

if (value_now1 != prev_value1) {
    count1++;
    prev_value1 = value_now1;
}
if (value_now2 != prev_value2) {
	count2++;
    prev_value2 = value_now2;
}
if ((count1 == 20) and (count2 == 20)) {
	squareCount++;
	count1=0;
	count2=0;
}
if (mountain=true) or (line=true) {
	return squareCount;
}




//coordinate system
int coor[] = {0,0};
float degrees;
int dir;
int value_now1;
int value_now2;
int count1 = 0;
int count2 = 0;

drive_c();
void loop() {
	int prev_value1 = digitalRead(pin_encoder_left);
	int prev_value2 = digitalRead(pin_encoder_right);

	if (value_now1 != prev_value1) {
	    count1++;
	    prev_value1 = value_now1;
	}
	if (value_now2 != prev_value2) {
		count2++;
	    prev_value2 = value_now2;
	}
	if ((count1 == 20) and (count2 == 20)) {
		squareCount++;
		count1=0;
		count2=0;
	}




	if (mountain=true) or (line=true) {
		return squareCount;
	}

	if ((mountain=true) or (line=true)) {
		stop_drive();	
		turn(degrees);
		int DegreesINT = (int) degrees;
		dir = dir + DegreesINT;
		if (dir >= 360) {
	  		dir = dir%360;
		}
		else if (dir <= -360) {
	  		dir = dir%(-360);
		}

		if (dir=0) {
			steps = count();
			coor[1] += steps;
		}
		if (dir=90) {
			steps = count();
			coor[0] += steps;
		}
		if (dir=180) {
			steps = count();
			coor[1] -= steps;
		}
		if (dir=270) {
			steps = count();
			coor[0] -= steps;
		}
	}
}





//code to determine direction
int dir = 0;
float degrees;	//90=right, -90=left
turn(degrees);
int DegreesINT = (int) degrees;
dir = dir + DegreesINT;
if (dir >= 360) {
		dir = dir%360;
}
else if (dir <= -360) {
		dir = dir%(-360);
}

//code to determine its own location
int coor[] = {0,0};
int value_now1;
int value_now2;
int count1 = 0;
int count2 = 0;
int prev_value1 = digitalRead(pin_encoder_left);
int prev_value2 = digitalRead(pin_encoder_right);

if (value_now1 != prev_value1) {
    count1++;
    prev_value1 = value_now1;
}
if (value_now2 != prev_value2) {
	count2++;
    prev_value2 = value_now2;
}
if ((count1 == 20) and (count2 == 20)) {
	if (dir=0) {	//north
		coor[1] += steps;
	}
	if (dir=90) {	//east
		coor[0] += steps;
	}
	if (dir=180) {	//south
		coor[1] -= steps;
	}
	if (dir=270) {	//west
		coor[0] -= steps;
	}
	count1=0;
	count2=0;
}







//-----------------------------------------------------------------//
//making of route back to lab
//-----------------------------------------------------------------//

/*
steps:
1)	drive x to 0
	- blocked or x = 0? go to step 2 if y != 0
		- blocked again? turn again and turn back when possible to perform step 2
2)	drive y to 0
	- blocked or y=0? go to step 1 if x != 0
		- blocked again? turn again and turn back when possible to perform step 1
*/

int x_start = coor[0];
int y_start = coor[1];
int tempx = x_start;	//virtual x-coor
int tempy = y_start;	//virtual y-coor
bool focusY = false;
int block = 0;


if (focusY == false) {
	if (x_start > 0) {
		//coor[2] needs to be 270
		for (int i = 0; i < 100; i++) {
			if ((tempx-i,tempy) is in array 'obstacles') or (tempx-i == 0) {
				focusY = true;
				if (block == 2) {
					do the 'blocked again' action
					block = 0;
				}
				block = 1;
				break; //go to code to focus on y to 0
			}
			else {
				add (tempx-i,tempy) to array 'route';
				tempx = tempx-i;
				block = 0;
			}
		}
	}
	else if (x_start < 0) {
		//coor[2] needs to be 90
		for (int i = 0; i < 100; i++) {
			if ((tempx+i,tempy) is in array 'obstacles') or (tempx+i == 0) {
				focusY = true;
				if (block == 2) {
					//do the 'blocked again' action
					block = 0;
				}
				block = 1;
				break; //go to code to focus on y to 0
			}
			else {
				add (tempx+i,tempy) to array 'route';
				tempx = tempx+i;
				block = 0;
			}
		}
	}
	else if (x_start == 0) {
		if (y_start == 0) {
			//at the lab, so coor[2] needs to be 0
		}
		else {
			//coor[2] needs to be based on y_start
			focusY = true;
		}
	}
}

if (focusY == true) {
	if (y_start > 0) {
		//coor[2] needs to be 180
		for (int i = 0; i < 100; i++) {
			if ((tempx,tempy-i) is in array 'obstacles') or (tempy-i == 0) {
				focusY = false;
				if (block == 2) {
					//do the 'blocked again' action
					block = 0;
				}
				block = 1;
				break; //go to code to focus on y to 0
			}
			else {
				add (tempx,tempy-i) to array 'route';
				tempy = tempy-i;
				block = 0;
			}
		}
	}
	else if (y_start < 0) {
		//coor[2] needs to be 0
		for (int i = 0; i < 100; i++) {
			if ((tempx,tempy+i) is in array 'obstacles') or (tempy+i == 0) {
				focusY = false;
				if (block == 2) {
					//do the 'blocked again' action
					block = 0;
				}
				block = 1;
				break; //go to code to focus on y to 0
			}
			else {
				add (tempx,tempy+i) to array 'route';
				tempy = tempy+i;
				block = 0;
			}
		}
	}
}

/*
else if (y_start == 0) {
	if (x_start == 0) {
		//at the lab, so coor[2] needs to be 0
	}
	//coor[2] needs to be based on x_start
}
*/