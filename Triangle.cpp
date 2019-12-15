#include "Triangle.h"
#include "Rectangle.h"


void Triangle::setBrick(float startX, float startY, float a, float b, int stt)
{
	position.x = startX;
	position.y = startY;
	height = 1.5 * b;
	baseSize = a;
	radius = b;
	shape.setPointCount(a);
	shape.setRadius(b);
	shape.setPosition(position);
	status = stt;
}

void Triangle::setTexture(string textureName)
{
	texture.loadFromFile(textureName);
	shape.setTexture(&texture);
}

FloatRect Triangle::getPosition()
{
	return shape.getGlobalBounds();
}

Vector2f Triangle::getPositionxy()
{
	return Vector2f(position.x, position.y);
}

int Triangle::getStatus()
{
	return status;
}

void Triangle::setPosition(float newPosx, float newPosy)
{
	position.x = newPosx;
	position.y = newPosy;
}

void Triangle::setNumber(int num)
{
	float x, y;
	number = num;
	font.loadFromFile("iCielPanton-Black.otf");
	text.setString(to_string(number));
	text.setCharacterSize(20);
	text.setFont(font);
	text.setFillColor(Color::Yellow);
	//chinh cho text nam o giua hinh tam giac
	x = (baseSize / 2 + getPosition().left) - (text.getGlobalBounds().width / 2) + radius/1.2;
	y = (height / 2 + getPosition().top) - (text.getGlobalBounds().height / 2);
	text.setPosition({ x,y });
}

void Triangle::setStatus(int stt)
{
	status = stt;
}

void Triangle::setItemForBrick(int type)
{
	string name = to_string(type) + ".png";
	item.setItem(position.x, position.y, name, type, -1);
}

CircleShape Triangle::getShape()
{
	return shape;
}

void Triangle::draw(Paddle &paddle, RenderWindow& window)
{
	if (status != -1)
	{
		window.draw(getShape());
	}
	else
	{
		if (item.getStatus() != -2)
		{
			item.setStatus(0);//cho item xuat hien khi vat the bien mat
		}
		item.moveDown(0.2, 770);
		if (isItemHitPaddle(paddle) != -10)//neu item cham paddle
		{
			item.setStatus(-2);//cho item bien mat vinh vien
		}
		if (item.getPosition().top > 770)//neu item di den cuoi man hinh thi se vinh vien bien mat
		{
			item.setStatus(-2);
		}
		item.draw(window);
	}
	//truong hop hung duoc vat pham ban sung
	if (isItemHitPaddle(paddle) == 0)
	{
		paddle.isOnGunMode = true;
	}
	if (number != 0)
	{
		window.draw(text);
	}
}

void Triangle::moveLeftAndRight(float vx)
{
	position.x += vx;
	shape.setPosition(position);
}

void Triangle::moveDown(float vy)
{
	position.y += vy;
	shape.setPosition(position);
}

bool Triangle::reflex(Ball& ball, float& vx, float& vy, Paddle & paddle)
{
	point2D a, b, c;

	//toa do hinh tam giac
	float x0 = getPosition().left;
	float x1 = x0 + getPosition().width;
	float y0 = getPosition().top;
	float y1 = y0 + getPosition().height;

	// toa do trai banh
	float bx0 = ball.getPosition().left;
	float bx1 = bx0 + ball.getPosition().width;
	float by0 = ball.getPosition().top;
	float by1 = by0 + ball.getPosition().height;

	// dinh cua tam giac
	a.x = x0 + getPosition().width / 2.0;
	a.y = y0;

	// diem ben trai cua tam giac
	b.x = a.x - getPosition().height *sqrt(3) / 4.0;
	b.y = y0 + getPosition().height*0.75;

	// diem ben phai cua tam giac
	c.x = a.x + getPosition().height *sqrt(3) / 4;
	c.y = y0 + getPosition().height*0.75;


	bool collision = false;

	point2D _pBall;
	_pBall.x = bx1 + vx;
	_pBall.y = by1 + vy;

	if (AreaTriangle(a, b, c) +20 >= AreaTriangle(a, b, _pBall) + AreaTriangle(c, b, _pBall) + AreaTriangle(a, c, _pBall))
	{
		collision = true;
	}

	_pBall.x = bx0 + vx;
	_pBall.y = by1 + vy;

	if (AreaTriangle(a, b, c) +20 >= AreaTriangle(a, b, _pBall) + AreaTriangle(c, b, _pBall) + AreaTriangle(a, c, _pBall))
	{
		collision = true;
	}

	_pBall.x = bx1 + vx;
	_pBall.y = by0 + vy;

	if (AreaTriangle(a, b, c)+20  >= AreaTriangle(a, b, _pBall) + AreaTriangle(c, b, _pBall) + AreaTriangle(a, c, _pBall))
	{
		collision = true;
	}

	_pBall.x = bx0 + vx;
	_pBall.y = by0 + vy;

	if (AreaTriangle(a, b, c)+20 >= AreaTriangle(a, b, _pBall) + AreaTriangle(c, b, _pBall) + AreaTriangle(a, c, _pBall))
	{
		collision = true;
	}

	if (shape.getGlobalBounds().intersects(ball.getGlobalBounds()))
	{
		
		
		if (collision)
		{
			if (((by0 + vy <= y0 + getPosition().height ) && (by1 + vy >= y0 + getPosition().height))) // xet 3 vi tri phia duoi
			{
				if (bx1 + vx >= b.x && bx0 + vx <= c.x )
				/*if (bx1 + vx >= x0 && bx0 + vx <= x0) //xet vi tri ben trai goc duoi
				{
					if (vy >= 0) // va cham ben trai
					{
						cout << "trai duoi" << endl;
						vx = -vx;
					}
				}
				else if (bx0 + vx <= x1 && bx1 + vx >= x1) // xet vi tri ben phai goc duoi cung
				{
					/*if (vy > 0) // va cham canh ben phai cua gach
					{
						vx = -vx;
						cout << "phai  duoi" << endl;
					}
					vy = -vy;
				}
				else // va chamm phia duoi
				{
					cout << "ben duoi" << endl;
					vy = -vy;
				}*/
				vy = -vy; // phia duoi
			}
			else if (by0 + vy <= y0 && by1 + vy >= y0)// xet dinh tam giac
			{
				if (vy >= 0) // va cham phia tren
				{
					/*if (vx >= 0) // va cham ben trai
					{
						cout << " trai dinh tren" << endl;
						vx = -vx;
					}
					else // va cham ben phai
					{
						cout << "pahi dinh duoi" << endl;
						vx = -vx;
					}*/
					vy = -vy;
				}
				else // xet va cham trai phai
				{
					if (vx >= 0) // va cham ben trai
					{
						cout << "trai" << endl;
						vx = -vx;
					}
					else // va cham ben phai
					{
						cout << "phai" << endl;
						vx = -vx;
					}
				}
			}
			else // xet hai canh ben tam giac
			{
				if (vx >= 0) // va cham ben trai
				{
					float v = sqrt(vx * vx + vy * vy);
					float pi = 3.141592654;
					float goc = atan((float)fabs(vy) / fabs(vx));
					vx = -cos(pi / 6 - goc) * v;
					vy = sin(pi / 6 - goc) * v;	
				}
				else // va cham ben phai
				{
					float v = sqrt(vx * vx + vy * vy);
					float pi = 3.141592654;
					float goc = atan((float)fabs(vy) / fabs(vx));
					vx = -cos(pi / 6 - goc) * v;
					vy = sin(pi / 6 - goc) * v;
				}
			}
			return true;
		}
	}
	return false;
}

int Triangle::isItemHitPaddle(Paddle paddle)
{
	if (item.getPosition().intersects(paddle.getPosition()))
	{
		return item.getType();//dua ra so diem khi hung duoc item
	}
	return -10;//truong hop item khong cham paddle
}

bool Triangle::isHitBullet(Bullet bullet)
{
	if (bullet.getPosition().intersects(getPosition()))
	{
		return true;
	}
	return false;
}

float Triangle::AreaTriangle(point2D a, point2D b, point2D c)
{
	float ab = sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
	float bc = sqrt((c.x - b.x)*(c.x - b.x) + (c.y - b.y)*(c.y - b.y));
	float ac = sqrt((a.x - c.x)*(a.x - c.x) + (a.y - c.y)*(a.y - c.y));
	float  p = (ab + ac + bc)/2;
	float s = sqrt(p* (p - ab)*(p - ac)*(p - bc));
	return s;
}

int Triangle::getNumber()
{
	return number;
}

void Triangle::changeNumber(int num)
{
	text.setString(to_string(num));
}

Item Triangle::getItem()
{
	return item;
}

void Triangle ::setStatusForItem(int status)
{
	item.setStatus(status);
}

void Triangle ::setPositionForItem(Vector2f pos)
{
	item.setPosition(pos.x, pos.y);
}

