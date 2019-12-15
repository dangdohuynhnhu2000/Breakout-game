#include "TextBox.h"
void TextBox::setTextBox(int size, Color color, bool sel)
{
	textBox.setCharacterSize(size);// cai dat kich thuoc chu
	textBox.setFillColor(color); // mau chu
	isSelected = sel;
	if (sel)
	{
		textBox.setString("_");
	}
	else
	{
		textBox.setString("");
	}
}

void TextBox::inputLogic(int charTyped)
{
	if (charTyped != DELETEKEY && charTyped != ENTERKEY && charTyped != ESCAPEKEY)
	{
		text << static_cast<char>(charTyped);
	}
	else if (charTyped == DELETEKEY)
	{
		if (text.str().length() > 0)
		{
			deleteLastChar();
		}
	}
	textBox.setString(text.str() + "_");
}

void TextBox::deleteLastChar()
{
	string t = text.str();
	string newT = "";
	for (int i = 0; i < t.length() - 1; i++)
	{
		newT += t[i];
	}
	text.str("");
	text << newT;
	textBox.setString(text.str());
}

void TextBox::setFont(Font& font)
{
	textBox.setFont(font); // font chu cho text box
}

void TextBox::setPosition(Vector2f pos)
{
	textBox.setPosition(pos); // vi tri cho text box
}

void TextBox::setLimit(bool existLimit)
{
	hasLimit = existLimit; // so luong chu bi gioi han
}

void TextBox::setLimit(bool existLimit, int lim)
{
	hasLimit = existLimit;
	limit = lim;
}

string TextBox::getText()
{
	return text.str(); // tra ve gia tri nguoi dung nhap
}

void TextBox::draw(RenderWindow& window)
{
	window.draw(textBox); // ve text box
}

void TextBox::typedOn(Event input)
{
	if (isSelected)
	{
		int charTyped = input.text.unicode;
		if (charTyped < 128)
		{
			if (charTyped == ENTERKEY)
			{
				limit = 0;
			}
			else
			{
				if (hasLimit)
				{
					if (text.str().length() <= limit)
					{
						inputLogic(charTyped);
					}
					else if (text.str().length() > limit && charTyped == DELETEKEY)
					{
						deleteLastChar();
					}
				}
				else
				{
					inputLogic(charTyped);
				}
			}
		}
	}
}

int TextBox::getLimit()
{
	return limit; // tra ve so luong chu toi da
}