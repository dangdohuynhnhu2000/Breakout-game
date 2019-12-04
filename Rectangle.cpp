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

bool Rectangle::reflex(Ball & ball, float &vx, float &vy, bool & goingUp, bool & goingDown, bool & goingLeft, bool & goingRight, bool & check)
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

	if (collision == true)
	{
		cout << "?????????" << endl;
	}

	if (collision)
	{
		if (bx1 + vx >= x0 && bx0 + vx <= x0) //xet 3 vi tri ben trai
		{
			if (by1 <= y0)
			{
				if (vy > 0) // va cham canh ben tren cua gach 
				{
					goingUp = true;
					goingDown = false;
					vy = -vy;
				}
				else // va cham canh trai cua gach
				{
					goingLeft = true;
					goingRight = false;
					vx = -vx;
				}
			}
			else if (by0 >= y1)
			{
				if (vy >= 0) // va cham ben trai
				{
					goingLeft = true;
					goingRight = false;
					vx = -vx;
				}
				else // va cham ben duoi
				{
					goingUp = false;
					goingDown = true;
					vy = -vy;
				}
			}
			else
			{
				goingRight = false;
				goingLeft = true;
				vx = -vx; // va cham ben trai 
				//cout << "vo day" << endl;
				check = false;
			}
		}
		else if (bx0 + vx <= x1 && bx1 + vx >= x1) // xet 3 vi tri ben phai
		{
			if (by0 >= y1)
			{
				if (vy > 0) // va cham canh ben phai cua gach
				{
					goingLeft = false;
					goingRight = true;
					vx = -vx;
				}
				else // va cham canh duoi cua gach
				{
					goingUp = false;
					goingDown = true;
					vy = -vy;
				}
			}
			else if (by1 <= y0)
			{
				if (vy < 0) // va cham ben phai
				{
					goingLeft = false;
					goingRight = true;
					vx = -vx;
				}
				else // va cham phia tren
				{
					goingUp = true;
					goingDown = false;
					vy = -vy;
				}
			}
			else
			{
				goingLeft = false;;
				goingRight = true;
				vx = -vx; // va cham ben phai 
			}
		}
		else
		{
			if (by0 + vy <= y0 && by1 + vy >= y0) // tren
			{
				goingUp = true;
				goingDown = false;
			}
			else // va cham duoi
			{
				goingDown = true;
				goingUp = false;
			}
			vy = -vy;// va cham tren hoac duoi;
		}
		return true;
	}
	return false;
}

/*void Rectangle::Collision(Ball &ball, float &vx, float &vy)
{
	float x0 = getPosition().left;
	float x1 = x0 + getPosition().width;
	float y0 = getPosition().top;
	float y1 = y0 + getPosition().height;

	float bx0 = ball.getPosition().left;
	float bx1 = bx0 + ball.getPosition().width;
	float by0 = ball.getPosition().top;
	float by1 = by0 + ball.getPosition().height;

	if (by0 + vy < y1 && by1 + vy > y0)
	{
		if (bx1 + vx > x0 && bx0 < x0)// sai vi chau biet tu dau toi
		{
			vx = abs(x0 - bx1);
			cout << ball.getPosition().left << " " << ball.getPosition().top << endl;
		}
		else if (bx0 + vx < x1 && bx1 + vx > x1)// sai luon vi chua biet tu dau toi
		{
			vx = -abs(x1 - bx0);
			cout << ball.getPosition().left << " " << ball.getPosition().top << endl;
		}


	}
	else if (by1 + vy > y0 && by0 + vy < y0)
	{
		if (bx1 + vx > x0 && bx0 + vx < x1)
		{
			vy = by1 - y0;
			cout << ball.getPosition().left << " " << ball.getPosition().top << endl;
		}
	}
	else if (by0 + vy < y1 && by1 + vy > y1)
	{
		if (bx1 + vx > x0 && bx0 + vx < x1)
		{
			vy = y1 - by0;
			cout << ball.getPosition().left << " " << ball.getPosition().top << endl;
		}
	}

}*/