#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Brick.h"
#include "Item.h"
#include "Header.h"

class Triangle:public Brick
{
private:
	CircleShape shape;
	float height, baseSize, radius;
public:
	virtual void setBrick(float startX, float startY, float a, float b, int stt);

	virtual void setTexture(string textureName);

	virtual void changeNumber(int num);

	virtual void setStatus(int stt);
	
	FloatRect getPosition();

	virtual Vector2f getPositionxy();

	virtual int getStatus();
	virtual int getNumber();

	virtual void setPosition(float newPosx, float newPosy);

	virtual void setNumber(int num);
	virtual void setItemForBrick(int type);
	
	CircleShape getShape();

	virtual void draw(Paddle& paddle, RenderWindow& window);

	virtual void moveLeftAndRight(float vx);
	virtual void moveDown(float vy);
	virtual bool reflex(Ball& ball, float& vx, float& vy);
	virtual bool isHitBullet(Bullet bullet);
	virtual int isItemHitPaddle(Paddle paddle);

};