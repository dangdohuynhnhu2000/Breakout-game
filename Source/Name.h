#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
#include "TextBox.h"
#include "Button.h"
#include <string>
#include <fstream>
#include <vector>
#include <conio.h>
struct achievement
{
	string player_name;
	int score;
};
// class thuc thi toan bo nhung chuong trinh lien quan den ten nguoi choi (bao game nhap ten va in bang thanh tich)
class Name
{
	RectangleShape box;
	Text text;
	TextBox textbox;

	Button button;

	Font font;

	vector <achievement> board; // bang thanh tich

public:
	Name();
	~Name();
	void setTheButtonPlay();  // tao nut play

	void setTheTextBox(); // tao text box

	string fillName(RenderWindow & window); // hien thi man hinh dien thong tin

	void writeToFile(string name, int score); // viet vao file

	void readFromFile(); // doc bang xep hang tu file

	void changeTheBoard(achievement tmp); // thay doi bang xep  hang

	void drawAchievementBoard(RenderWindow & window, bool & playing); // ve bang xep hang len man hinh

};

