#include "Brick.h"

FloatRect Brick::getPosition()
{
	return FloatRect();
}

Vector2f Brick::getPositionxy()
{
	return Vector2f(0, 0);
}

int Brick::getStatus()
{
	return 0;
}

void Brick::setPosition(float newPosx, float newPosy)
{

}

void Brick::setTexture(string textureName)
{

}

void Brick::setBrick(float startX, float startY, float a, float b, int stt)
{

}

void Brick::moveLeftAndRight(float vx)
{

}

void Brick::draw(Paddle& paddle, RenderWindow& window)
{

}

void Brick::setNumber(int num)
{

}

void Brick::setStatus(int stt)
{

}

void Brick::setItemForBrick(int type)
{

}

int isItemHitPaddle(Paddle paddle)
{
	return 0;
}

void Brick::moveDown(float vy)
{

}

bool Brick::reflex(Ball& ball, float& vx, float& vy)
{
	return bool();
}

bool Brick::isHitBullet(Bullet bullet)
{
	return true;
}

int Brick::getNumber()
{
	return 0;
}

void Brick::changeNumber(int num)
{
	
}

void Brick::setIsStone(bool type)
{
}