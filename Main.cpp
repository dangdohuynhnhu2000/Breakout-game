#include "Header.h"

int main() {

	sf::RenderWindow window;
	sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445, (sf::VideoMode::getDesktopMode().height / 2) - 480);//lay vi tri giua man hinh
	window.create(sf::VideoMode(900, 900), "Pong Pong Pong Pong", sf::Style::Titlebar | sf::Style::Close);//create window: size, title
	window.setPosition(centerWindow);//dat vi tri mo len = centerWindow

	window.setFramerateLimit(480);//limit framerate

	bool AIMode = false;
	//Set Text
	sf::Font font;
	if (!font.loadFromFile("INVASION2000.ttf")) {
		// error...
	}

	//Start Screen
	//Option
	float defaultSpeed = 0.41;
	float padSpeed = defaultSpeed - 0.01;
	float ballSpeed = defaultSpeed;
	int speed = 5;

	//Thong bao level
	sf::Text Level;
	Level.setFont(font);
	Level.setFillColor(sf::Color::Color(185, 175, 120));
	Level.setPosition({ 250,480 });
	Level.setCharacterSize(50);
	Level.setString("Level: 5"); //mac dinh lv5

	//hong bao mode
	sf::Text Mode;
	Mode.setFont(font);
	Mode.setFillColor(sf::Color::Yellow);
	Mode.setPosition({ 250, 250 });
	Mode.setCharacterSize(50);
	Mode.setString("Human VS Human"); // mac dinh 2 player

	//Menu
	//Mainmenu
	std::string mainMenu[3];
	mainMenu[0] = "Play";
	mainMenu[1] = "Option";
	mainMenu[2] = "Exit";
	Menu mainScreen(900, 900, mainMenu, 3); //truyen 3 lua chon

	while (window.isOpen()) {
		bool playing = false;
		sf::Event event;
		//Menu screen
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
					//chon bang up/ down
				case sf::Keyboard::Up:
					mainScreen.moveUp();
					break;
				case sf::Keyboard::Down:
					mainScreen.moveDown();
					break;

				case sf::Keyboard::Return:
					switch (mainScreen.getPressedItem())//lay gia tri dang chon
					{
					case 0:
						playing = true;
						break;
					case 1:
						changeSetting(window, event, Level, defaultSpeed, ballSpeed, padSpeed, speed, AIMode, Mode);
						//cap nhat gia tri speed, mode
						break;
					case 2:
						window.close();
						exit(0);
						break;
					}
					break;
				}
				break;
			case sf::Event::Closed:
				window.close();
				exit(0);
				break;
			}
		}
		//truyen vao speed, mode de choi game
		gamePlay(window, font, padSpeed, ballSpeed, defaultSpeed, playing, AIMode);

		window.clear();
		mainScreen.drawTo(window);
		
		window.display();//hien thi ra man hinh menu
	}
}