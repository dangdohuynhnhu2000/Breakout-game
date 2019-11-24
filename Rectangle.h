#pragma once
#include <SFML/Graphics.hpp>
#include "Figure.h"
using namespace sf;

class Rectangle : public Figure
{
private:
	RectangleShape shape;

public:
	Rectangle(float startX, float startY, float width, float height, int color, int stt);

	virtual FloatRect getPosition();

	RectangleShape getShape();

	virtual void draw(RenderWindow& window);

};

