#pragma once
//#include <string>
#include "Ball.h"
#include "Item.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Bullet.h"
//#include <iostream>
using namespace sf;
using namespace std;
class Brick
{
protected:
	Vector2f position;
	int status;
	//0: dang ton tai
	//-1: da bien mat
	Texture texture;
	int number = 0;//so mac dinh cho moi brick
	Text text; //de in cac chu hoac so trong cuc gach
	Font font;
	Item item;//vat pham thuong, phat trong game

public:
	virtual FloatRect getPosition() = 0; // lay vi tri cua vien gach tra ve vi ttri hinh chu nhat

	virtual Vector2f getPositionxy() = 0; // lay toa do

	virtual int getStatus() = 0; // lay status

	virtual void setPosition(float newPosx, float newPosy) = 0; // dat lai toa do

	virtual void setBrick(float startX, float startY, float a, float b, int stt) = 0; // thiet lap vien gach
	
	virtual void setTexture(string textureName) = 0;// cai dat hinh anh cho vien gach

	virtual void setNumber(int num) = 0; // cai dat co so (level3)

	virtual void setStatus(int stt) = 0; // cai dat trang thai 

	virtual void setItemForBrick(int type) = 0; // cai dat loai vat pham

	virtual void draw(Paddle & paddle, RenderWindow& window) = 0; // ve ra dong thoi lam xuat hien vat pham 

	virtual void moveLeftAndRight(float vx) = 0;

	virtual void moveDown(float vy) = 0;

	virtual bool reflex(Ball& ball, float& vx, float& vy, Paddle & paddle) = 0; //phan xa

	virtual int isItemHitPaddle(Paddle paddle) = 0; // xet xem vat pham co cham paddle hay khong

	virtual bool isHitBullet(Bullet bullet) = 0; // xet xem vien dan co cham gach hay khong

	virtual int getNumber() = 0; // lay co so (lv3)

	virtual void changeNumber(int num)=0; // thay doi co so

	virtual Item getItem() = 0; // tra ve vat pham cua gach

	virtual void setStatusForItem(int status); // cat dat thuoc tinh cho vat pham (dung trong save game)

	virtual void setPositionForItem(Vector2f pos); // cai dat vi tri cho vat pham (dung trong save game)

};

