#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "Ball.h"
using namespace sf;
using namespace std;

class Brick
{
protected:
	Vector2f position;
	int status;
	Texture texture;
	//-1: die
	//0: stationary
	//1: go left
	//2: go right
public:
	virtual FloatRect getPosition() = 0;
	virtual void setBrick(float startX, float startY, float a, float b, int stt) = 0;
	virtual void setTexture(string textureName) = 0;
	virtual void draw(RenderWindow& window) = 0;
	virtual bool reflex(Ball & ball, float &vx, float &vy) = 0;
	virtual int getStatus();
	virtual void setStatus(int _status);
};

