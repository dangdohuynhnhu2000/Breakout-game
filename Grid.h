#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Rectangle.h"
#include "Triangle.h"
#include "Ball.h"
#include "Brick.h"
#include <vector>
#include <iostream>
using namespace std;

class Grid
{
private:
	vector <Brick*> shape;
	int n;
public:
	void Level2();
	void Level1();
	void Level3();
	
	int getNumOfElements();
	void moveLeftAndRight(float &vx, int windowWidth);
	void moveDown(float& vy, int windowHeight);
	void Reflex(Ball& ball, float& vx, float& vy);
	void hitBullet(GunMode& gun);
	void draw(Paddle& paddle, RenderWindow& window);
};

