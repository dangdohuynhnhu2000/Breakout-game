#pragma once

#include <SFML\Graphics.hpp>
#include "Ball.h"
#include "Paddle.h"

class Wall {
public:
	Paddle Left, Right, Top, Bottom; //co the truy xuat len bong canh ra ngoai vi khi bong tac dong len moi canh se co hieu ung khac nhau
	Wall(); //khoi tao kich thuoc
	~Wall();
	void drawTo(sf::RenderWindow& window); //ve ra man hinh
};
