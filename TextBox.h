#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include <iostream>
using namespace std;
#include <sstream>
#define DELETEKEY 8
#define ENTERKEY 13
#define ESCAPEKEY 27

class TextBox
{
private:
	Text textBox;
	ostringstream text;
	bool isSelected = false;
	bool hasLimit = false;
	int limit = 0;
	void inputLogic(int charTyped);
	void deleteLastChar();
public:

	void setTextBox(int size, Color color, bool sel);
	void setFont(Font& font);
	void setPosition(Vector2f pos);
	void setLimit(bool existLimit);
	void setLimit(bool existLimit, int lim);
	string getText();
	void draw(RenderWindow& window);
	void typedOn(Event input);
	int getLimit();
};