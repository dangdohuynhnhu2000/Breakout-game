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
	int firstExistBullet;//bullet dau tien trong chuoi bullet dang hien thi tren man hinh
public:
	vector <Bullet> bulletList;
	GunMode();
	void setAmountOfBullets(int n);

	void checkBulletClock(Paddle & paddle);

	void updateNextBullet();//cap nhat nextBullet

	void moveBullets();

	void shootMode(Paddle& paddle);

	void drawBullets(RenderWindow& window);

	void turnOnGunMode(RenderWindow& window, Paddle& paddle);

	void turnOffGunMode(Paddle & paddle);

	void resetBulletList();

	int getNextBullet();

	void setNextBullet(int next);

};
