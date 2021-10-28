#include "Button.h"

void Button::setButton(string buttonText, Vector2f buttonSize, int charSize, Color buttonColor, Color textColor)
{
	button.setSize(buttonSize); // cai dat kich thuoc cho nutt
	button.setFillColor(buttonColor); // cai dat mau nen cho nut
	 
	// cai dat vi tri
	buttonWidth = buttonSize.x;
	buttonHeight = buttonSize.y;

	text.setString(buttonText); // tao chu
	text.setCharacterSize(charSize); // cai dat kich thuoc chu
	text.setFillColor(textColor); // cai dat mau chu
}

void Button::setFont(Font& font)
{
	text.setFont(font); // cai dat font chu
}

void Button::setBackColor(Color color)
{
	button.setFillColor(color); // cai dat mau nen button
}

void Button::setTextColor(Color color)
{
	text.setFillColor(color); //cai dat mau chu
}

void Button::setPosition(Vector2f point) // cai dat vi tri cho button
{
	button.setPosition(point);
	// Center text on button:
	float xPos = (point.x + buttonWidth / 2) - (text.getLocalBounds().width / 2);
	float yPos = (point.y + buttonHeight / 2.2) - (text.getLocalBounds().height / 2);
	text.setPosition(xPos, yPos);
}

void Button::draw(RenderWindow& window)
{
	window.draw(button); // ve nut len man hinh
	window.draw(text); // ve chu len man hinh
}

bool Button::isMouseOver(RenderWindow& window) 
{
	// lay toa do cua con chuot tren man hinh
	int mouseX = Mouse::getPosition(window).x;
	int mouseY = Mouse::getPosition(window).y;

	// Lay toa do cua nut tren man hinh
	int buttonPosX = button.getPosition().x;
	int buttonPosY = button.getPosition().y;

	// lay  kich thuoc cua nut
	int buttonxPosWidth = button.getPosition().x + buttonWidth;
	int buttonyPosHeight = button.getPosition().y + buttonHeight;

	// kiem tra xem con chuot co luot vao btton hay khong
	if (mouseX < buttonxPosWidth && mouseX > buttonPosX && mouseY < buttonyPosHeight && mouseY > buttonPosY)
	{
		return true;
	}
	return false;
}