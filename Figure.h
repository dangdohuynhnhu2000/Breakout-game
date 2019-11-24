#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;

class Figure
{
protected:
	Vector2f position;
	int status;
	//-1: die
	//0: stationary
	//1: go left
	//2: go right
public:
	virtual FloatRect getPosition() = 0;
	virtual void draw(RenderWindow& window) = 0;
};

