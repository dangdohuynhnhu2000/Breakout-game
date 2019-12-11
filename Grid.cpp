#include "Grid.h"

void Grid::draw(RenderWindow& window)
{
	for (int i = 0; i < shape.size(); i++)
	{
		if (shape[i]->getStatus() != -1)
		{
			
			shape[i]->draw(window);
		}
	}
}

void Grid::Level1()
{
	n = 43;
	Brick* temp;
	int width, height, radius, posx, posy;
	posy = 10;
	width = 40;
	height = 70;

	for (int i = 0; i < 7; i++)
	{
		posx = 250;
		posy = posy + height + 10;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("stand blue rectangle.jpg");
		shape.push_back(temp);
	}

	posy = 10;
	for (int i = 0; i < 7; i++)
	{
		posx = 300;
		posy = posy + height + 10;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("stand blue rectangle.jpg");
		shape.push_back(temp);
	}

	posy = 10;
	for (int i = 0; i < 7; i++)
	{
		posx = 550;
		posy += height + 10;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("stand blue rectangle.jpg");
		shape.push_back(temp);
	}

	posy = 10;
	for (int i = 0; i < 7; i++)
	{
		posx = 600;
		posy += height + 10;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("stand blue rectangle.jpg");
		shape.push_back(temp);
	}

	posy = 370;
	posx = 300;
	width = 40;
	height = 40;
	for (int i = 0; i < 4; i++)
	{
		posx += width + 10;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("pink square.jpg");
		shape.push_back(temp);
	}

	posy = 320;
	posx = 300;
	width = 40;
	height = 40;
	for (int i = 0; i < 4; i++)
	{
		posx += width + 10;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("pink square.jpg");
		shape.push_back(temp);
	}
	
	radius = 35;
	posx = 650;
	posy = 15;
	for (int i = 0; i < 7; i++)
	{
		posy += 80;
		temp = new Triangle; 
		temp->setBrick(posx, posy, 3, radius, 0);
		temp->setTexture("red triangle.jpg");
		shape.push_back(temp);
	}
	level = 1;
}

void Grid::Level2()
{
	n = 0;
	int posx, posy, width, height, radius;
	Brick* temp;
	width = 70;
	height = 40;
	radius = 40;
	
	posx = 470;
	posy = 70;
	n += 2;
	for (int i = 0; i < 2; i++)
	{
		posy = posy + height + i + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie blue rectangle.jpg");
		shape.push_back(temp);
	}


	posx = 317;
	posy = 70;
	n += 2;
	for (int i = 0; i < 2; i++)
	{
		posy = posy + height + i + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie blue rectangle.jpg");
		shape.push_back(temp);
	}


	posx = 627;
	posy = 70;
	n += 2;
	for (int i = 0; i < 2; i++)
	{
		posy = posy + height + i + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie blue rectangle.jpg");
		shape.push_back(temp);
	}


	posx = 242;
	posy = 68;
	n += 5;
	for (int i = 0; i < 5; i++)
	{
		posx += width + i + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie blue rectangle.jpg");
		shape.push_back(temp);
	}


	posx = 242;
	posy = 208;
	n += 5;
	for (int i = 0; i < 5; i++)
	{
		posx += width + i + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie blue rectangle.jpg");
		shape.push_back(temp);
	}


	posx = 242;
	posy = 118;
	n += 6;
	for (int i = 0; i < 6; i++)
	{
		posy += height + i + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie blue rectangle.jpg");
		shape.push_back(temp);
	}

	posx = 165;
	posy = 118;
	n += 6;
	for (int i = 0; i < 6; i++)
	{
		posy += height + i + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie blue rectangle.jpg");
		shape.push_back(temp);
	}


	posx = 702;
	posy = 118;
	n += 6;
	for (int i = 0; i < 6; i++)
	{
		posy += height + i + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie blue rectangle.jpg");
		shape.push_back(temp);
	}


	posx = 778;
	posy = 118;
	n += 6;
	for (int i = 0; i < 6; i++)
	{
		posy += height + i + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie blue rectangle.jpg");
		shape.push_back(temp);
	}

	posx = 243;
	posy = 445;
	n += 5;
	for (int i = 0; i < 5; i++)
	{
		posx += width + i + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie blue rectangle.jpg");
		shape.push_back(temp);
	}


	posx = 243;
	posy = 492;
	n += 5;
	for (int i = 0; i < 5; i++)
	{
		posx += width + i + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie blue rectangle.jpg");
		shape.push_back(temp);
	}


	//ve rang
	posx = 252;
	posy = 380;
	n += 5;
	for (int i = 0; i < 5; i++)
	{
		posx += width + i;
		temp = new Triangle;
		temp->setBrick(posx, posy, 3, radius, 0);
		temp->setTexture("pink triangle.jpg");
		shape.push_back(temp);
	}


	//ve nuou
	posx = 280;
	posy = 252;
	n += 4;
	for (int i = 0; i < 4; i++)
	{
		posx += width + i + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie pink rectangle.jpg");
		shape.push_back(temp);
	}


	//ve rang
	posx = 227; 
	posy = 297;
	n += 2;
	for (int i = 0; i < 2; i++)
	{
		posx += width + i + 100;
		temp = new Rectangle;
		temp->setBrick(posx, posy, 50, 50, 0);
		temp->setTexture("pink square.jpg");
		shape.push_back(temp);
	}


	//ve chu L
	posx = 327;
	posy = 497;
	n += 2;
	width = 40;
	height = 70;
	for (int i = 0; i < 2; i++)
	{
		posy += height + i + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("stand red rectangle.jpg");
		shape.push_back(temp);
	}

	posx = 252;
	posy = 724;
	n += 2;
	width = 70;
	height = 40;
	for (int i = 0; i < 2; i++)
	{
		posx += width + i + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie red rectangle.jpg");
		shape.push_back(temp);
	}

	//ve chu V
	posx = 380;
	posy = 535;
	n += 4;
	width = 40;
	height = 40;
	for (int i = 0; i < 4; i++)
	{
		posx += width + i - 15;
		posy += height + i + 6;
		temp = new Rectangle;
		temp->setBrick(posx, posy, 40, 40, 0);
		temp->setTexture("red square.jpg");
		shape.push_back(temp);
	}


	posx = 580;
	posy = 535;
	n += 3;
	width = 40;
	height = 40;
	for (int i = 0; i < 3; i++)
	{
		posx -= width - i -15;
		posy += height + i + 6;
		temp = new Rectangle;
		temp->setBrick(posx, posy, 40, 40, 0);
		temp->setTexture("red square.jpg");
		shape.push_back(temp);
	}


	//ve so 2
	posx = 605;
	posy = 565;
	n += 1;
	width = 70;
	height = 40;
	temp = new Rectangle;
	temp->setBrick(posx, posy, width, height, 0);
	temp->setTexture("lie red rectangle.jpg");
	shape.push_back(temp);

	posx = 680;
	posy = 565;
	n += 1;
	temp = new Rectangle;
	temp->setBrick(posx, posy, 40, 40, 0);
	temp->setTexture("red square.jpg");
	shape.push_back(temp);

	posx = 680;
	posy = 610;
	n += 1;
	width = 40;
	height = 70;
	temp = new Rectangle;
	temp->setBrick(posx, posy, width, height, 0);
	temp->setTexture("stand red rectangle.jpg");
	shape.push_back(temp);


	posx = 605;
	posy = 650;
	n += 1;
	width = 70;
	height = 40;
	temp = new Rectangle;
	temp->setBrick(posx, posy, width, height, 0);
	temp->setTexture("lie red rectangle.jpg");
	shape.push_back(temp);


	posx = 604;
	posy = 695;
	n += 1;
	width = 40;
	height = 70;
	temp = new Rectangle;
	temp->setBrick(posx, posy, width, height, 0);
	temp->setTexture("stand red rectangle.jpg");
	shape.push_back(temp);


	posx = 648;
	posy = 724;
	n += 1;
	width = 70;
	height = 40;
	temp = new Rectangle;
	temp->setBrick(posx, posy, width, height, 0);
	temp->setTexture("lie red rectangle.jpg");
	shape.push_back(temp);


	//ve dau cham
	posx = 545;
	posy = 724;
	n += 1;
	temp = new Rectangle;
	temp->setBrick(posx, posy, 40, 40, 0);
	temp->setTexture("red square.jpg");
	shape.push_back(temp);
	level = 2;
}

void Grid::Reflex(Ball & ball, float &vx, float &vy)
{
	vector <Brick *> ::iterator it;
	for (it = shape.begin(); it != shape.end(); it++)
	{
		if ((*it)->getStatus() == 0)
		{
			bool collision = false;
			collision = (*it)->reflex(ball, vx, vy);
			if (collision)
			{
				(*it)->setStatus(-1);
			}
		}
		
	}
}

int Grid::getlevel()
{
	return level;
}

void Grid::setStatus(vector <int> status)
{
	for (int i = 0;i < n;i++)
	{
		shape[i]->setStatus(status[i]);
	}
}

vector <Brick *> Grid::getShape()
{
	return shape;
}
