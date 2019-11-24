#include "Rectangle.h"


Rectangle::Rectangle(float startX, float startY, float width, float height, int color, int stt)
{
	position.x = startX;
	position.y = startY;
	shape.setSize(Vector2f(width,height));
	shape.setPosition(position);
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
}
FloatRect Rectangle::getPosition()
{
	return shape.getGlobalBounds();
}

RectangleShape Rectangle ::getShape()
{
	return shape;
}

void Rectangle::draw(RenderWindow& window)
{
	window.draw(getShape());
}