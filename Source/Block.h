#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Figure.h"

using namespace sf;

class Block : public Figure
{
private:
	CircleShape shape;

public:
	Block(float startX, float startY, int point, float radius, int color, int stt);
	virtual FloatRect getPosition();
	CircleShape getShape();
	virtual void draw(RenderWindow& window);
};