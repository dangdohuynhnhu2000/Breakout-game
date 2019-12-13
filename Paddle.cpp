
#include "Paddle.h"

Paddle::Paddle()
{
	paddle.setSize({ 0,0 });//khoi tao size mac dinh  = 0
	canShoot = false;//ban dau khong co chuc nang ban
	isOnGunMode = false;//ban dau khong co che do ban
}

void Paddle::setSize(sf::Vector2f size)
{
	paddle.setSize(size);//cai size
}

void Paddle::turnGunMode(bool shootMode)
{
	canShoot = shootMode;
}

Paddle::Paddle(sf::Vector2f size) {
	paddle.setSize(size);//khoi tao voi size cho truoc
}

void Paddle::drawTo(sf::RenderWindow& window) {
	window.draw(paddle);// ve thanh truot hinh chu nhat
}

void Paddle::move(sf::Vector2f distance) {
	paddle.move(distance);//di chuyen theo huong vecto
}

void Paddle::setPos(sf::Vector2f newPos) {
	paddle.setPosition(newPos);//cai dat vi tri
}

void Paddle::setColor(int a, int b, int c, int d) {
	paddle.setFillColor(sf::Color(a, b, c, d));//doi mau
}

FloatRect Paddle::getPosition()
{
	return paddle.getGlobalBounds();
}


bool Paddle::isHitBall(Ball ball) {
	//neu bong cham thanh truot thi tra ve true
	if (ball.getPos().y + ball.getRad() * 2 > paddle.getPosition().y && ball.getPos().y < paddle.getPosition().y + paddle.getSize().y) {
		if (ball.getPos().x + ball.getRad() * 2 > paddle.getPosition().x && ball.getPos().x < paddle.getPosition().x + paddle.getSize().x) {
			return true;
		}
	}
	return false;
}

bool Paddle::reflex(Ball& ball, float& vx, float& vy)
{
	bool collision = false;

	float x0 = getPosition().left;
	float x1 = x0 + getPosition().width;
	float y0 = getPosition().top;
	float y1 = y0 + getPosition().height;

	float bx0 = ball.getPosition().left;
	float bx1 = bx0 + ball.getPosition().width;
	float by0 = ball.getPosition().top;
	float by1 = by0 + ball.getPosition().height;

	if (by0 + vy <= y1 && by1 + vy >= y0)
	{
		if ((bx0 + vx <= x1 && bx1 + vx >= x0))
		{
			collision = true;
		}
	}

	if (collision)
	{
		if (vy >= 0)
		{
			vy = -vy;
		}
		return true;
	}
	return false;
}
