#pragma once
#include <iostream>
using namespace std;
#include <SFML\Graphics.hpp>
using namespace sf;

class Ball {
private:
	sf::CircleShape ball;
	float vx;
	float vy;
public:
	Ball();
	~Ball();
	Ball(float size); // khoi tao voi kich thuoc cho truoc

	void drawTo(sf::RenderWindow& window); //ve bong

	void move(sf::Vector2f distance); //di chuyen theo huong vecto
	
	void setPos(sf::Vector2f newPos); //cai dat vi tri

	sf::Vector2f getPos(); //lay vi tri hien tai

	float getRad(); //lay ban kinh

	FloatRect getPosition(); // lay vi tri cua trai bong

	FloatRect getGlobalBounds(); // lay vi tri cua trai bong
};
