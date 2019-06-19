#include "Sensors.h"
#include "Movement.h"
#include "Arduino.h"
#include "Map.h"

// create construct
int Map::Xcoordinate = 0;
int Map::Ycoordinate = 1;
int Map::directionInt = 2;
int Map::robotPosition[4] = {0,0,0};
int Map::obstacles[30][3];
int Map::labPosition[3] = {0,0};
int Map::returnDir = 0;
int Map::blockedStatus = 0;
bool Map::focusY = false;
int Map::blockedTurn = 0;

void Map::addObstacle(){ 
  
  // check if position is already in array
  for (int i = 0; i < 30; i++) {
    if (Map::obstacles[i] == NULL){ //if entry is NULL, the next will also be NULL since we only add to the end of the array
      break;
    }
    else{
      if (Map::obstacles[i][Map::Xcoordinate] == Map::robotPosition[Map::Xcoordinate] && Map::obstacles[i][Map::Ycoordinate] == Map::robotPosition[Map::Ycoordinate]){
		return;
      }
    }
  }
  // add current location to the end of the array, since the obstacle is virtually in the same gridspace as the robot most of the time
  for (int i = 0; i < 30; i++) {  // find first empty spot in array
    if (Map::obstacles[i] == NULL)  {
      Map::obstacles[i][Map::Xcoordinate] = Map::robotPosition[Map::Xcoordinate];
      Map::obstacles[i][Map::Ycoordinate] = Map::robotPosition[Map::Ycoordinate];
      break; 
    }
  }
}

void Map::updateRobotLoc(){
  // call this function in main whenever a new gridspace is reached
  // thus in the main function there needs to be the encoder check for knowing how far we've driven
   switch ( Map::robotPosition[Map::directionInt] ) {
    case 0: //north
      Map::robotPosition[Map::Xcoordinate] += 1;
      break;
    case 90: //east
      Map::robotPosition[Map::Ycoordinate] += 1;
      break;
    case 180: // south
      Map::robotPosition[Map::Xcoordinate] -= 1;
      break;
    case 270: // west
      Map::robotPosition[Map::Ycoordinate] -= 1;
      break;
   }
}

void Map::updateRobotDir(int amount){
	Map:robotPosition[Map::directionInt] += amount;
	
	if (Map::robotPosition[Map::directionInt] >= 360){
		Map::robotPosition[Map::directionInt] -= 360;
	}
	if (Map::robotPosition[Map::directionInt] < 0){
		Map::robotPosition[Map::directionInt] += 360;
	}
}

bool Map::mountain() {
  #include "Sensors.h";
  
  int mountainDistance = Sensors::ultrasound();
  if (mountainDistance < 40) {
    return true;
  }
  else {
    return false;
  }
}

void Map::returnLab(){
  Map::focusY = false;
  int driveReturn;
  int dir = Map::findDir();
  Move::turn(dir-Map::robotPosition[2]);
  
  while(Map::robotPosition[0] != 0 && Map::robotPosition[1] != 0){
     if (Map::focusY == false){
      if(Map::robotPosition[0] > 0) {
        if (Map::mountain() == true) {
          Map::blocked();
        }
        else{
          driveReturn = Move::drive_new(1.35);
          if (driveReturn == true) {
            Map::blocked(); 
          }
          else {
            Map::blockedStatus = 0;
            Map::robotPosition[0]--;
          }
        }
      }
      if (Map::robotPosition[0] > 0) {
        if (Map::mountain() == true) {
          Map::blocked();
        }
        else{
          driveReturn = Move::drive_new(1.35);
          if (driveReturn == true) {
            Map::blocked(); 
          }
          else {
            Map::blockedStatus = 0;
            Map::robotPosition[0]++;
          }
        }
      }
    }
    if (Map::focusY == true){
      if(Map::robotPosition[1] > 0) {
        if (Map::mountain() == true) {
          Map::blocked();
        }
        else{
          driveReturn = Move::drive_new(1.35);
          if (driveReturn == true) {
            Map::blocked(); 
          }
          else {
            Map::blockedStatus = 0;
            Map::robotPosition[1]--;
          }
        }
      }
      if (Map::robotPosition[1] > 0) {
        if (Map::mountain() == true) {
          Map::blocked();
        }
        else{
          driveReturn = Move::drive_new(1.35);
          if (driveReturn == true) {
            Map::blocked(); 
          }
          else {
            Map::blockedStatus = 0;
            Map::robotPosition[1]++;
          }
        }
      }
    }
  }
  if (Map::robotPosition[0] == 0 && Map::robotPosition[1] == 0){
    //at the lab
    dir=180;
    Move::turn(dir-Map::robotPosition[2]);
    Map::robotPosition[2] = dir;
  }
}

int Map::findDir(){
  if (Map::focusY == true) {
    
    if (Map::robotPosition[1] > 0) {
      Map::returnDir = 180;
    }
    else if (Map::robotPosition[1] < 0) {
      Map::returnDir = 0;
    }
    else if (Map::robotPosition[1] == 0) {
      int randm = random(0,2);
      if (randm == 0) {
        Map::returnDir = 0;
      }
      else {
      Map::returnDir = 180;
      }
    }
  }
  else {
    if (Map::robotPosition[0] > 0) {
    Map::returnDir = 270;
    }
    else if (Map::robotPosition[0] < 0) {
      Map::returnDir = 90;
    }
    else if (Map::robotPosition[0] == 0) {
      int randm = random(0,2);
      if (randm == 0) {
        Map::returnDir = 270;
      }
      else {
        Map::returnDir = 90;
      }
    }
  }
  return(Map::returnDir);
}

void Map::blocked() { //when it is blocked in front 
  switch (Map::blockedStatus) {
      case 0:   //first time blocked;
      
        if (Map::focusY){
          Map::focusY = false;
        }
        else{
          Map::focusY = true;
        }
        
        Map::blockedStatus++;
        int dir = Map::findDir();
        Map::blockedTurn = dir-Map::robotPosition[2];
        Move::turn(Map::blockedTurn);
        Map::robotPosition[2] = dir;
        break;
      case 1:   //second time blocked
        Map::blockedStatus++;
        Move::turn(blockedTurn);
        
        while (true) {
          Move::drive(1.35);
          if (Map::robotPosition[0] < 0 && Map::robotPosition[1] < 0){
            if (focusY == true) {
              Map::robotPosition[0]--;
            }
            else {
              Map::robotPosition[1]--;
            } 
          }
          else if (Map::robotPosition[0] >= 0 && Map::robotPosition[1] < 0) {
            if (focusY == true) {
              Map::robotPosition[0]++;
            }
            else {
              Map::robotPosition[1]--;
            } 
          }
          else if (Map::robotPosition[0] < 0 && Map::robotPosition[1] >= 0) {
            if (focusY == true) {
              Map::robotPosition[0]--;
            }
            else {
              Map::robotPosition[1]++;
            } 
          }
          else if (Map::robotPosition[0] >= 0 && Map::robotPosition[1] >= 0) {
            if (focusY == true) {
              Map::robotPosition[0]++;
            }
            else {
              Map::robotPosition[1]++;
            } 
         }
          Move::turn(-Map::blockedTurn);
          if (mountain() == true) {
            Move::turn(Map::blockedTurn);
            
          }
          else {
            break;
          }
        }
        break;
  }
  
}


void Map::test(){
  Map::robotPosition[0] = 4;
  Map::robotPosition[1] = -3;
  Map::robotPosition[2] = 90;
}
