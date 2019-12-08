#include "Brick.h"

FloatRect Brick::getPosition()
{
	return FloatRect();
}

void Brick::setTexture(string textureName)
{

}

void Brick::setBrick(float startX, float startY, float a, float b, int stt)
{

}

void Brick::draw(RenderWindow& window)
{

}

bool Brick::reflex(Ball & ball, float &vx, float &vy)
{
	return bool();
}

int Brick::getStatus()
{
	return status;
}

void Brick::setStatus(int _status)
{
	this->status = _status;
}