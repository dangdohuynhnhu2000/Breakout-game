#include "SaveGame.h"



SaveGame::SaveGame()
{
}


SaveGame::~SaveGame()
{
}

void SaveGame::saveGameOutFile(int score, string name, float vx, float vy, float bx, float by, Paddle paddle1, vector <Brick*> shape, int level, int life, GunMode gun)
{
	status.life = life;
	status.score = score;
	status.name = name;
	status.vx = vx;
	status.vy = vy;
	status.ballx = bx;
	status.bally = by;
	status.px = paddle1.getPosition().left;
	status.py = paddle1.getPosition().top;
	status.level = level;

	for (int i = 0; i < shape.size();i++)
	{
		int status_brick = shape[i]->getStatus(); // lay trang thai cua vien gach
		status.block_status[i] = status_brick;
	}
	status.block_status[shape.size()] = -100; //dau hieu de ket thuc mang

	for (int i = 0; i < shape.size();i++)
	{
		int _status_item = shape[i]->getItem().getStatus(); // luu status cua item
		status.item_status[i] = _status_item;
		Vector2f _position = shape[i]->getItem().getPositionxy(); // lay toa do cua item
		status.item_x[i]= _position.x;
		status.item_y[i] = _position.y;
		status.block_number[i] = shape[i]->getNumber();
	}
	status.item_status[shape.size()] = -100;// dau hieu de ket thuc mang
	status.item_x[shape.size()] = 0; // dau hieu de ket thuc mang
	status.item_y[shape.size()]= 0; // dau hieu de ket thuc mang
	status.block_number[shape.size()] = -100;// dau hieu de ket thuc mang

	if (paddle1.isOnGunMode == true) 
	{
		status.gunMode = 1;
	}
	else
	{
		status.gunMode = 0;
	}

	status.nextBullet = gun.getNextBullet();

	int count_bullet_status = 0;
	for (int i = 0;i < 5;i++)
	{
		if (gun.bulletList[i].getStatus() == 0)
		{
			count_bullet_status++;
		}
		status.bullet_status[i] = gun.bulletList[i].getStatus();
	}
	if (count_bullet_status != 0) // de khi thuc hien chuc nang  history co the thuc hien duoc
	{
		status.gunMode = 1;
	} 

	for (int i = 0;i < 5;i++) //vi tri cua vien dan
	{
		status.bullet_x[i] = gun.bulletList[i].getPosition().left;
		status.bullet_y[i] = gun.bulletList[i].getPosition().top;
	}

	ofstream file;
	file.open("savegame.txt", ios::binary);
	if (file.is_open())
	{
		file.write((char *) &status, sizeof(status));
	}
	file.close();
}

void SaveGame:: readSaveGame(float &vx, float &vy,Ball &ball, Paddle &paddle1, Grid & grid, int &life, GunMode & gun)
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
	life = status.life;
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
	case 3:
		grid.Level3();
		break;
	case 4:
		grid.Level4();
		break;
	}
	vector <int> list_brick_status;
	vector <int> list_brick_number;
	vector <int> list_item_status;
	vector <float> list_item_x;
	vector <float > list_item_y;
	
	// luu tu mang ra vector
	for (int i = 0;i < 150;i++)
	{
		if (status.block_status[i] != -100)
		{
			list_brick_status.push_back(status.block_status[i]);
			list_item_status.push_back(status.item_status[i]);
			list_item_x.push_back(status.item_x[i]);
			list_item_y.push_back(status.item_y[i]);
			list_brick_number.push_back(status.block_number[i]);
		}
		else
		{
			break;
		}
	}
	// thiet lap lai gach
	grid.setStatus(list_brick_status);
	grid.setStatusItem(list_item_x, list_item_y, list_item_status);
	grid.setNumber(list_brick_number);

	if (status.gunMode == 1)
	{
		paddle1.isOnGunMode = true;
	}
	else
	{
		paddle1.isOnGunMode = false;
	}
		
	// thiet lap lai gunmode
	for (int i = 0;i < 5;i++)
	{
		gun.bulletList[i].setStatus(status.bullet_status[i]);
	}

	gun.setNextBullet(status.nextBullet);

	for (int i = 0; i < 5;i++)
	{
		gun.bulletList[i].setPosition(status.bullet_x[i], status.bullet_y[i]);
	}
}