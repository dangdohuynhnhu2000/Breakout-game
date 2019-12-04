#include "Menu.h"

Menu::Menu(float width, float height, std::string selectLine[], int amount) {
	amountOfItems = amount;
	menu = new sf::Text[amount];
	if (!font.loadFromFile("INVASION2000.ttf")) {
		//error...
	}
	for (int i = 0; i < amountOfItems; i++) {
		menu[i].setFont(font);
		menu[i].setCharacterSize(70);
		menu[i].setString(selectLine[i]);
		menu[i].setPosition(sf::Vector2f(250, height / (amountOfItems + 1) * (i + 1) - 50));
		if (i == 0) {
			menu[i].setFillColor(sf::Color::White); //dong dang chon trang tinh
		}
		else {
			menu[i].setFillColor(sf::Color::Color(128, 128, 128)); // dong khong duoc chon nhat mau hon
		}
	}
	selectedItemIndex = 0;
}


Menu::~Menu() {
}

void Menu::drawTo(sf::RenderWindow& window) {
	for (int i = 0; i < amountOfItems; i++) {
		window.draw(menu[i]);//ve menu
	}
}
//di chuyen len
void Menu::moveUp() {
	if (selectedItemIndex - 1 >= 0) {
		menu[selectedItemIndex].setFillColor(sf::Color::Color(128, 128, 128));
		selectedItemIndex--; //cap nhat vi tri sau khi di chuyen
		menu[selectedItemIndex].setFillColor(sf::Color::White); //doi mau dong chon
	}
}
// di chuyen xuong
void Menu::moveDown() {
	if (selectedItemIndex + 1 < amountOfItems) {
		menu[selectedItemIndex].setFillColor(sf::Color::Color(128, 128, 128));
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::White);
	}
}
//tra ve vi tri dang duoc chon
int Menu::getPressedItem() {
	return selectedItemIndex;
}
//tra ve 0 khi thoat menu
void Menu::resetPressedItem() {
	selectedItemIndex = 0;
}
//so luong dong
int Menu::setAmount(int amount) {
	menu = new sf::Text[amount];
	amountOfItems = amount;
	return amount;
}