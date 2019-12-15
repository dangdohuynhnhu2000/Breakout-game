#include "Bullet.h"

Bullet::Bullet(Texture& texture)
{
	sprite.setTexture(texture);
	sprite.scale(0.1, 0.1);
	exist = -1;
}

FloatRect Bullet::getPosition()
{
	return sprite.getGlobalBounds();
}

void Bullet::Shoot(Paddle& paddle, Clock& bulletClock)
{
	exist = 0;
	float x, y;
	x = paddle.getPosition().left + paddle.getPosition().width / 2 - sprite.getGlobalBounds().width / 2;
	y = paddle.getPosition().top - sprite.getGlobalBounds().height;
	sprite.setPosition(x, y);
	paddle.turnGunMode(false);//tat che do ban sung cho paddle cho den khi thoa dieu kien ban
	bulletClock.restart();
}

void Bullet::moveUp(float a, float b)
{
	sprite.move(a, b);//di chuyen vien dan len tren khi ban
	//neu bullet cham khung man hinh thi bien mat
	if (sprite.getGlobalBounds().top + sprite.getGlobalBounds().height < 155)
	{
		exist = -2;//bien mat vinh vien khoi man hinh
	}
}

void Bullet::draw(RenderWindow& window)
{
	window.draw(sprite);
}

void Bullet :: setStatus(int status)
{
	exist = status;
}

int Bullet::getStatus()
{
	return exist;
}

void Bullet::setPosition(float x, float y)
{
	sprite.setPosition({ x,y });
}