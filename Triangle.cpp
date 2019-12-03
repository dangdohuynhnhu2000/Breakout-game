#include "Triangle.h"
#include "Rectangle.h"


void Triangle::setBrick(float startX, float startY, float a, float b, int stt)
{
	position.x = startX;
	position.y = startY;
	shape.setPointCount(a);
	shape.setRadius(b);
	shape.setPosition(position);
	status = stt;
}

void Triangle::setTexture(string textureName)
{
	texture.loadFromFile(textureName);
	shape.setTexture(&texture);
}

FloatRect Triangle::getPosition()
{
	return shape.getGlobalBounds();
}

CircleShape Triangle::getShape()
{
	return shape;
}

void Triangle::draw(RenderWindow& window)
{
	window.draw(getShape());
}