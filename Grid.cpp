#include "Grid.h"

void Grid::draw(RenderWindow& window)
{
	for (int i = 0; i < n; i++)
	{
		blockShape[i]->draw(window);
	}
}

void Grid::Level1()
{
	n = 43;
	Figure* temp;
	int width, height, radius, posx, posy, color;
	color = 0;
	cout << color << endl;
	posy = 10;
	width = 40;
	height = 70;

	for (int i = 0; i < 7; i++)
	{
		posx = 250;
		posy = posy + height + 10;
		temp = new Rectangle(posx, posy, width, height, color, 0);
		blockShape.push_back(temp);
	}

	posy = 10;
	for (int i = 0; i < 7; i++)
	{
		posx = 300;
		posy = posy + height + 10;
		temp = new Rectangle(posx, posy, width, height, color, 0);
		blockShape.push_back(temp);
	}

	posy = 10;
	for (int i = 0; i < 7; i++)
	{
		posx = 550;
		posy += height + 10;
		temp = new Rectangle(posx, posy, width, height, color, 0);
		blockShape.push_back(temp);
	}

	posy = 10;
	for (int i = 0; i < 7; i++)
	{
		posx = 600;
		posy += height + 10;
		temp = new Rectangle(posx, posy, width, height, color, 0);
		blockShape.push_back(temp);
	}

	posy = 370;
	posx = 300;
	width = 40;
	height = 40;
	for (int i = 0; i < 4; i++)
	{
		posx += width + 10;
		temp = new Rectangle(posx, posy, width, height, color, 0);
		blockShape.push_back(temp);
	}

	posy = 320;
	posx = 300;
	width = 40;
	height = 40;
	for (int i = 0; i < 4; i++)
	{
		posx += width + 10;
		temp = new Rectangle(posx, posy, width, height, color, 0);
		blockShape.push_back(temp);
	}
	
	radius = 35;
	posx = 650;
	posy = 15;
	for (int i = 0; i < 7; i++)
	{
		posy += 80;
		temp = new Block(posx, posy, 5, radius, color, 0);
		blockShape.push_back(temp);
	}
}

