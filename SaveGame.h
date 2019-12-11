#pragma once
#include "Header.h"
#include "Grid.h"
struct statusGame
{
	float vx;
	float vy;
	float ballx, bally;
	float px, py;
	int level;
	int block[100];
};
class Grid;
class SaveGame
{
	statusGame status;
public:
	void saveGameOutFile(float vx, float vy, float bx, float by, float px, float py, vector <Brick*> shape, int level);
	
	void readSaveGame(float & vx, float &vy, Ball &ball, Paddle &paddle1, Grid & grid);


	SaveGame();
	~SaveGame();
};

