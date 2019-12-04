#pragma once
#include "SFML/Graphics.hpp"
#include <string>

#define MAX_NUMBER_OF_ITEMS 3
#define const sf::Time Game::TimePerFrame  sf::seconds(1.f / 60.f)

class Menu
{
private:
	int selectedItemIndex;//phan tu dang duoc chon

	int amountOfItems;//so luong phan tu trong menu

	sf::Font font;    //font trong Menu

	sf::Text *menu;   //Menu co the gom nhieu dong khac nhau
public:
	Menu(float width, float height, std::string lineOption[], int amount); //khoi tao menu, vi tri dong dua tren kich thuoc ban dau, truyen vao so luong dong va noi dung trong menu

	~Menu();

	void drawTo(sf::RenderWindow& window);//ve ra man hinh

	void moveUp();    //di chuyen xuong

	void moveDown();  //di chuyen len

	int getPressedItem();     //layphan tu dang duoc chon

	void resetPressedItem();  //tra ve 0 khi roi menu

	int setAmount(int amount);  //truyen so dong trong menu
};
