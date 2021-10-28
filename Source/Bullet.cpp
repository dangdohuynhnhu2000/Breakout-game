#include "Bullet.h"

Bullet::Bullet(Texture& texture)
{
	sprite.setTexture(texture); // cai dat texture
	sprite.scale(0.1, 0.1); // cai dat ti le
	exist = -1; // trang thai mac dinh -1
}

FloatRect Bullet::getPosition()
{
	return sprite.getGlobalBounds(); //tra ve vi tri
}

void Bullet::Shoot(Paddle& paddle, Clock& bulletClock)
{
	exist = 0; // khi ban thi trang thai = 0
	float x, y; 
	x = paddle.getPosition().left + paddle.getPosition().width / 2 - sprite.getGlobalBounds().width / 2; // cai dat vi tri ban giua paddle
	y = paddle.getPosition().top - sprite.getGlobalBounds().height; // cai dat vi tri ban giua paddle
	sprite.setPosition(x, y); // thiet lap vi tri
	paddle.turnGunMode(false);//tat che do ban sung cho paddle cho den khi thoa dieu kien ban
	bulletClock.restart(); // reset lai dong ho
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
	window.draw(sprite); // ve sprite len man hinh
}

void Bullet :: setStatus(int status)
{
	exist = status; // cai dat lai trang thai moi cho vien dan
}

int Bullet::getStatus()
{
	return exist; //tra ve trang thai cua vien dan
}

void Bullet::setPosition(float x, float y)
{
	sprite.setPosition({ x,y }); // thiat lap vi tri moi cho vien dan (dung trong save game)
}