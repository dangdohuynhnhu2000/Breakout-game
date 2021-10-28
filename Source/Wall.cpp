#include "Wall.h"

//khoi tao vi tri kich thuoc va tuong
Wall::Wall() {
	Left.setPos({ 30,120 }); // vi tri tuong trai
	Left.setSize({ 10,650 });// kich thuoc tuong trai
	Right.setPos({ 860,120 }); // vi tri tuong phai
	Right.setSize({ 10,650 }); // kich thuoc tuong phai
	Top.setPos({ 30, 120 }); // vi tri tuong tren
	Top.setSize({ 840,10 }); // kich thuoc tuong trai
	Bottom.setPos({ 30,770 }); // vi tri tuong duoi
	Bottom.setSize({ 840,10 });// kich thuoc tuong duoi
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