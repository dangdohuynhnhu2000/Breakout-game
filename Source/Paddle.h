#pragma once

#include <SFML\Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Ball.h"

class Paddle {
private:
	sf::RectangleShape paddle;
	int score;
public:
	bool canShoot;//dung cho truong hop nhan duoc vat pham ban sung
	bool isOnGunMode;//cho biet paddle co dang o che do GunMode

	Paddle();
	~Paddle();
	void setSize(sf::Vector2f size); //cai dat kich thuoc

	Paddle(sf::Vector2f size); //khoi tao kich thuoc

	void drawTo(sf::RenderWindow& window); //ve ban do

	void move(sf::Vector2f distance); //di  chuyen theo vecto

	void setPos(sf::Vector2f newPos); //ai dat vi tri

	void setColor(int a, int b, int c, int d); //to mau

	FloatRect getPosition(); // lay vi tri cua paddle

	bool isHitBall(Ball ball, float vx, float vy); //tra ve true neu hung duoc bong, nguoc lai tra ve false

	bool reflex(Ball &ball, float &vx, float &vy, bool &check);

	void setScore(int newScore); // thiet lap diem cho paddle

	int getScore(); // lay diem tu paddle

	void turnGunMode(bool shootMode); // bat tat che do ban sung

	void autoMove(float vx); // tu dong di chuyen
};

