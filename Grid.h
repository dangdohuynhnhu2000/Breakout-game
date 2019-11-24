#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Rectangle.h"
#include "Block.h"
#include <vector>
#include <iostream>
using namespace std;

class Grid
{
private:
	vector <Figure*> blockShape;
	int n;
public:
	void Level1();
	void draw(RenderWindow& window);
	friend int random(int min, int max);
};

