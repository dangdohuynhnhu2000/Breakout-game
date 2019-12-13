#pragma once
#include <string>
#include "Ball.h"
#include "Item.h"
#include "Bullet.h"
#include "GunMode.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class Brick
{
protected:
	Vector2f position;
	int status;
	//0: dang ton tai
	//-1: da bien mat
	Texture texture;
	int number = 0;//so mac dinh cho moi brick
	Text text; //de in cac chu hoac so trong cuc gach
	Font font;
	Item item;//vat pham thuong, phat trong game
public:
	virtual FloatRect getPosition() = 0;
	virtual Vector2f getPositionxy() = 0;
	virtual int getStatus() = 0;
	virtual void setPosition(float newPosx, float newPosy) = 0;
	virtual void setBrick(float startX, float startY, float a, float b, int stt) = 0;
	virtual void setTexture(string textureName) = 0;
	virtual void setNumber(int num) = 0;
	virtual void setStatus(int stt) = 0;
	virtual void setItemForBrick(int type) = 0;
	virtual void draw(Paddle& paddle, RenderWindow& window) = 0;

	virtual void moveLeftAndRight(float vx) = 0;
	virtual void moveDown(float vy) = 0;
	virtual bool reflex(Ball& ball, float& vx, float& vy) = 0;
	virtual int isItemHitPaddle(Paddle paddle) = 0;
	virtual bool isHitBullet(Bullet bullet) = 0;

};

