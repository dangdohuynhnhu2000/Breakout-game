#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Paddle.h"
// class vien dan
class Bullet
{
private:
	Sprite sprite;

public:
	int exist;
	//0: ton tai
	//-1: an
	//-2: bien mat vinh vien khoi man hinh
	Bullet(Texture& texture);

	FloatRect getPosition(); // tra ve vi tri cua vien dan

	void Shoot(Paddle& paddle, Clock& bulletClock); // ban sung

	void moveUp(float a, float b); // vien dan di chuyen len

	void draw(RenderWindow& window); // ve vien dan 

	void setStatus(int status); // cai dat thuoc tinh status cho vien dan

	int getStatus(); // lay gia tri status cua vien dan

	void setPosition(float x, float y); // thiet lap vi tri cho vien dan (dung trong save game)

};