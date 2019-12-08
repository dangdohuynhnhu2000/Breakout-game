#include "Triangle.h"
#include "Rectangle.h"


void Triangle::setBrick(float startX, float startY, float a, float b, int stt)
{
	position.x = startX;
	position.y = startY;
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

CircleShape Triangle::getShape()
{
	return shape;
}

void Triangle::draw(RenderWindow& window)
{
	window.draw(getShape());
}

bool Triangle::reflex(Ball & ball, float &vx, float &vy)
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
				float v = sqrt(vx*vx + vy * vy);
				float pi = 3.141592654;
				float goc = atan((float)fabs(vy) / fabs(vx));
				vx = -cos(pi / 6 - goc)*v;
				vy = sin(pi / 6 - goc)*v;
			}
			else // va cham ben phai
			{
				float v = sqrt(vx*vx + vy * vy);
				float pi = 3.141592654;
				float goc = atan((float)fabs(vy) / fabs(vx));
				vx = -cos(pi / 6 - goc)*v;
				vy = sin(pi / 6 - goc)*v;
			}
		}
		return true;
	}
	return false;
}