#include "Rectangle.h"


void Rectangle::setBrick(float startX, float startY, float a, float b, int stt)
{
	position.x = startX;
	position.y = startY;
	recshape.setSize(Vector2f(a,b));
	recshape.setPosition(position);
	status = stt;
}

void Rectangle::setTexture(string textureName)
{
	texture.loadFromFile(textureName);
	recshape.setTexture(&texture);
}

FloatRect Rectangle::getPosition()
{
	return recshape.getGlobalBounds();
}

RectangleShape Rectangle ::getShape()
{
	return recshape;
}

void Rectangle::draw(RenderWindow& window)
{
	window.draw(getShape());
}

bool Rectangle::reflex(Ball & ball, float &vx, float &vy)
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

FloatRect Paddle::getPosition()
{
	return paddle.getGlobalBounds();
}
