#include "Block.h"

Block::Block(float startX, float startY, int point, float radius, int color, int stt)
{
	position.x = startX;
	position.y = startY;
	shape.setPointCount(point);
	shape.setRadius(radius);
	color = 1 + rand() % (5 + 1 - 1); //random 1 so tu 1 toi 5
	if (color == 1)
	{
		shape.setFillColor(Color::Blue);
	}
	else if (color == 2)
	{
		shape.setFillColor(Color::Green);
	}
	else if (color == 3)
	{
		shape.setFillColor(Color::Yellow);
	}
	else if (color == 4)
	{
		shape.setFillColor(Color::Cyan);
	}
	else
	{
		shape.setFillColor(Color::Red);
	}
	status = stt;
	shape.setPosition(position);
}

FloatRect Block::getPosition()
{
	return shape.getGlobalBounds();
}

CircleShape Block::getShape()
{
	return shape;
}

void Block::draw(RenderWindow& window)
{
	window.draw(getShape());
}