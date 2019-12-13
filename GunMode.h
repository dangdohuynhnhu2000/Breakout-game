#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Paddle.h"
#include "Bullet.h"

class GunMode
{
private:
	Clock bulletClock;
	int totalBullets;	
	int nextBullet;//cho biet bullet nao tiep theo duoc ban
	Texture texture;
public:
	vector <Bullet> bulletList;
	GunMode();
	void setAmountOfBullets(int n);
	void resetBulletList();//reset lai de chuan bi cho lan hung duoc vat pham ban thu 2
	void checkBulletClock(Paddle& paddle);
	void updateNextBullet();//cap nhat nextBullet
	void moveBullets();
	void shootMode(Paddle& paddle);
	void drawBullets(RenderWindow& window);
	void turnOnGunMode(RenderWindow& window, Paddle& paddle);
	void turnOffGunMode(Paddle& paddle);
};

