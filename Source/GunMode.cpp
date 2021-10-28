#include "GunMode.h"

GunMode::GunMode()
{
	totalBullets = 0;
	nextBullet = 0;
	texture.loadFromFile("bullet.png");
}

void GunMode::setAmountOfBullets(int n)
{ 
	// cai dat so luong dan toi da
	totalBullets = n;
	Bullet bullet(texture);
	for (int i = 0; i < totalBullets; i++)
	{
		bulletList.push_back(bullet);
	}
}

void GunMode::resetBulletList()
{
	// reset lai (sau khi ban xong)
	nextBullet = 0;
	for (int i = 0; i < totalBullets; i++)
	{
		bulletList[i].exist = -1;
	}
}

void GunMode::updateNextBullet()
{ 
	// cap nhat vien dan ban ke tiep
	if (nextBullet < totalBullets - 1)
	{
		nextBullet += 1;
	}
	if (nextBullet == totalBullets)//truong hop da ban het dan
	{
		nextBullet = 0;
	}
}

void GunMode::checkBulletClock(Paddle& paddle)
{
	Time time;
	time = seconds(0.3);

	if (bulletClock.getElapsedTime() > time)//neu vien dan thu nhat da duoc ban di sau 1 khoang thoi gian quy dinh
	{
		updateNextBullet();//cap nhat lai nextBullet
		paddle.turnGunMode(true);//paddle co the ban vien dan tiep theo
		bulletClock.restart();//khoi dong lai dong ho
	}
}

void GunMode::moveBullets()
{
	for (int i = 0; i < totalBullets; i++)
	{
		//neu bullet ton tai thi di chuyen no
		if (bulletList[i].exist == 0)
		{
			bulletList[i].moveUp(0, -1);
		}
	}
}

void GunMode::shootMode(Paddle& paddle)
{
	//ban vien dan hien tai
	if (bulletList[nextBullet].exist == -1)
	{
		bulletList[nextBullet].Shoot(paddle, bulletClock);
	}
}

void GunMode::drawBullets(RenderWindow& window)
{
	for (int i = 0; i < totalBullets; i++)
	{
		//neu bullet ton tai thi ve no ra man hinh
		if (bulletList[i].exist == 0)
		{
			bulletList[i].draw(window);
		}
	}
}

void GunMode::turnOnGunMode(RenderWindow& window, Paddle& paddle)
{
	// bat che de ban sung
	drawBullets(window); // ve ra man hinh
	shootMode(paddle); // ban sung
	moveBullets();// di chuyen dam
	if (paddle.canShoot == false)
	{
		checkBulletClock(paddle);
	}
}

void GunMode::turnOffGunMode(Paddle& paddle)
{
	bool check = true;
	if (bulletList[totalBullets - 2].exist == -2)
	{
		check = false;
	}

	if (!check) //neu tat ca dan da ra khoi man hinh thi tat che do ban sung
	{
		resetBulletList();
		paddle.isOnGunMode = false;
	}
}

int GunMode::getNextBullet()
{
	return nextBullet;
}

void GunMode::setNextBullet(int next)
{
	nextBullet = next;
}