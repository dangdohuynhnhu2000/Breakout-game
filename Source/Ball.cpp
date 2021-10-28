#include "Ball.h"

Ball::Ball() {
	ball.setRadius(0); // kich thuoc mat dinh = 0
}
Ball::~Ball() {

}

Ball::Ball(float size) {
	ball.setRadius(size); //truyen ban kinh
}

void Ball::drawTo(sf::RenderWindow& window) {
	window.draw(ball); //ve qua bong
}

void Ball::move(sf::Vector2f distance) {
	ball.move(distance.x, distance.y); // di chuyen 
}

void Ball::setPos(sf::Vector2f newPos) {
	ball.setPosition(newPos); //cai dat vi tri
}

sf::Vector2f Ball::getPos() {
	return ball.getPosition(); //lay vi tri
}

float Ball::getRad() {
	return ball.getRadius(); //lay ban kinh
}


FloatRect Ball::getPosition()
{
	return ball.getGlobalBounds(); // lay vi tri cua ball
}

FloatRect Ball::getGlobalBounds()
{
	return ball.getGlobalBounds(); // lay vi tri cua ball
}