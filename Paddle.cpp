#include "Paddle.h"

Paddle::Paddle() {
	paddle.setSize({ 0,0 });//khoi tao size mac dinh  = 0
}

void Paddle::setSize(sf::Vector2f size) {
	paddle.setSize(size);//cai size
}

Paddle::~Paddle() {

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

sf::Vector2f Paddle::getPos() {
	return paddle.getPosition(); //lay vi tri
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