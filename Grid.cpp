#include "Grid.h"

void Grid::draw(Paddle paddle, RenderWindow& window)
{
	for (int i = 0; i < n; i++)
	{
		shape[i]->draw(paddle, window);
	}
}

void Grid::Level1()
{
	n = 0;
	Brick* temp;
	int height, width, posx, posy, radius, dx, dy;
	posx = 0;
	posy = 0;
	dx = 10;
	dy = -70;
	width = 40;
	height = 20;
	radius = 25;

	//ve chu L thu 1
	n += 7;
	posx = dx + 50;
	posy = dy + 200;
	for (int i = 0; i < 7; i++)
	{
		posy += height + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie blue rectangle.jpg");
		if (i == 2)
		{
			temp->setItemForBrick(3);
		}
		if (i == 5)
		{
			temp->setItemForBrick(-3);
		}
		shape.push_back(temp);
	}

	n += 2;
	posx = dx + 50;
	posy = dy + 375;
	for (int i = 0; i < 2; i++)
	{
		posx += width + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie blue rectangle.jpg");
		if (i == 1)
		{
			temp->setItemForBrick(5);
		}
		shape.push_back(temp);
	}

	//ve chu E thu 1
	n += 7;
	posx = dx + 190;
	posy = dy + 200;
	for (int i = 0; i < 7; i++)
	{
		posy += height + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie pink rectangle.jpg");
		if (i == 1)
		{
			temp->setItemForBrick(-5);
		}
		if (i == 6)
		{
			temp->setItemForBrick(1);
		}
		shape.push_back(temp);
	}

	n += 2;
	posx = dx + 190;
	posy = dy + 225;
	for (int i = 0; i < 2; i++)
	{
		posx += width + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie pink rectangle.jpg");
		shape.push_back(temp);
	}

	n += 1;
	posx = dx + 190;
	posy = dy + 300;
	for (int i = 0; i < 1; i++)
	{
		posx += width + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie pink rectangle.jpg");
		shape.push_back(temp);
	}

	n += 2;
	posx = dx + 190;
	posy = dy + 375;
	for (int i = 0; i < 2; i++)
	{
		posx += width + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie pink rectangle.jpg");
		if (i == 1)
		{
			temp->setItemForBrick(-6);
		}
		shape.push_back(temp);
	}

	//ve chu V
	n += 7;
	posx = dx + 320;
	posy = dy + 200;
	for (int i = 0; i < 7; i++)
	{
		posx += 8;
		posy += height + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie orange rectangle.jpg");
		if (i == 2)
		{
			temp->setItemForBrick(6);
		}
		shape.push_back(temp);
	}

	n += 7;
	posx = dx + 470;
	posy = dy + 200;
	for (int i = 0; i < 7; i++)
	{
		posx -= 8;
		posy += height + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie orange rectangle.jpg");
		if (i == 5)
		{
			temp->setItemForBrick(-2);
		}
		shape.push_back(temp);
	}

	//ve chu E thu 2
	n += 7;
	posx = dx + 510;
	posy = dy + 200;
	for (int i = 0; i < 7; i++)
	{
		posy += height + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie pink rectangle.jpg");
		if (i == 1)
		{
			temp->setItemForBrick(-1);
		}
		if (i == 6)
		{
			temp->setItemForBrick(6);
		}
		shape.push_back(temp);
	}

	n += 2;
	posx = dx + 510;
	posy = dy + 225;
	for (int i = 0; i < 2; i++)
	{
		posx += width + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie pink rectangle.jpg");
		if (i == 0)
		{
			temp->setItemForBrick(1);
		}
		shape.push_back(temp);
	}

	n += 1;
	posx = dx + 510;
	posy = dy + 300;
	for (int i = 0; i < 1; i++)
	{
		posx += width + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie pink rectangle.jpg");
		shape.push_back(temp);
	}

	n += 2;
	posx = dx + 510;
	posy = dy + 375;
	for (int i = 0; i < 2; i++)
	{
		posx += width + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie pink rectangle.jpg");
		if (i == 1)
		{
			temp->setItemForBrick(3);
		}
		shape.push_back(temp);
	}

	//ve chu L thu 2
	n += 7;
	posx = dx + 650;
	posy = dy + 200;
	for (int i = 0; i < 7; i++)
	{
		posy += height + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie blue rectangle.jpg");
		if (i == 1)
		{
			temp->setItemForBrick(4);
		}
		if (i == 6)
		{
			temp->setItemForBrick(-3);
		}
		shape.push_back(temp);
	}

	n += 2;
	posx = dx + 650;
	posy = dy + 375;
	for (int i = 0; i < 2; i++)
	{
		posx += width + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie blue rectangle.jpg");
		if (i == 0)
		{
			temp->setItemForBrick(-1);
		}
		shape.push_back(temp);
	}

	//ve so 1

	n += 1;
	posx = dx + 755;
	posy = dy + 225;
	posx -= 10;
	posy += height + 5;
	temp = new Rectangle;
	temp->setBrick(posx, posy, width, height, 0);
	temp->setTexture("lie red rectangle.jpg");
	shape.push_back(temp);
		
	

	n += 7;
	posx = dx + 790;
	posy = dy + 200;
	for (int i = 0; i < 7; i++)
	{
		posy += height + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie red rectangle.jpg");
		if (i == 4)
		{
			temp->setItemForBrick(6);
		}
		if (i == 6)
		{
			temp->setItemForBrick(-3);
		}
		shape.push_back(temp);
	}
}



void Grid::Level2()
{
	n = 0;
	int posx, posy, width, height, radius;
	Brick* temp;
	width = 40;
	height = 20;
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
		temp->setTexture("lie green rectangle.jpg");
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
		temp->setTexture("lie pink rectangle.jpg");
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
		temp->setTexture("lie orange rectangle.jpg");
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
		temp->setTexture("lie orange rectangle.jpg");
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
}

void Grid::Level3()
{
	n = 0;
	int posx, posy, width, height, radius;
	Brick* temp;
	width = 70;
	height = 40;
	radius = 40;


	//mui craft
	posx = 480;
	posy = 85;
	radius = 40;
	n++;
	temp = new Triangle;
	temp->setBrick(posx, posy, 3, radius, 0);
	temp->setTexture("pink danger.jpg");
	shape.push_back(temp);

	//than scraft
	posx = 445;
	posy = 150;
	n += 8;
	for (int i = 0; i < 8; i++)
	{
		posy += height + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie blue rectangle.jpg");
		shape.push_back(temp);
	}

	posx = 520;
	posy = 150;
	n += 8;
	for (int i = 0; i < 8; i++)
	{
		posy += height + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie blue rectangle.jpg");
		shape.push_back(temp);
	}


	posx = 430;
	posy = 150;
	n += 2;
	for (int i = 0; i < 2; i++)
	{
		posx += height + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, height, height, 0);
		temp->setTexture("orange gift.jpg");
		shape.push_back(temp);
	}



	//canh phai
	posx = 595;
	posy = 202;
	n += 5;
	for (int i = 0; i < 5; i++)
	{
		posy += height + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, height, height, 0);
		temp->setTexture("pink square.jpg");
		shape.push_back(temp);
	}


	posx = 640;
	posy = 248;
	n += 4;
	for (int i = 0; i < 4; i++)
	{
		posy += height + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie pink rectangle.jpg");
		shape.push_back(temp);
	}


	posx = 715;
	posy = 295;
	n += 3;
	for (int i = 0; i < 3; i++)
	{
		posy += height + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie pink rectangle.jpg");
		shape.push_back(temp);
	}

	posx = 790;
	posy = 340;
	n += 2;
	for (int i = 0; i < 2; i++)
	{
		posy += height + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie pink rectangle.jpg");
		shape.push_back(temp);
	}


	//canh trai
	posx = 400;
	posy = 202;
	n += 5;
	for (int i = 0; i < 5; i++)
	{
		posy += height + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, height, height, 0);
		temp->setTexture("pink square.jpg");
		shape.push_back(temp);
	}


	posx = 325;
	posy = 248;
	n += 4;
	for (int i = 0; i < 4; i++)
	{
		posy += height + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie pink rectangle.jpg");
		shape.push_back(temp);
	}


	posx = 250;
	posy = 295;
	n += 3;
	for (int i = 0; i < 3; i++)
	{
		posy += height + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie pink rectangle.jpg");
		shape.push_back(temp);
	}

	posx = 173;
	posy = 340;
	n += 2;
	for (int i = 0; i < 2; i++)
	{
		posy += height + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie pink rectangle.jpg");
		shape.push_back(temp);
	}


	//duoi craft
	posx = 430;
	posy = 555;
	n += 2;
	for (int i = 0; i < 2; i++)
	{
		posx += height + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, height, height, 0);
		temp->setTexture("green gift.jpg");
		shape.push_back(temp);
	}


	posx = 380;
	posy = 595;
	n += 2;
	for (int i = 0; i < 2; i++)
	{
		posx += height + 25;
		temp = new Triangle;
		temp->setBrick(posx, posy, 3, radius, 0);
		temp->setTexture("green danger.jpg");
		shape.push_back(temp);
	}

	posx = 350;
	posy = 655;
	n += 3;
	for (int i = 0; i < 3; i++)
	{
		posx += height + 25;
		temp = new Triangle;
		temp->setBrick(posx, posy, 3, radius, 0);
		temp->setTexture("green danger.jpg");
		shape.push_back(temp);
	}
}

void Grid::moveLeftAndRight(float &vx, int windowWidth)
{
	for (int i = 0; i < shape.size(); i++)
	{
		shape[i]->moveLeftAndRight(vx);
	}

	Vector2f position2 = shape[shape.size() - 1]->getPositionxy();
	Vector2f position1 = shape[0]->getPositionxy();
	if (position1.x < -100 || position2.x >windowWidth + 100)
	{
		vx = -vx;
		if (fabs(vx) < 3)
		{
			vx = vx * 1.02;
			cout << vx << endl;
		}
		     
	}
}

void Grid::moveDown(float& vy, int windowHeight)
{
	for (int i = 0; i < shape.size(); i++)
	{
		shape[i]->moveDown(vy);
	}
}

void Grid::Reflex(Ball& ball, float& vx, float& vy)
{
	vector <Brick*> ::iterator it;
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