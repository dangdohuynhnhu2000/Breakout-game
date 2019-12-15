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
	bool hasLimit = false; //gioi han so chu
	int limit = 0;
	void inputLogic(int charTyped);
	void deleteLastChar();
public:

	void setTextBox(int size, Color color, bool sel); //cai dat text box
	void setFont(Font& font); // cai dat font chu cho text box
	void setPosition(Vector2f pos); // cai dat vi tri cho text box
	void setLimit(bool existLimit); // cai dat so luong chu toi da duoc nhap
	void setLimit(bool existLimit, int lim);
	string getText(); // tra ve gia tri nguoi dung nhap vao
	void draw(RenderWindow& window); // ve text box
	void typedOn(Event input);
	int getLimit(); // lay so luong chu toi da
};