#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Paddle.h"
#include "Bullet.h"
// che do ban sung
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
	void setAmountOfBullets(int n); // thiet lap tong so dan ban ra

	void checkBulletClock(Paddle & paddle); 

	void updateNextBullet();//cap nhat nextBullet

	void moveBullets(); // di chuyeen vien dan (huong len)

	void shootMode(Paddle& paddle); // che do ban

	void drawBullets(RenderWindow& window); // ve toan bo dan

	void turnOnGunMode(RenderWindow& window, Paddle& paddle); // bat che do ban sung len

	void turnOffGunMode(Paddle & paddle);// tat che do ban sung

	void resetBulletList(); // thiet lap lai sau khi ban dan xong

	int getNextBullet(); // tra ve vien dan chuan bi duoc ban (dung trong save Game)

	void setNextBullet(int next); // cai dat vien dan chuan bi duoc ban (dung trong save Game)

};
