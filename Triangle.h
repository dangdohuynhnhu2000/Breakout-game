#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;
//#include "Header.h"
#include "Brick.h"
#include "Item.h"
#include <conio.h>
struct point2D
{
	float x;
	float y;
};
class Triangle:public Brick
{
private:
	CircleShape shape;
	float height, baseSize, radius;
public:
	virtual void setBrick(float startX, float startY, float a, float b, int stt);

	virtual void setTexture(string textureName);
	virtual void setStatus(int stt);
	
	FloatRect getPosition();

	virtual Vector2f getPositionxy();

	virtual int getStatus();

	virtual void setPosition(float newPosx, float newPosy);

	virtual void setNumber(int num);
	virtual void setItemForBrick(int type);
	
	CircleShape getShape();

	virtual void draw(Paddle &paddle, RenderWindow& window);

	virtual void moveLeftAndRight(float vx);

	virtual void moveDown(float vy);

	virtual bool reflex(Ball& ball, float& vx, float& vy,Paddle & paddle);

	virtual int isItemHitPaddle(Paddle paddle);

	virtual bool isHitBullet(Bullet bullet);

	virtual float AreaTriangle(point2D a, point2D b, point2D c);

	virtual int getNumber();

	virtual void changeNumber(int num);

	virtual Item getItem();

	void setStatusForItem(int status);

	void setPositionForItem(Vector2f pos);

};