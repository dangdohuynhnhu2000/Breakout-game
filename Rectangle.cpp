#include "Rectangle.h"


void Rectangle::setBrick(float startX, float startY, float a, float b, int stt)
{
	position.x = startX;
	position.y = startY;
	recshape.setSize(Vector2f(a,b));
	recshape.setPosition(position);
	status = stt;
}

void Rectangle::setTexture(string textureName)
{
	texture.loadFromFile(textureName);
	recshape.setTexture(&texture);
}

FloatRect Rectangle::getPosition()
{
	return recshape.getGlobalBounds();
}

RectangleShape Rectangle ::getShape()
{
	return recshape;
}

void Rectangle::draw(RenderWindow& window)
{
	window.draw(getShape());
}