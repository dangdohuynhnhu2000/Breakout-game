
#include "Rectangle.h"


void Rectangle::setBrick(float startX, float startY, float a, float b, int stt)
{
	// cai dat vat the cho gach
	position.x = startX;
	position.y = startY;
	width = a;
	height = b;
	shape.setSize(Vector2f(width, height));
	shape.setPosition(position);
	status = stt;
}

void Rectangle::setTexture(string textureName)
{
	// cai dat hinh anh cho gach
	texture.loadFromFile(textureName);
	shape.setTexture(&texture);
}

FloatRect Rectangle::getPosition()
{
	return shape.getGlobalBounds();
}

Vector2f Rectangle::getPositionxy()
{
	return Vector2f(position.x, position.y);
}

int Rectangle::getStatus()
{
	return status; // tra ve trang thai dang ton tai
}

void Rectangle::setPosition(float newPosx, float newPosy)
{
	// cai dat vi tri
	position.x = newPosx;
	position.y = newPosy;
}

void Rectangle::setNumber(int num)
{
	// cai dat co so
	float x, y;
	number = num;
	font.loadFromFile("iCielPanton-Black.otf");
	text.setString(to_string(number));
	text.setCharacterSize(20);
	text.setFont(font);
	text.setFillColor(Color::Yellow);
	//chinh cho doan text o giua hinh chu nhat
	x = (width / 2 + getPosition().left) - (text.getGlobalBounds().width / 2);
	y = (height / 2.5 + getPosition().top) - (text.getGlobalBounds().height / 2);
	text.setPosition({ x,y });
}

void Rectangle::setStatus(int stt)
{
	status = stt;
}

void Rectangle::setItemForBrick(int type)
{
	string name = to_string(type) + ".png";
	item.setItem(position.x, position.y, name, type, -1);
}

RectangleShape Rectangle::getShape()
{
	return shape;
}

void Rectangle::draw(Paddle &paddle, RenderWindow& window)
{
	if (status != -1) 
	{
		window.draw(getShape()); // trang thai dang ton tai 
	}
	else // trang thai da bien mat
	{
		
			if (item.getStatus() != -2) // item chua bi bien mat
			{
				item.setStatus(0);//cho item xuat hien khi vat the bien mat
			}
			item.moveDown(0.2, 770);
			if (isItemHitPaddle(paddle) != -10)//neu item cham paddle
			{
				if (item.getStatus() != -2)
				{
					item.setStatus(-2);//cho item bien mat vinh vien
					paddle.setScore(paddle.getScore() + item.getType()); // tinh diem
				}
			}
			if (item.getPosition().top > 750)//neu item di den cuoi man hinh thi se vinh vien bien mat
			{
				item.setStatus(-2);
			}
			item.draw(window);
	}
	if (number != 0)
	{
		window.draw(text);
	}
	//hung duoc vat pham ban sung
	if (isItemHitPaddle(paddle) == 0)
	{
		paddle.isOnGunMode = true;
	}
}

void Rectangle::moveLeftAndRight(float vx)
{
	// di chuyen gach theo huong cu the
	position.x += vx;
	shape.setPosition(position);
}

void Rectangle::moveDown(float vy)
{
	// di chuyen xuong
	position.y += vy;
	shape.setPosition(position);

	float x, y;
	x = (width / 2 + getPosition().left) - (text.getGlobalBounds().width / 2);
	y = (height / 2.5 + getPosition().top) - (text.getGlobalBounds().height / 2);
	text.setPosition({ x,y });
}

bool Rectangle::reflex(Ball& ball, float& vx, float& vy, Paddle & paddle)
{
	bool collision = false;

	float x0 = getPosition().left;
	float x1 = x0 + getPosition().width;
	float y0 = getPosition().top;
	float y1 = y0 + getPosition().height;

	float bx0 = ball.getPosition().left;
	float bx1 = bx0 + ball.getPosition().width;
	float by0 = ball.getPosition().top;
	float by1 = by0 + ball.getPosition().height;

	if (by0 + vy <= y1 && by1 + vy >= y0)
	{
		if ((bx0 + vx <= x1 && bx1 + vx >= x0))
		{
			if (number != 0)
			{
				number--;
				changeNumber(number);
			}
			collision = true;
		}
	}

	if (collision)
	{
		if (bx1 + vx >= x0 && bx0 + vx <= x0) //xet 3 vi tri ben trai
		{
			if (by1 <= y0)
			{
				if (vy > 0) // va cham canh ben tren cua gach 
				{
					vy = -vy;
				}
				else // va cham canh trai cua gach
				{
					vx = -vx;
				}
			}
			else if (by0 >= y1)
			{
				if (vy >= 0) // va cham ben trai
				{
					vx = -vx;
				}
				else // va cham ben duoi
				{

					vy = -vy;
				}
			}
			else
			{
				vx = -vx; // va cham ben trai 
			}
		}
		else if (bx0 + vx <= x1 && bx1 + vx >= x1) // xet 3 vi tri ben phai
		{
			if (by0 >= y1)
			{
				if (vy > 0) // va cham canh ben phai cua gach
				{
					vx = -vx;
				}
				else // va cham canh duoi cua gach
				{
					vy = -vy;
				}
			}
			else if (by1 <= y0)
			{
				if (vy < 0) // va cham ben phai
				{
					vx = -vx;
				}
				else // va cham phia tren
				{
					vy = -vy;
				}
			}
			else
			{
				vx = -vx; // va cham ben phai 
			}
		}
		else
		{
			vy = -vy;// va cham tren hoac duoi;
		}
		return true;
	}
	return false;
}

int Rectangle::isItemHitPaddle(Paddle paddle)
{
	if (item.getPosition().intersects(paddle.getPosition()))
	{
		return item.getType();//dua ra so diem khi hung duoc item
	}
	return -10;
}

bool Rectangle::isHitBullet(Bullet bullet)
{
	if (bullet.getPosition().intersects(getPosition()))
	{
		return true;
	}
	return false;
}

int Rectangle::getNumber()
{
	return number;
}

void Rectangle::changeNumber(int num)
{
	number = num;
	text.setString(to_string(num));
}

Item Rectangle::getItem()
{
	return item;
}

void Rectangle::setStatusForItem(int status)
{
	item.setStatus(status);
}

void Rectangle::setPositionForItem(Vector2f pos)
{
	item.setPosition(pos.x, pos.y);
}

