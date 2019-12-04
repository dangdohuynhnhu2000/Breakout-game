#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Brick.h"
#include "Header.h"

class Triangle:public Brick
{
private:
	CircleShape shape;

public:
	virtual void setBrick(float startX, float startY, float a, float b, int stt);

	virtual void setTexture(string textureName);
	
	FloatRect getPosition();

	CircleShape getShape();

	virtual void draw(RenderWindow& window);
	
	bool reflex(Ball & ball, float &vx, float &vy, bool & goingUp, bool & goingDown, bool & goingLeft, bool & goingRight, bool & check);

};