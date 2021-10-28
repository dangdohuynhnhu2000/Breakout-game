#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include <iostream>
using namespace std;
// class nut (dung trong text box) - nut Play Now
class Button
{
private:
	RectangleShape button; // hinh dang nut
	Text text; // chu (Play Now)
	int buttonWidth; // chieu dai
	int buttonHeight; // chieu rong
public:
	void setButton(string buttonText, Vector2f buttonSize, int charSize, Color buttonColor, Color textColor); // thiet lap nut
	void setFont(Font& font); // thiet lap font chu
	void setBackColor(Color color); // thiet lap mau nen
	void setTextColor(Color color);// thiet lap mau chu
	void setPosition(Vector2f point); // thiet lap vi tri 
	void draw(RenderWindow& window); // ve nut
	// Check if the mouse is within the bounds of the button:
	bool isMouseOver(RenderWindow& window);
};
