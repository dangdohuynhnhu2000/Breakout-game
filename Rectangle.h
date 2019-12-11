#pragma once
#include <SFML/Graphics.hpp>
#include "Brick.h"
#include "Grid.h"
#include "Item.h"
#include "Header.h"
#include <iostream>
using namespace std;
using namespace sf;

class Rectangle : public Brick
{
private:
	RectangleShape shape;
	float width, height;
public:
	virtual void setBrick(float startX, float startY, float a, float b, int stt);
	
	virtual void setTexture(string textureName);
	
	virtual FloatRect getPosition();

	virtual Vector2f getPositionxy();

	virtual int getStatus();

	virtual void setPosition(float newPosx, float newPosy);

	virtual void setNumber(int num);

	virtual void setStatus(int stt);

	virtual void setItemForBrick(int type);

	RectangleShape getShape();

	virtual void draw(Paddle paddle, RenderWindow& window);

	virtual void moveLeftAndRight(float vx);
	virtual void moveDown(float vy);
	virtual bool reflex(Ball& ball, float& vx, float& vy);
	virtual int isItemHitPaddle(Paddle paddle);
};

