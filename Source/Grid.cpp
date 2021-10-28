#include "Grid.h"

void Grid::draw(Paddle &paddle, RenderWindow& window)
{
	for (int i = 0; i < shape.size(); i++)
	{
		shape[i]->draw(paddle, window); // ve tung vien gach len man hinh
	}
}

int Grid::getNumOfElements()
{
	return n;
}

void Grid::Level1()
{
	level = 1;
	shape.empty();
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
			temp->setItemForBrick(0);
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

	shape[2]->setItemForBrick(0);
	shape[10]->setItemForBrick(0);
	shape[30]->setItemForBrick(0);
	shape[35]->setItemForBrick(0);
}

void Grid::Level2()
{
	level = 2;
	shape.empty();
	n = 0;
	Brick* temp;
	int height, width, posx, posy, radius, dx, dy;
	posx = 0;
	posy = 0;
	dx = 90;
	dy = -70;
	width = 40;
	height = 20;
	radius = 25;

	//ve so 2
	n += 3;
	posx = dx + 40;
	posy = dy + 220;
	for (int i = 0; i < 3; i++)
	{
		posx += width + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie blue rectangle.jpg");
		if (i == 0)
		{
			temp->setItemForBrick(2);
		}
		shape.push_back(temp);
	}

	n += 3;
	posx = dx + 175;
	posy = dy + 220;
	for (int i = 0; i < 3; i++)
	{
		posy += height + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie blue rectangle.jpg");
		if (i == 1)
		{
			temp->setItemForBrick(-4);
		}
		shape.push_back(temp);
	}

	n += 2;
	posx = dx + 40;
	posy = dy + 295;
	for (int i = 0; i < 2; i++)
	{
		posx += width + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie blue rectangle.jpg");
		if (i == 1)
		{
			temp->setItemForBrick(6);
		}
		shape.push_back(temp);
	}

	n += 2;
	posx = dx + 85;
	posy = dy + 295;
	for (int i = 0; i < 2; i++)
	{
		posy += height + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie blue rectangle.jpg");
		if (i == 0)
		{
			temp->setItemForBrick(-3);
		}
		shape.push_back(temp);
	}

	n += 2;
	posx = dx + 85;
	posy = dy + 345;
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

	//ve so 0
	n += 3;
	posx = dx + 185;
	posy = dy + 220;
	for (int i = 0; i < 3; i++)
	{
		posx += width + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie pink rectangle.jpg");
		if (i == 1)
		{
			temp->setItemForBrick(6);
		}
		shape.push_back(temp);
	}

	n += 3;
	posx = dx + 185;
	posy = dy + 345;
	for (int i = 0; i < 3; i++)
	{
		posx += width + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie pink rectangle.jpg");
		if (i == 2)
		{
			temp->setItemForBrick(-2);
		}
		shape.push_back(temp);
	}

	n += 4;
	posx = dx + 230;
	posy = dy + 220;
	for (int i = 0; i < 4; i++)
	{
		posy += height + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie pink rectangle.jpg");
		if (i == 3)
		{
			temp->setItemForBrick(3);
		}
		shape.push_back(temp);
	}

	n += 4;
	posx = dx + 320;
	posy = dy + 220;
	for (int i = 0; i < 4; i++)
	{
		posy += height + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie pink rectangle.jpg");
		if (i == 3)
		{
			temp->setItemForBrick(-1);
		}
		shape.push_back(temp);
	}

	//ve so 2 thu 2
	n += 3;
	posx = dx + 330;
	posy = dy + 220;
	for (int i = 0; i < 3; i++)
	{
		posx += width + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie orange rectangle.jpg");
		if (i == 1)
		{
			temp->setItemForBrick(4);
		}
		shape.push_back(temp);
	}

	n += 3;
	posx = dx + 465;
	posy = dy + 220;
	for (int i = 0; i < 3; i++)
	{
		posy += height + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie orange rectangle.jpg");
		if (i == 2)
		{
			temp->setItemForBrick(-4);
		}
		shape.push_back(temp);
	}

	n += 2;
	posx = dx + 330;
	posy = dy + 295;
	for (int i = 0; i < 2; i++)
	{
		posx += width + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie orange rectangle.jpg");
		if (i == 1)
		{
			temp->setItemForBrick(3);
		}
		shape.push_back(temp);
	}

	n += 2;
	posx = dx + 375;
	posy = dy + 295;
	for (int i = 0; i < 2; i++)
	{
		posy += height + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie orange rectangle.jpg");
		if (i == 0)
		{
			temp->setItemForBrick(-2);
		}
		shape.push_back(temp);
	}

	n += 2;
	posx = dx + 375;
	posy = dy + 345;
	for (int i = 0; i < 2; i++)
	{
		posx += width + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie orange rectangle.jpg");
		if (i == 0)
		{
			temp->setItemForBrick(1);
		}
		shape.push_back(temp);
	}

	//ve so 0 thu 2
	n += 3;
	posx = dx + 475;
	posy = dy + 220;
	for (int i = 0; i < 3; i++)
	{
		posx += width + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie red rectangle.jpg");
		if (i == 2)
		{
			temp->setItemForBrick(-5);
		}
		shape.push_back(temp);
	}

	n += 3;
	posx = dx + 475;
	posy = dy + 345;
	for (int i = 0; i < 3; i++)
	{
		posx += width + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie red rectangle.jpg");
		if (i == 1)
		{
			temp->setItemForBrick(6);
		}
		shape.push_back(temp);
	}

	n += 4;
	posx = dx + 520;
	posy = dy + 220;
	for (int i = 0; i < 4; i++)
	{
		posy += height + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie red rectangle.jpg");
		if (i == 3)
		{
			temp->setItemForBrick(-3);
		}
		shape.push_back(temp);
	}

	n += 4;
	posx = dx + 610;
	posy = dy + 220;
	for (int i = 0; i < 4; i++)
	{
		posy += height + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie red rectangle.jpg");
		if (i == 3)
		{
			temp->setItemForBrick(2);
		}
		shape.push_back(temp);
	}

	//ve hang tam giac cuoi cung
	n += 12;
	posx = dx + 50;
	posy = dy + 380;
	for (int i = 0; i < 12; i++)
	{
		posx += 45;
		temp = new Triangle;
		temp->setBrick(posx, posy, 3, 25, 0);
		temp->setTexture("blue triangle.jpg");
		/*if (i == 0)
		{
			temp->setItemForBrick(6);
		}
		if (i == 3)
		{
			temp->setItemForBrick(-4);
		}
		if (i == 6)
		{
			temp->setItemForBrick(5);
		}*/
		if (i == 9)
		{
			temp->setItemForBrick(0);
		}
		if (i == 10)
		{
			temp->setItemForBrick(0);
		}
		//temp->setItemForBrick(0);
		shape.push_back(temp);
	}
}

void Grid::Level3()
{
	level = 3;
	shape.empty();
	n = 0;
	Brick* temp;
	int height, width, posx, posy, radius, dx, dy, side;
	posx = 0;
	posy = 0;
	dx = 0;
	dy = 0;
	width = 40;
	height = 20;
	radius = 25;
	side = 20;

	//ve trai tim thu nhat
	n += 2;
	posx = dx + 100;
	posy = dy + 195;
	for (int i = 0; i < 2; i++)
	{
		posx += width + 50;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie red rectangle.jpg");
		shape.push_back(temp);
		if (i == 0)
		{
			temp->setItemForBrick(1);
		}
	}

	n += 5;
	posx = dx + 100;
	posy = dy + 220;
	for (int i = 0; i < 5; i++)
	{
		posx += width + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie red rectangle.jpg");
		if (i == 1)
		{
			temp->setItemForBrick(-1);
		}
		shape.push_back(temp);
	}

	n += 5;
	posx = dx + 100;
	posy = dy + 245;
	for (int i = 0; i < 5; i++)
	{
		posx += width + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie red rectangle.jpg");
		if (i == 3)
		{
			temp->setItemForBrick(6);
		}
		shape.push_back(temp);
	}

	n += 5;
	posx = dx + 100;
	posy = dy + 270;
	for (int i = 0; i < 5; i++)
	{
		posx += width + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie red rectangle.jpg");
		if (i == 4)
		{
			temp->setItemForBrick(0);
		}
		shape.push_back(temp);
	}

	n += 3;
	posx = dx + 145;
	posy = dy + 295;
	for (int i = 0; i < 3; i++)
	{
		posx += width + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie red rectangle.jpg");
		if (i == 2)
		{
			temp->setItemForBrick(-6);
		}
		shape.push_back(temp);
	}

	n += 1;
	posx = dx + 190;
	posy = dy + 320;
	for (int i = 0; i < 1; i++)
	{
		posx += width + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie red rectangle.jpg");
		shape.push_back(temp);
	}

	//ve trai tim thu hai
	dx += 400;
	n += 2;
	posx = dx + 100;
	posy = dy + 195;
	for (int i = 0; i < 2; i++)
	{
		posx += width + 50;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie pink rectangle.jpg");
		if (i == 0)
		{
			temp->setItemForBrick(4);
		}
		shape.push_back(temp);
	}

	n += 5;
	posx = dx + 100;
	posy = dy + 220;
	for (int i = 0; i < 5; i++)
	{
		posx += width + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie pink rectangle.jpg");
		if (i == 3)
		{
			temp->setItemForBrick(-2);
		}
		shape.push_back(temp);
	}

	n += 5;
	posx = dx + 100;
	posy = dy + 245;
	for (int i = 0; i < 5; i++)
	{
		posx += width + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie pink rectangle.jpg");
		if (i == 4)
		{
			temp->setItemForBrick(6);
		}
		shape.push_back(temp);
	}

	n += 5;
	posx = dx + 100;
	posy = dy + 270;
	for (int i = 0; i < 5; i++)
	{
		posx += width + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie pink rectangle.jpg");
		if (i == 2)
		{
			temp->setItemForBrick(0);
		}
		shape.push_back(temp);
	}

	n += 3;
	posx = dx + 145;
	posy = dy + 295;
	for (int i = 0; i < 3; i++)
	{
		posx += width + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie pink rectangle.jpg");
		shape.push_back(temp);
	}

	n += 1;
	posx = dx + 190;
	posy = dy + 320;
	for (int i = 0; i < 1; i++)
	{
		posx += width + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie pink rectangle.jpg");
		shape.push_back(temp);
	}

	//ve hang hinh chu nhat ben duoi
	n += 12;
	posx = dx - 255;
	posy = dy + 370;
	for (int i = 0; i < 12; i++)
	{
		posx += width + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, width, height, 0);
		temp->setTexture("lie blue rectangle.jpg");
		if (i == 2)
		{
			temp->setItemForBrick(5);
		}
		if (i == 6)
		{
			temp->setItemForBrick(-2);
		}
		if (i == 10)
		{
			temp->setItemForBrick(4);
		}
		shape.push_back(temp);
	}


	//cai dat so cho moi vien gach
	int number;
	for (int i = 0; i < shape.size(); i++)
	{
		number = random(1, 5);
		shape[i]->setNumber(number);
	}
}

void Grid::Level4()
{
	level = 4;
	shape.empty();
	n = 0;
	Brick* temp;
	int height, width, posx, posy, radius, dx, dy, side;
	posx = 0;
	posy = 0;
	dx = 80;
	dy = 0;
	width = 40;
	height = 20;
	radius = 25;
	side = 20;

	//ve khung da ben ngoai
	n += 6;
	posx = dx + 100;
	posy = dy + 220;
	for (int i = 0; i < 6; i++)
	{
		posy += side + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, side, side, -2);
		temp->setTexture("stone brick.jpg");
		shape.push_back(temp);
	}

	n += 2;
	posx = dx + 225;
	posy = dy + 220;
	for (int i = 0; i < 2; i++)
	{
		posy += side + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, side, side, -2);
		temp->setTexture("stone brick.jpg");
		shape.push_back(temp);
	}

	n += 2;
	posx = dx + 225;
	posy = dy + 320;
	for (int i = 0; i < 2; i++)
	{
		posy += side + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, side, side, -2);
		temp->setTexture("stone brick.jpg");
		shape.push_back(temp);
	}

	n += 4;
	posx = dx + 100;
	posy = dy + 245;
	for (int i = 0; i < 4; i++)
	{
		posx += side + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, side, side, -2);
		temp->setTexture("stone brick.jpg");
		shape.push_back(temp);
	}

	n += 1;
	posx = dx + 100;
	posy = dy + 370;
	for (int i = 0; i < 1; i++)
	{
		posx += side + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, side, side, -2);
		temp->setTexture("stone brick.jpg");
		shape.push_back(temp);
	}

	n += 1;
	posx = dx + 175;
	posy = dy + 370;
	for (int i = 0; i < 1; i++)
	{
		posx += side + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, side, side, -2);
		temp->setTexture("stone brick.jpg");
		shape.push_back(temp);
	}

	n += 2;
	posx = dx + 225;
	posy = dy + 270;
	for (int i = 0; i < 2; i++)
	{
		posx += side + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, side, side, -2);
		temp->setTexture("stone brick.jpg");
		shape.push_back(temp);
	}

	n += 2;
	posx = dx + 225;
	posy = dy + 345;
	for (int i = 0; i < 2; i++)
	{
		posx += side + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, side, side, -2);
		temp->setTexture("stone brick.jpg");
		shape.push_back(temp);
	}

	n += 2;
	posx = dx + 300;
	posy = dy + 220;
	for (int i = 0; i < 2; i++)
	{
		posy += side + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, side, side, -2);
		temp->setTexture("stone brick.jpg");
		shape.push_back(temp);
	}

	n += 2;
	posx = dx + 300;
	posy = dy + 320;
	for (int i = 0; i < 2; i++)
	{
		posy += side + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, side, side, -2);
		temp->setTexture("stone brick.jpg");
		shape.push_back(temp);
	}

	n += 1;
	posx = dx + 300;
	posy = dy + 245;
	for (int i = 0; i < 1; i++)
	{
		posx += side + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, side, side, -2);
		temp->setTexture("stone brick.jpg");
		shape.push_back(temp);
	}

	n += 1;
	posx = dx + 300;
	posy = dy + 370;
	for (int i = 0; i < 1; i++)
	{
		posx += side + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, side, side, -2);
		temp->setTexture("stone brick.jpg");
		shape.push_back(temp);
	}

	n += 1;
	posx = dx + 380;
	posy = dy + 370;
	for (int i = 0; i < 1; i++)
	{
		posx += side + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, side, side, -2);
		temp->setTexture("stone brick.jpg");
		shape.push_back(temp);
	}

	n += 1;
	posx = dx + 380;
	posy = dy + 245;
	for (int i = 0; i < 1; i++)
	{
		posx += side + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, side, side, -2);
		temp->setTexture("stone brick.jpg");
		shape.push_back(temp);
	}

	n += 2;
	posx = dx + 430;
	posy = dy + 220;
	for (int i = 0; i < 2; i++)
	{
		posy += side + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, side, side, -2);
		temp->setTexture("stone brick.jpg");
		shape.push_back(temp);
	}

	n += 2;
	posx = dx + 430;
	posy = dy + 320;
	for (int i = 0; i < 2; i++)
	{
		posy += side + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, side, side, -2);
		temp->setTexture("stone brick.jpg");
		shape.push_back(temp);
	}

	n += 2;
	posx = dx + 430;
	posy = dy + 270;
	for (int i = 0; i < 2; i++)
	{
		posx += side + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, side, side, -2);
		temp->setTexture("stone brick.jpg");
		shape.push_back(temp);
	}

	n += 2;
	posx = dx + 430;
	posy = dy + 345;
	for (int i = 0; i < 2; i++)
	{
		posx += side + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, side, side, -2);
		temp->setTexture("stone brick.jpg");
		shape.push_back(temp);
	}

	n += 2;
	posx = dx + 505;
	posy = dy + 220;
	for (int i = 0; i < 2; i++)
	{
		posy += side + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, side, side, -2);
		temp->setTexture("stone brick.jpg");
		shape.push_back(temp);
	}

	n += 2;
	posx = dx + 505;
	posy = dy + 320;
	for (int i = 0; i < 2; i++)
	{
		posy += side + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, side, side, -2);
		temp->setTexture("stone brick.jpg");
		shape.push_back(temp);
	}

	n += 2;
	posx = dx + 580;
	posy = dy + 370;
	for (int i = 0; i < 2; i++)
	{
		posx += side + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, side, side, -2);
		temp->setTexture("stone brick.jpg");
		shape.push_back(temp);
	}

	n += 1;
	posx = dx + 505;
	posy = dy + 370;
	for (int i = 0; i < 1; i++)
	{
		posx += side + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, side, side, -2);
		temp->setTexture("stone brick.jpg");
		shape.push_back(temp);
	}

	n += 5;
	posx = dx + 505;
	posy = dy + 245;
	for (int i = 0; i < 5; i++)
	{
		posx += side + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, side, side, -2);
		temp->setTexture("stone brick.jpg");
		shape.push_back(temp);
	}

	n += 4;
	posx = dx + 630;
	posy = dy + 245;
	for (int i = 0; i < 4; i++)
	{
		posy += side + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, side, side, -2);
		temp->setTexture("stone brick.jpg");
		shape.push_back(temp);
	}

	//ve cac gach trong o hinh vuong thu nhat
	n += 3;
	posx = dx + 140;
	posy = dy + 260;
	for (int i = 0; i < 3; i++)
	{
		posy += side + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, side, side, 0);
		temp->setTexture("blue square.jpg");
		shape.push_back(temp);
	}

	n += 3;
	posx = dx + 165;
	posy = dy + 260;
	for (int i = 0; i < 3; i++)
	{
		posy += side + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, side, side, 0);
		temp->setTexture("blue square.jpg");
		shape.push_back(temp);
	}

	n += 3;
	posx = dx + 190;
	posy = dy + 260;
	for (int i = 0; i < 3; i++)
	{
		posy += side + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, side, side, 0);
		temp->setTexture("blue square.jpg");
		shape.push_back(temp);
	}

	//ve cac gach trong o hinh vuong thu hai
	dx += 200;
	n += 3;
	posx = dx + 140;
	posy = dy + 260;
	for (int i = 0; i < 3; i++)
	{
		posy += side + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, side, side, 0);
		temp->setTexture("blue square.jpg");
		shape.push_back(temp);
	}

	n += 3;
	posx = dx + 165;
	posy = dy + 260;
	for (int i = 0; i < 3; i++)
	{
		posy += side + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, side, side, 0);
		temp->setTexture("blue square.jpg");
		shape.push_back(temp);
	}

	n += 3;
	posx = dx + 190;
	posy = dy + 260;
	for (int i = 0; i < 3; i++)
	{
		posy += side + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, side, side, 0);
		temp->setTexture("blue square.jpg");
		shape.push_back(temp);
	}

	//ve cac gach trong o hinh vuong thu ba
	dx += 200;
	n += 3;
	posx = dx + 140;
	posy = dy + 260;
	for (int i = 0; i < 3; i++)
	{
		posy += side + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, side, side, 0);
		temp->setTexture("blue square.jpg");
		shape.push_back(temp);
	}

	n += 3;
	posx = dx + 165;
	posy = dy + 260;
	for (int i = 0; i < 3; i++)
	{
		posy += side + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, side, side, 0);
		temp->setTexture("blue square.jpg");
		shape.push_back(temp);
	}

	n += 3;
	posx = dx + 190;
	posy = dy + 260;
	for (int i = 0; i < 3; i++)
	{
		posy += side + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, side, side, 0);
		temp->setTexture("blue square.jpg");
		shape.push_back(temp);
	}

	//ve day hinh vuong phia tren
	n += 20;
	posx = dx - 300;
	posy = dy + 200;
	for (int i = 0; i < 20; i++)
	{
		posx += side + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, side, side, 0);
		temp->setTexture("blue square.jpg");
		shape.push_back(temp);
	}

	n += 20;
	posx = dx - 300;
	posy = dy + 175;
	for (int i = 0; i < 20; i++)
	{
		posx += side + 5;
		temp = new Rectangle;
		temp->setBrick(posx, posy, side, side, 0);
		temp->setTexture("blue square.jpg");
		shape.push_back(temp);
	}
}

void Grid::moveLeftAndRight(float &vx, int windowWidth)  //dich chuyen trong level 2
{
	if (level == 2)
	{
		for (int i = 0; i < shape.size(); i++)
		{
			shape[i]->moveLeftAndRight(vx); // tung vien gach dich chuyen
		}

		Vector2f position2 = shape[shape.size() - 1]->getPositionxy();
		Vector2f position1 = shape[0]->getPositionxy();
		if (position1.x < 50 || position2.x >windowWidth -100) // xet khong gian di chuyen
		{	
			vx = -vx;
			if (fabs(vx) < 3)
			{
				vx = vx * 1.02;
			}

		}
	}
	
}

void Grid::moveDown(float vy, int windowHeight)
{
	if (level == 3) // chi thuc hien khi level 3
	{
		for (int i = 0; i < shape.size(); i++)
		{
			shape[i]->moveDown(vy);
		}
	}
}

bool Grid::Reflex(Ball& ball, float& vx, float& vy, Paddle & paddle)
{
	if (ball.getGlobalBounds().top < 400 || level ==3) // gioi han khong gian chay vong lap de thuc hien nhanh hon
	{
		vector <Brick*> ::iterator it;
		for (it = shape.begin(); it != shape.end(); it++) // duyet tung vien gach
		{
			if ((*it)->getStatus() != -1) // chi xet khi status =-1
			{
				bool collision = false; // bien va cham 
				collision = (*it)->reflex(ball, vx, vy, paddle); // kiem tra xem co va cham khong
				if (collision)
				{
					if ((*it)->getStatus() == 0)  // kiem tra xem trang thai cua vien gach
					{
						if ((*it)->getNumber() == 0) // kiem tra co so cua vien gach
						{
							(*it)->setStatus(-1); // cai dat lai trang thai cua vien gach
						}
						paddle.setScore(paddle.getScore() + 1); // tinh diem cho paddle
					}
					return true;
				}
			}

		}
	}
	return false;
	
}

vector <Brick*> Grid::getShape()
{
	return shape;// dung trong save game
}

int Grid::getlevel()
{
	return level; // tra ve level hien tai
}

void Grid::hitBullet(GunMode& gun, Paddle & paddle) // vien dam cham gach
{
	for (int i = 0; i < gun.bulletList.size(); i++)
	{
		vector <Brick*> ::iterator it;
		for (it = shape.begin(); it != shape.end(); it++)
		{
			if ((*it)->getStatus() == 0)
			{
				bool collision = false;
				collision = (*it)->isHitBullet(gun.bulletList[i]); // dieu kien va cham
				if (collision) 
				{
					
					if ((*it)->getNumber() == 0) // gach binh thuong
					{
						(*it)->setStatus(-1);
					}
					else
					{
						(*it)->changeNumber((*it)->getNumber() - 1); // gach co co so trong lvel 3
						if ((*it)->getNumber() == 0)
						{
							(*it)->setStatus(-1); // dat lai trang thai
						}
					}
					paddle.setScore(paddle.getScore() + 1); // tinh diem
				}
			}

		}
	}
}

int Grid::getRemainAmount( float y) // tra ve so luong gach con lai
{
	
	if (y <= 400 || level==3)
	{
		int count = 0;
		for (int i = 0; i < shape.size();i++)
		{
			if (shape[i]->getStatus() == 0)
			{
				count++;
			}
		}
		return count;
	}
	return -1;
}

int Grid::random(int a, int b)
{
	return a + (b - a)*rand() / RAND_MAX;
}

void Grid::setStatus(vector <int> status)
{
	for (int i = 0;i < shape.size();i++)
	{
		shape[i]->setStatus(status[i]); // thiet lap status cho toan bo gach (dung trong save)
	}
}

void Grid::setStatusItem(vector <float> item_x, vector <float> item_y, vector <int> item_status)
{ 
	// thiet lap status cho toan bo item
	for (int i = 0;i < shape.size(); i++)
	{
		shape[i]->setStatusForItem(item_status[i]);
		shape[i]->setPositionForItem({ item_x[i], item_y[i] });
	}
}

void Grid::setNumber(vector <int> list_num)
{
	// thiet lap co so cho toan bo gach
	for (int i = 0;i < shape.size(); i++)
	{
		shape[i]->setNumber(list_num[i]);
	}
}