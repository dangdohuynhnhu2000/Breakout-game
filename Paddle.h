#pragma once

#include <SFML\Graphics.hpp>
#include "Ball.h"

class Paddle {
private:
	sf::RectangleShape paddle;
public:
	Paddle();
	~Paddle();
	void setSize(sf::Vector2f size); //cai dat kich thuoc

	Paddle(sf::Vector2f size); //khoi tao kich thuoc

	void drawTo(sf::RenderWindow& window); //ve ban do

	void move(sf::Vector2f distance); //di  chuyen theo vecto

	void setPos(sf::Vector2f newPos); //ai dat vi tri

	void setColor(int a, int b, int c, int d); //to mau

	FloatRect getPosition();

	bool isHitBall(Ball ball); //tra ve true neu hung duoc bong, nguoc lai tra ve false

	bool reflex(Ball &ball, float &vx, float &vy);
};

