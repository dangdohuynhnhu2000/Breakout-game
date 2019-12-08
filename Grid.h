#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Rectangle.h"
#include "Triangle.h"
#include <vector>
#include <iostream>
using namespace std;

class Grid
{
private:
	vector <Brick*> shape;
	int n;
public:
	void Level1();
	void Level2();
	void draw(RenderWindow& window);

	void Reflex(Ball & ball, float &vx, float &vy);
};

