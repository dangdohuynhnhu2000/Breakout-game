#include "Item.h"

Item::Item()
{
	// thiet lap cac gia tri mac dinh cho item
	position.x = 0;
	position.y = 0;
	sprite.setPosition(position);
	type = 0;
	status = -2;
}

void Item::setPosition(float x, float y)
{ 
	// thiet lap vi tri cho item
	position.x = x;
	position.y = y;
	sprite.setPosition(position);
}

void Item::setTexture(string textureName)
{
	// tao hinh anh
	texture.loadFromFile(textureName);
	sprite.setTexture(texture);
}

void Item::setType(int t)
{
	// loai vat pham
	type = t;
}

void Item::setStatus(int stt)
{
	// cai dat status cho item
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
	// lay vi tri hien tai cua item
	return position;
}

FloatRect Item::getPosition()
{
	return sprite.getGlobalBounds();
}

int Item::getType()
{
	// tra ve loai vat pham
	return type;
}

void Item::moveDown(float vy, float limit)
{
	// vat pham roi xuong
	if (position.y < limit)
	{
		position.y += vy;
		setPosition(position.x, position.y);
	}
	
}

void Item::draw(RenderWindow& window)
{
	// ve len man hinh
	if (status == 0)
	{
		window.draw(sprite);
	}
}