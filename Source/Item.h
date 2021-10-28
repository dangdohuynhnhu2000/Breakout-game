#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Paddle.h"
using namespace sf;
using namespace std;
// class vat pham
class Item
{
private:
	Vector2f position; // vi tri cua vat pham
	Sprite sprite;
	Texture texture;
	int type; // loai vat pham (thuong hay phat, hay ban sung)
	int status;
	//-1: an ben trong gach
	//0: ton tai
	//-2: bien mat
public:
	Item(); // cai dat mac dinh cho item
	void setPosition(float x, float y);// cai dat vi tri cho item
	void setTexture(string textureName);// cai dat text ture cho item
	void setType(int t); // cai dat tung loai vat pham cu the
	void setItem(float x, float y, string textureName, int t, int stt);// cai dat tong the vat pham
	void setStatus(int stt); // cai dat trang thai cho item
	int getStatus(); // lay trang thai hien tai
	FloatRect getPosition(); // tra ve vi tri hien tai
	Vector2f getPositionxy(); // tra ve vi tri hien tai
	int getType(); // tra ve loai vat pham
	void moveDown(float vy, float limit);// di chuyen xuong toi khi cham 1 limit nao do thi dung
	void draw(RenderWindow& window); // ve item
};

