#include "Name.h"



Name::Name()
{
}


Name::~Name()
{
}


void Name::setTheTextBox()
{
	box.setSize(Vector2f(400, 50));
	box.setPosition(Vector2f(300, 380));

	text.setString("Name of player: ");
	text.setFont(font);
	text.setPosition(Vector2f(300, 280));
	text.setCharacterSize(45);
	text.setOutlineColor(sf::Color::White);

	font.loadFromFile("Villa-njwJ.ttf");

	textbox.setTextBox(35, Color::Blue, true);
	textbox.setFont(font);
	textbox.setLimit(true, 9);
	textbox.setPosition(Vector2f(310, 385));
}

string Name::fillName(RenderWindow & window)
{
	string player_name;

	Font font_breakOut;
	font_breakOut.loadFromFile("Cute Notes.ttf");
	Text text_breakOut;
	text_breakOut.setString("Break Out");
	text_breakOut.setCharacterSize(100);
	text_breakOut.setPosition({ 100,100 });
	text_breakOut.setFont(font_breakOut);
	text_breakOut.setFillColor(Color(250, 220, 25));

	setTheTextBox();
	setTheButtonPlay();
	int check = true; // neu da hoan thanh phan dien thong tin thi thoat ra ngoai
	while (window.isOpen() && check)
	{

		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				window.close();
			case Event::TextEntered:
				if (textbox.getLimit() != 0)
				{
					textbox.typedOn(event);
				}
			case Event::MouseMoved:
				if (button.isMouseOver(window))
				{
					button.setBackColor(Color::Blue);
				}
				else
				{
					button.setBackColor(Color::Green);
				}
				break;
			case Event::MouseButtonPressed:
				if (button.isMouseOver(window))
				{
					check = false;
					break;
				}
				break;
			case Event::KeyReleased:
			{
				if (event.key.code == Keyboard::Enter)
				{
					check = false;
					break;
				}
			}
			}
			
		}
		window.clear(sf::Color(20, 20, 20));

		window.draw(text);

		window.draw(box);

		window.draw(text_breakOut);

		textbox.draw(window);

		button.draw(window);
		
		window.display();
	}
	player_name = textbox.getText();
	return player_name;
}

void Name::setTheButtonPlay()
{
	button.setButton("PLAY NOW", { 200,80 }, 30, Color::Green, Color::Black);
	button.setFont(font);
	button.setPosition({ 400, 550 });
}

void Name::writeToFile(string name, int score)
{
	readFromFile();
	ofstream file; 
	file.open("AchievementBoard.txt");
	if (!board.empty())
	{
		achievement tmp;
		tmp.player_name = name;
		tmp.score = score;
		changeTheBoard(tmp);
		for (int i =0; i <board.size();i++)
		{
			file << board[i].player_name << endl;
			file << board[i].score << endl;
		}
	}
	else
	{
		file << name << endl;
		file << score << endl;
	}
	file.close();
}

void  Name :: readFromFile()
{
	ifstream file;
	file.open("AchievementBoard.txt");
	string tmp_line;
	achievement tmp_achievement;
	if (file.is_open())
	{
		while (!file.eof())
		{
			getline(file, tmp_line);
			if (tmp_line == "")
			{
				tmp_achievement.player_name = tmp_line;
				getline(file, tmp_line);
				if (file.eof())
				{
					break;
				}
				else
				{
					tmp_achievement.score = stoi(tmp_line);
					board.push_back(tmp_achievement);
				}
			}
			else
			{
				tmp_achievement.player_name = tmp_line;
				getline(file, tmp_line);
				tmp_achievement.score = stoi(tmp_line);
				board.push_back(tmp_achievement);
			}

		}
	}
	
	file.close();
}

void Name::changeTheBoard(achievement tmp) // vector da duoc sap xep giam dan
{
	if (board.size() >0)
	{
		vector <achievement> ::iterator it;
		for (it = board.begin(); it != board.end(); it++)
		{
			if (tmp.score > (*it).score)
			{
				break;
			}
		}
		board.insert(it, tmp);
		if (board.size() > 5)
		{
			board.resize(5);

		}
	}
	else
	{
		board.push_back(tmp);
	}
}

void Name::drawAchievementBoard(RenderWindow & window, bool & playing)
{
	readFromFile(); // doc du lieu tu file
	vector <Text> achievement;
	int posx = 220;
	int posy = 300;

	Text tmp;

	Font font;

	// ve chu high score
	Font highscore;
	highscore.loadFromFile("Karate.ttf");
	tmp.setString("High Score");
	tmp.setCharacterSize(140);
	tmp.setPosition(120, 80);
	tmp.setFont(highscore);
	tmp.setFillColor(Color(249, 220, 13));
	achievement.push_back(tmp);
	
	font.loadFromFile("sketchy.ttf");

	// thiet lap thanh tich tung nguoi
	for (int i = 0; i < board.size(); i++)
	{
		tmp.setString(board[i].player_name);
		tmp.setCharacterSize(50);
		tmp.setPosition(posx, posy);
		tmp.setFont(font);
		tmp.setFillColor(Color::White);
		achievement.push_back(tmp);
		tmp.setString(to_string(board[i].score));
		tmp.setCharacterSize(50);
		tmp.setPosition(posx+400, posy);
		tmp.setFont(font);
		achievement.push_back(tmp);
		posy = posy + 90;
	}

	while (window.isOpen() & playing)
	{

		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				window.close();
				exit(0);
			case Event ::KeyReleased:
				if (event.key.code== sf::Keyboard::Escape)
				{
					window.close();
					exit(0);
				}
				if (event.key.code == sf::Keyboard::Tab)
				{
					playing = false;
				}
			}
		}
		window.clear(sf::Color(20, 20, 20));

		// ve thanh tich tung nguoi
		for (int i = 0; i < achievement.size();i++)
		{
			window.draw(achievement[i]);
		}
		window.display();
	}
}