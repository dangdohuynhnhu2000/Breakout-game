#pragma once
#include <SFML/Graphics.hpp>
#include "Brick.h"
#include "Grid.h"
#include "Header.h"
using namespace sf;

class Rectangle : public Brick
{
private:
	RectangleShape recshape;

public:
	virtual void setBrick(float startX, float startY, float a, float b, int stt);
	
	virtual void setTexture(string textureName);
	
	virtual FloatRect getPosition();

	RectangleShape getShape();

	virtual void draw(RenderWindow& window);

	bool reflex(Ball & ball, float &vx, float &vy);
	// void Collision(Ball & ball, float &vx, float &vy);
};

