#include "Wall.h"

//khoi tao vi tri kich thuoc va tuong
Wall::Wall() {
	Left.setPos({ 10,200 });
	Left.setSize({ 10,600 });
	Right.setPos({ 880,200 });
	Right.setSize({ 10,600 });
	Top.setPos({ 10, 200 });
	Top.setSize({ 880,10 });
	Bottom.setPos({ 10,800 });
	Bottom.setSize({ 880,10 });
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