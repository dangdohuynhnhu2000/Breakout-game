#include "Item.h"

Item::Item()
{
	position.x = 0;
	position.y = 0;
	sprite.setPosition(position);
	type = 0;
}

void Item::setPosition(float x, float y)
{
	position.x = x;
	position.y = y;
	sprite.setPosition(position);
}

void Item::setTexture(string textureName)
{
	texture.loadFromFile(textureName);
	sprite.setTexture(texture);
}

void Item::setType(int t)
{
	type = t;
}

void Item::setStatus(int stt)
{
	status = stt;
}

void Item::setItem(float x, float y, string textureName, int t, int stt)
{
	setPosition(x, y);
	setTexture(textureName);
	setType(t);
	setStatus(stt);
	sprite.setScale(0.3, 0.3);
}

int Item::getStatus()
{
	return status;
}

Vector2f Item::getPositionxy()
{
	return position;
}

FloatRect Item::getPosition()
{
	return sprite.getGlobalBounds();
}

int Item::getType()
{
	return type;
}

void Item::moveDown(float vy, float limit)
{
	if (position.y < limit)
	{
		position.y += vy;
		setPosition(position.x, position.y);
	}
	
}

void Item::draw(RenderWindow& window)
{
	if (status == 0)
	{
		window.draw(sprite);
	}
}