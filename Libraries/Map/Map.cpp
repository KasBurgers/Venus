#include "Sensors.h"
#include "Movement.h"
#include "Arduino.h"
#include "Map.h"

void Map::addObstacle(){ 
  
  // check if position is already in array
  for (int i = 0; i < 30; i++) {
    if (Map::obstacles[i] == NULL){
      break;
    }
    else{
      if (Map::obstacles[i][0] == Map::robotPosition[0] && Map::obstacles[i][1] == Map::robotPosition[1]){
        
      return;
      }
    }
  }
  // add current location to the end of the array, since the obstacle is virtually in the same gridspace as the robot
  for (int i = 0; i < 30; i++) {  // find first empty spot in array
    if (Map::obstacles[i] == NULL)  {
      Map::obstacles[i][0] = Map::robotPosition[0];
      Map::obstacles[i][1] = Map::robotPosition[1];
      break; 
    }
  }
}
	
	
