#include "Wall.h"

//khoi tao vi tri kich thuoc va tuong
Wall::Wall() {
	Left.setPos({ 30,120 });
	Left.setSize({ 10,650 });
	Right.setPos({ 860,120 });
	Right.setSize({ 10,650 });
	Top.setPos({ 30, 120 });
	Top.setSize({ 840,10 });
	Bottom.setPos({ 30,770 });
	Bottom.setSize({ 840,10 });
}

Wall::~Wall() {

}
//ve tuong
void Wall::drawTo(sf::RenderWindow& window) {
	Left.drawTo(window);
	Right.drawTo(window);
	Top.drawTo(window);
	Bottom.drawTo(window);
}