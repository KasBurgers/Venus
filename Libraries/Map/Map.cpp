#include "Sensors.h"
#include "Movement.h"
#include "Arduino.h"
#include "Map.h"

// create construct
int Map::Xcoordinate = 0;
int Map::Ycoordinate = 1;
int Map::dir = 2;

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
   switch ( Map::robotPosition[Map::dir] ) {
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
	Map:robotPosition[Map::dir] += amount;
	
	if (Map::robotPosition[Map::dir] >= 360){
		Map::robotPosition[Map::dir] -= 360;
	}
	if (Map::robotPosition[Map::dir] < 0){
		Map::robotPosition[Map::dir] += 360;
	}
}
	
