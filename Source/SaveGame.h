#pragma once
#include <fstream>
#include "Grid.h"
#include "Brick.h"
#include "GunMode.h"

struct statusGame
{
	int life;
	int score;
	string name;
	float vx; // huong di chuyen
	float vy; // huong di chuyen
	float ballx, bally; // toa do cua ball
	float px, py; // toa do cua paddle
	int level; // level dang choi
	int block_status[150]; // trang thai cac cuc gach
	int block_number[150]; // co so cua cuc gach
	float item_x[150]; // hoanh do cua vat pham 
	float item_y[150]; // tung do cua vat pham 
	int item_status[150]; // trang thai cua vat pham
	int gunMode; // trang thai ban sung (1: dang ban, 0: khong ban)
	int nextBullet; // vien dan ke tiep duoc ban ra
	int bullet_status[5]; // trang thai cua list vien dan
	float bullet_x[5]; // vi tri cua list dan
	float bullet_y[5]; // vi tri cua list dan

};
class Grid;
class SaveGame
{
	statusGame status;
public:
	void saveGameOutFile(int score, string name, float vx, float vy, float bx, float by, Paddle paddle1, vector <Brick*> shape, int level, int life, GunMode gun); // luu toan bo man hinh hien tai vao file
	
	void readSaveGame(float & vx, float &vy, Ball &ball, Paddle &paddle1, Grid & grid, int & life, GunMode & gun); // doc thong tin tu file ra va thuc thi khi nguoi choi muon chon che do History


	SaveGame();
	~SaveGame();
};

