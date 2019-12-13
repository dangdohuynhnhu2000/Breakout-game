#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Paddle.h"

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
	FloatRect getPosition();
	void Shoot(Paddle& paddle, Clock& bulletClock);
	void moveUp(float a, float b);
	void draw(RenderWindow& window);
};

