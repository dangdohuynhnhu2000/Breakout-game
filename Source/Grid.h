#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;
#include "Rectangle.h"
#include "Triangle.h"
#include "Ball.h"
#include "Brick.h"
#include <vector>
#include <iostream>
#include "GunMode.h"
#include <iostream>
#include <stdlib.h>
#include "SaveGame.h"
using namespace std;

class Grid
{
private:
	vector <Brick*> shape;
	int n;
	int level;
public:
	void Level2();
	void Level3();
	void Level1();
	void Level4();
	
	int getNumOfElements(); // lay so luong gach

	void moveLeftAndRight(float &vx, int windowWidth); // dich chuyen gach qua lai khi o level 2

	void moveDown(float vy, int windowHeight); // dich chuyen gach xuong khi o level 3

	bool Reflex(Ball& ball, float& vx, float& vy, Paddle & paddle); // chay vong lap de phan xa bong

	// tinh diem khi va cham item
	void draw(Paddle &paddle, RenderWindow& window); // ve toan bo gach

	vector <Brick*> getShape(); // lay toan bo gach

	int getlevel();// lay gia tri level

	void hitBullet(GunMode& gun, Paddle & paddle); // va cham vien dan

	int getRemainAmount(float y); // lay so luong gach chua bien mat

	int random(int a, int b); // ham khoi tao so ngau nhien

	void setStatus(vector <int>); // thiet lap status cho tat ca gach (su dung trong save game)

	void setStatusItem(vector <float> item_x, vector <float> itm_y, vector <int> item_status); // thiet lap status cho toan bo gach (dung trong save game)

	void setNumber(vector <int> list_num); // thiet lap co so cho toan bo gach (dung trong save game)

};

