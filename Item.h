#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Paddle.h"
using namespace sf;
using namespace std;

class Item
{
private:
	Vector2f position;
	Sprite sprite;
	Texture texture;
	int type;
	int status;
	//-1: an ben trong gach
	//0: ton tai
	//-2: bien mat
public:
	Item();
	void setPosition(float x, float y);
	void setTexture(string textureName);
	void setType(int t);
	void setItem(float x, float y, string textureName, int t, int stt);
	void setStatus(int stt);
	int getStatus();
	FloatRect getPosition();
	Vector2f getPositionxy();
	int getType();
	void moveDown(float vy, float limit);// di chuyen xuong toi khi cham 1 limit nao do thi dung
	void draw(RenderWindow& window);
};

