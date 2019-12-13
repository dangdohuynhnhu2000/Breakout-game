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

void Triangle::changeNumber(int num)
{
	text.setString(to_string(num));
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

int Triangle::getNumber()
{
	return number;
}

void Triangle::draw(Paddle& paddle, RenderWindow& window)
{
	if (status == 0)
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

bool Triangle::reflex(Ball& ball, float& vx, float& vy)
{
	if (shape.getGlobalBounds().intersects(ball.getGlobalBounds()))
	{
		float x0 = getPosition().left;
		float x1 = x0 + getPosition().width;
		float y0 = getPosition().top;
		float y1 = y0 + getPosition().height;

		float bx0 = ball.getPosition().left;
		float bx1 = bx0 + ball.getPosition().width;
		float by0 = ball.getPosition().top;
		float by1 = by0 + ball.getPosition().height;

		if ((by0 + vy <= y0 + getPosition().height * 3 / 4) && (by1 + vy >= y0 + getPosition().height * 3 / 4)) // xet 3 vi tri phia duoi
		{
			if (bx1 + vx >= x0 && bx0 + vx <= x0) //xet vi tri ben trai goc duoi
			{
				if (vy >= 0) // va cham ben trai
				{
					vx = -vx;
				}
			}
			else if (bx0 + vx <= x1 && bx1 + vx >= x1) // xet vi tri ben phai goc duoi cung
			{
				if (vy > 0) // va cham canh ben phai cua gach
				{
					vx = -vx;
				}
			}
			else // va chamm phia duoi
			{
				vy = -vy;
			}
		}
		else if (by0 + vy <= y0 && by1 + vy >= y0)// xet dinh tam giac
		{
			if (vy >= 0) // va cham phia tren
			{
				if (vx >= 0) // va cham ben trai
				{
					vx = -vx;
				}
				else // va cham ben phai
				{
					vx = -vx;
				}
			}
			else // xet va cham trai phai
			{
				if (vx >= 0) // va cham ben trai
				{
					vx = -vx;
				}
				else // va cham ben phai
				{
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

