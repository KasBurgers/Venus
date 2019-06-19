int coor[] = {0, 0, 0};	//{Xcoor, Ycoor, dir}
dir = coor[2];
bool blackLine = false;
//int degrees;

void setup()
{
	
}
void loop()
{
  
}

void checkOrientation()
{
	blackLine = move::new_drive(1.35);
	if (blackLine == true) {
		Move::turn(90);
		dir = dir + 90;
		if (dir >= 360) {
	  		dir = dir%360;
		}
		else if (dir < 0) {
	  		dir = dir%360;
		}
		coor[2] = dir;
	}
	else {
		switch (dir) {
		    case 0:
		      coor[1]++;
		      break;
		    case 90:
		      coor[0]++;
		      break;
		    case 180:
		      coor[1]--;
		      break;
		    case 270:
		      coor[0]--;
		      break;
		    default:
		      break;
		}
	}


	/*//if a turn is done:
	turn(degrees);
	int DegreesINT = (int) degrees;
	dir = dir + DegreesINT;
	if (dir >= 360) {
  		dir = dir%360;
	}
	else if (dir < 0) {
  		dir = dir%360;
	}
	coor[2] = dir;*/
}












//---------------------------------------------------------------------------------//
//new drive function:

bool Move::drive(float amount){    //amount = the amount of rotations of the wheels

   //enable encoders
  pinMode(pin_encoder_left, INPUT);
  pinMode(pin_encoder_right, INPUT);
  Serial.begin(9600);
  
  //define variables
  int count1 = 0;
  int count2 = 0;
  int prev_value1 = digitalRead(pin_encoder_left);
  int prev_value2 = digitalRead(pin_encoder_right);
  int value_now1;
  int value_now2;
  float calculation1 = abs(round(amount*15));   //calculates the amount of value-changes
  bool blackLine = false;  //only new variable
	
	//attach wheels
	wheel_left.attach(pin_wheel_left);
	wheel_right.attach(pin_wheel_right);
  	
  while((count1 < calculation1) and (count2 < calculation1)) {  
    if ((ir_ground_left() == true) or (ir_ground_right() == true)) {  //library used
      while(count1 != 0) and (count2 != 0) {
        value_now1 = digitalRead(7);
        value_now2 = digitalRead(8);
        if(amount >= 0) {
          wheel_left.write(1300);   //drive backwards
          wheel_right.write(1700);  //drive forwards
        }
        else {
          wheel_left.write(1700);
          wheel_right.write(1300);
        }
        if (value_now1 != prev_value1) {
          count1--;
          prev_value1 = value_now1;
        }
        if (value_now2 != prev_value2) {
          count2--;
          prev_value2 = value_now2;
        }
      }
      wheel_left.detach();
      wheel_right.detach();
      blackLine = true;
      break;
    }

    value_now1 = digitalRead(7);
    value_now2 = digitalRead(8);
    if(amount >= 0) {
      wheel_left.write(1700);   //drive forwards
      wheel_right.write(1300);  //drive backwards
    }
    else {
      wheel_left.write(1300);
      wheel_right.write(1700);
    }
    if (value_now1 != prev_value1) {
      count1++;
      prev_value1 = value_now1;
    }
    if (value_now2 != prev_value2) {
      count2++;
      prev_value2 = value_now2;
    }
  }

  wheel_left.detach();
  wheel_right.detach();

  return blackLine;
}
