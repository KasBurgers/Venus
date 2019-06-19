#ifndef Map_h
#define Map_h

class Map{
  public:
    //functions
	  static void addObstacle();
	  static void updateRobotLoc();
	  static void updateRobotDir(int amount);
    static void returnLab();
    static int findDir();
    static void blocked();
    static bool mountain();
    static void test();
    
    //variables
    static int robotPosition[4];
    static int obstacles[30][3];
    static int labPosition[3];
    static int returnDir;
    static int blockedStatus;
    static bool focusY;
    static int blockedTurn;
    
	private:
    //variables
		static int Xcoordinate;
		static int Ycoordinate;
		static int directionInt;

    
    
};
#endif
