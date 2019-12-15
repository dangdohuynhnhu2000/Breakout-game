#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include <iostream>
using namespace std;

class Button
{
private:
	RectangleShape button;
	Text text;
	int buttonWidth;
	int buttonHeight;
public:
	void setButton(string buttonText, Vector2f buttonSize, int charSize, Color buttonColor, Color textColor);
	void setFont(Font& font);
	void setBackColor(Color color);
	void setTextColor(Color color);
	void setPosition(Vector2f point);
	void draw(RenderWindow& window);
	// Check if the mouse is within the bounds of the button:
	bool isMouseOver(RenderWindow& window);
};
