#include "Header.h"

//vi tri mac dinh
void defaultPos(Paddle &paddle1, Ball& ball) {
	paddle1.setPos({ 440, 700});
	ball.setPos({ 440, 500 });
}
//ve cac chi tiet
void drawToWindow(sf::RenderWindow& window, Paddle paddle1, Ball ball, Wall wall, sf::Text Exit) {
	window.clear(sf::Color(20, 20, 20));
	window.draw(Exit);
	paddle1.drawTo(window);
	wall.drawTo(window);
	ball.drawTo(window);
}
//thay doi speed
void changeSpeed(sf::RenderWindow& window, sf::Event& event, sf::Text& Level, int& speed, Menu optionScreen) {
	switch (event.type) {
	case sf::Event::Closed:
		window.close();
	case sf::Event::KeyReleased:
		switch (event.key.code)
		{
			// up, down de thoat khoi che do chon
		case sf::Keyboard::Up:
			break;
		case sf::Keyboard::Down:
			break;
			//left, right de thay doi toc do
		case sf::Keyboard::Right:
			speed++;//tang spedd len neu lon hon 10 thi tro ve 1
			if (speed == 11) {
				speed = 1;
			}
			break;
		case sf::Keyboard::Left:
			speed--;//giam speed lai, neu be hon 1 thi tro ve 10
			if (speed == 0) {
				speed = 10;
			}
			break;
		}
		break;
	}
	Level.setString("Level: " + std::to_string(speed));//cap nhat thong bao level
}
//doi mode
void changeMode(sf::RenderWindow& window, sf::Event& event, Menu optionScreen, bool& history, sf::Text& Mode) {
	switch (event.type) {
	case sf::Event::Closed:
		window.close();
		exit(0);
	case sf::Event::KeyReleased:
		// up down de thoat khoi che do chon
		switch (event.key.code)
		{
		case sf::Keyboard::Up:
			break;
		case sf::Keyboard::Down:
			break;
			//left right de thay doi che do chon
		case sf::Keyboard::Right:
			history = !history;
			break;
		case sf::Keyboard::Left:
			history = !history;
			break;
		}
		break;
	}
	//cap nhat thong bao mode
	if (history == true) {
		Mode.setString("History");
	}
	else {
		Mode.setString("New game");
	}
}
// menu thay doi speed, level cho game
void changeSetting(sf::RenderWindow &window, sf::Event &event, sf::Text &Level, float &defaultSpeed, float &ballSpeed, float &padSpeed, int &speed, bool & history, sf::Text &Mode) {
	//optionmenu
	std::string optionMenu[4];
	optionMenu[0] = "Select Mode";
	optionMenu[1] = "Speed Level";
	optionMenu[2] = "Return";
	Menu optionScreen(900, 900, optionMenu, 3);//tao 3 dong gia tri
	bool exitOption = false;
	while (exitOption == false) {
		//event loop
		while (window.pollEvent(event)) {
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code) {
					//di chuyen len xuong = up, doown
				case sf::Keyboard::Up:
					optionScreen.moveUp();
					break;
				case sf::Keyboard::Down:
					optionScreen.moveDown();
					break;
				case sf::Keyboard::BackSpace:
					exitOption = true;//Thoat khoi option menu
					break;
				case sf::Keyboard::Enter:
					if (optionScreen.getPressedItem() == 2) {
						Level.setFillColor(sf::Color::Color(185, 175, 120));
						Mode.setFillColor(sf::Color::Color(185, 175, 120));
						exitOption = true;
						optionScreen.resetPressedItem();
					}
					break;
				}
				break;
			case sf::Event::Closed:
				window.close();
				exit(0);
				break;
			}
			//gia tri 1 tuong ung speed level
			if (optionScreen.getPressedItem() == 1)
			{
				Level.setFillColor(sf::Color::Yellow);
				Mode.setFillColor(sf::Color::Color(185, 175, 120));
				changeSpeed(window, event, Level, speed, optionScreen);

				defaultSpeed = (0.36 + 1.0 * speed / 20);
				padSpeed = defaultSpeed ;
				ballSpeed = defaultSpeed;
				break;
			}
			//gia tri 0 tuong ung mode
			if (optionScreen.getPressedItem() == 0)
			{
				Level.setFillColor(sf::Color::Color(185, 175, 120));
				Mode.setFillColor(sf::Color::Yellow);
				changeMode(window, event, optionScreen, history, Mode);
			}
			Level.setFillColor(sf::Color::Color(185, 175, 120));
			break;
		}
		window.clear();
		window.draw(Level);
		window.draw(Mode);
		optionScreen.drawTo(window);
		window.display();//hien cap nhat ra man hinh
	}
}

void result(int scoreLeft, int scoreRight, sf::Text &Result) {
	//thong bao loi the cua nguoi choi
	if (scoreLeft > scoreRight) {
		Result.setFillColor({ 255, 85, 45, 255 });
		Result.setString("Red is leading");
	}
	if (scoreLeft < scoreRight) {
		Result.setFillColor({ 0, 105, 255, 255 });
		Result.setString("Blue is leading");
	}
	if (scoreLeft == scoreRight) {
		Result.setFillColor(sf::Color::Yellow);
		Result.setString("       Tie");
	}
}