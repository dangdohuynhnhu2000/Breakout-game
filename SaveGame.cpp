#include "SaveGame.h"



SaveGame::SaveGame()
{
}


SaveGame::~SaveGame()
{
}

void SaveGame::saveGameOutFile(float vx, float vy, float bx, float by, float px, float py, vector <Brick*> shape, int level)
{
	status.vx = vx;
	status.vy = vy;
	status.ballx = bx;
	status.bally = by;
	status.px = px;
	status.py = py;
	status.level = level;
	for (int i = 0; i < shape.size();i++)
	{
		int status_brick = shape[i]->getStatus();
		status.block[i] = status_brick;
	}
	status.block[shape.size()] = -100;
	ofstream file;
	file.open("savegame.txt", ios::binary | ios ::trunc);

	if (file.is_open())
	{
		file.write((char *) &status, sizeof(status));
	}
	file.close();
}

void SaveGame:: readSaveGame(float &vx, float &vy,Ball &ball, Paddle &paddle1, Grid & grid)
{
	ifstream file;
	file.open("savegame.txt", ios ::binary);
	if (file.is_open())
	{
		file.read((char *)&status, sizeof(status));
	}
	file.close();
	ball.setPos({ status.ballx ,status.bally });
	vx = status.vx;
	vy = status.vy;
	paddle1.setPos({ status.px ,status.py});
	switch (status.level)
	{
	case 1:
	{
		grid.Level1();
		break;
	}
	case 2:
	{
		grid.Level2();
		break;
	}
	}
	vector <int> status_brick;
	for (int i = 0;i < 100;i++)
	{
		if (status.block[i] != -100)
		{
			status_brick.push_back(status.block[i]);
		}
		else
		{
			break;
		}
	}
	grid.setStatus(status_brick);
}