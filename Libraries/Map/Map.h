#ifndef Map_h
#define Map_h

class Map{
	public:
		static void addObstacle();
		static int obstacles[30][2];
		static void updateRobotLoc();
		static void updateRobotDir(int amount);
		static int robotPosition[3];
	private:
		static int Xcoordinate;
		static int Ycoordinate;
		static int dir;
};
#endif
