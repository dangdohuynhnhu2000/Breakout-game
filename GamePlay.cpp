#include "Header.h"
#include "Name.h"
void gamePlay(sf::RenderWindow& window, sf::Font font, float padSpeed, float ballSpeed, float defaultSpeed, bool& playing, bool history) {
	
	if (playing == true )
	{
		int level = 1;
		string player_name = "";
		Grid grid;
		
		
		int life = 3;

		sf::Text Start;//cai dat thong bao dung man hinh
		Start.setFont(font);
		Start.setString("Press Space/Enter To Start");
		Start.setFillColor(sf::Color::Yellow);

		sf::Text Guide;//huong dan phim
		Guide.setFont(font);
		Guide.setFillColor(sf::Color::Yellow);
		Guide.setString("Pause: P\t\t\t\t\t Menu: Tab\nResume: Space/Enter\tExit: ESC");
		Guide.setPosition(100, 795);

		sf::Text Result;
		Result.setFont(font);
		Result.setCharacterSize(60);
		Result.setPosition(220, 100);

		//tao paddle
		Paddle paddle1({ 120, 10 });
		paddle1.setColor(255, 85, 45, 255);
		//tao 4 buc tuong
		Wall wall;

		//tao bong
		Ball ball({ 8 });

		//ai dat vi tri ban dau
		defaultPos(paddle1, ball);

		//khoi tao event
		sf::Event event;
		//tao clock de do thoi gian
		sf::Clock clock;

		float vx = ballSpeed;
		float vy = -ballSpeed;

		GunMode gun;
		gun.setAmountOfBullets(5);

		bool check = true; // gioi han so lan va cham ben hong
		int test = 0;

		Texture heart;
		heart.loadFromFile("heart.png");

		Sprite sprite_heart1(heart);
		sprite_heart1.setPosition(55, 690);
		sprite_heart1.setScale(0.25, 0.25);

		Sprite sprite_heart2(heart);
		sprite_heart2.setPosition(95, 690);
		sprite_heart2.setScale(0.25, 0.25);

		Sprite sprite_heart3(heart);
		sprite_heart3.setPosition(135, 690);
		sprite_heart3.setScale(0.25, 0.25);

		Sprite sprite_heart4(heart);
		sprite_heart4.setPosition(175, 690);
		sprite_heart4.setScale(0.25, 0.25);

		Sprite sprite_heart5(heart);
		sprite_heart5.setPosition(205, 690);
		sprite_heart5.setScale(0.25, 0.25);

		Sprite sprite_heart6(heart);
		sprite_heart6.setPosition(245, 690);
		sprite_heart6.setScale(0.25, 0.25);

		Sprite sprite_heart7(heart);
		sprite_heart7.setPosition(285, 690);
		sprite_heart7.setScale(0.25, 0.25);


		vector <Sprite> life_heart;
		if (life >= 1)
		{
			life_heart.push_back(sprite_heart1);
		}
		if (life >= 2)
		{
			life_heart.push_back(sprite_heart2);
		}
		if (life >= 3)
		{
			life_heart.push_back(sprite_heart3);
		}
		if (life >= 4)
		{
			life_heart.push_back(sprite_heart4);
		}
		if (life >= 5)
		{
			life_heart.push_back(sprite_heart5);
		}
		if (life >= 6)
		{
			life_heart.push_back(sprite_heart6);
		}
		if (life >= 7)
		{
			life_heart.push_back(sprite_heart7);
		}

		sf::SoundBuffer buffer_paddle;
		buffer_paddle.loadFromFile("paddle.wav");
		sf::Sound sound_paddle;
		sound_paddle.setBuffer(buffer_paddle);

		sf::SoundBuffer buffer_brick;
		buffer_brick.loadFromFile("brick.wav");
		sf::Sound sound_brick;
		sound_brick.setBuffer(buffer_brick);

		if (!history)
		{
			Name name;
			player_name = name.fillName(window);
			grid.Level1();
		}
		else
		{
			SaveGame save;
			save.readSaveGame(vx, vy, ball, paddle1, grid, life, gun);
		}

		int limitGunMode = 0;//gioi han ma tai do ta tat che do GunMode

		paddle1.isOnGunMode = false;//cho biet co dang o che do gunMode hay khong

		bool automove = true;
		sf::Clock clock_Elapsed;
		while (playing == true) {
			float timeElapse = clock_Elapsed.getElapsedTime().asMilliseconds();
			clock_Elapsed.restart().asMilliseconds();
			if (timeElapse > 3)
			{
				timeElapse = 3;
			}
			//huong di chuyen cua may
			//sau moi vong lap tu tra ve mac dinh
			//Player1 Movement:
			//su dung cac nut w a s d de di chuyen
			//gioi han khong gian di chuyen
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && paddle1.getPosition().top > 690) {
				paddle1.move({ 0, -padSpeed * timeElapse });
				automove = false;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && (paddle1.getPosition().top + paddle1.getPosition().height) < 720) {
				paddle1.move({ 0, padSpeed * timeElapse });
				automove = false;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && paddle1.getPosition().left > 50) {
				paddle1.move({ -padSpeed * timeElapse , 0 });
				automove = false;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && (paddle1.getPosition().left + paddle1.getPosition().width) < 855) {
				paddle1.move({ padSpeed * timeElapse, 0 });
				automove = false;
			}
			while (window.pollEvent(event)) {
				switch (event.type) {
				case sf::Event::Closed: //click nut tat bang chuot
					window.close();
					exit(0);
				case sf::Event::KeyReleased:
					switch (event.key.code) //nhan lenh tu ban phim
					{
					case sf::Keyboard::Escape:
					{
						window.close();
						exit(0);
					}
					case sf::Keyboard::Tab:
					{
						SaveGame save;
						save.saveGameOutFile(paddle1.getScore(), player_name, vx, vy, ball.getGlobalBounds().left, ball.getGlobalBounds().top, paddle1, grid.getShape(), grid.getlevel(),life, gun);
						playing = false;// reset bong va tro ve menu
						vx = vy = ballSpeed;
						defaultPos(paddle1, ball);//reset position
						break;
					}

					case sf::Keyboard::P://pause game, hien thong bao
						window.draw(Start);
						window.display();
						//dnng man hinh
						while (window.waitEvent(event)) {
							switch (event.type) {
							case sf::Event::Closed:
								window.close();
								exit(0);
							}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
								window.close();
								exit(0);
							}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
								clock.restart(); //bo thoi gian vong lap khi pause
								break;
							}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
								clock.restart(); //bo thoi gian vong lap khi pause
								break;
							}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) {
								playing = false;//tro ve main menu

								break;
							}
						}
					}

				}
			}

			if (paddle1.reflex(ball, vx, vy, check))
			{

				sound_paddle.play();

				if (vx >= 0)
				{
					vx += ballSpeed * 0.1;
				}
				else
				{
					vx -= ballSpeed * 0.1;
				}
				if (vy >= 0)
				{
					vy = vy + ballSpeed * 0.1;
				}
				else
				{
					vy -= ballSpeed * 0.1;
				}
			}

			//doi huong khi va cham tren va duoi
			if (wall.Top.isHitBall(ball, vx, vy) == true) {

				vy = -vy;
			}

			//score board
			sf::Text Score;
			Score.setString("Score: " + std::to_string(paddle1.getScore()));//chuyen int thanh string va set cac gia tri cho text
			Score.setFont(font);
			Score.setCharacterSize(50);
			Score.setFillColor(sf::Color::Color(100, 255, 35));
			Score.setPosition(600, 15);

			sf::Text player;
			player.setString(player_name);
			player.setFont(font);
			player.setCharacterSize(50);
			player.setFillColor(sf::Color::Color(100, 255, 35));
			player.setPosition(100, 15);

			if (wall.Bottom.isHitBall(ball, vx, vy) == true) {
				//ve cac chi tiet
				drawToWindow(window, paddle1, ball, wall, Guide);
				window.draw(Score);
				window.draw(Start);
				//result(scoreLeft, scoreRight, Result);
				window.draw(Result);
				window.display(); //hien thi ra man hinh

				//reset game
				ballSpeed = defaultSpeed;
				vx = ballSpeed;
				vy = -ballSpeed;
				defaultPos(paddle1, ball);
				check = true; // gioi han va cham ben hong 1 lan
				//tam dung doi nguoi choi san sang
				bool wait = true;
				while (window.waitEvent(event) && wait) {

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
						window.close();//Thoat Game
						exit(0);
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
						clock.restart();//choi tiep
						break;
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) {
						playing = false;//ve main menu
						break;
					}


				}
				life--;
				life_heart.resize(life);
				clock_Elapsed.restart().asMilliseconds();
			}
			if (automove) paddle1.autoMove(vx);

			if (grid.Reflex(ball, vx, vy, paddle1))
			{
				sound_brick.play();
			}
			ball.move({ vx *timeElapse, vy *timeElapse });

			//Player score
			if (wall.Left.isHitBall(ball, vx, vy) == true) {
				vx = -vx;
			}


			//Player score
			if (wall.Right.isHitBall(ball, vx, vy) == true) {
				vx = -vx;
			}

			if (grid.getRemainAmount(ball.getGlobalBounds().top) == 0)
			{
				level++;
				if (level == 2)
				{
					grid.Level2();
				}
				else if (level == 3)
				{
					grid.Level3();
				}
				else if (level == 4)
				{
					grid.Level4();
				}
				ballSpeed = defaultSpeed;
				vx = ballSpeed;
				vy = -ballSpeed;
				defaultPos(paddle1, ball);
				automove = true;
				life++;
				switch (life)
				{
				case 2:
					life_heart.push_back(sprite_heart2);
					break;
				case 3:
					life_heart.push_back(sprite_heart3);
					break;
				case 4:
					life_heart.push_back(sprite_heart4);
					break;
				case 5:
					life_heart.push_back(sprite_heart5);
					break;
				case 6:
					life_heart.push_back(sprite_heart6);
					break;
				case 7:
					life_heart.push_back(sprite_heart7);
					break;
				}

			}

			//ve chi tiet
			drawToWindow(window, paddle1, ball, wall, Guide);
			window.draw(Score);
			window.draw(player);
			grid.draw(paddle1, window);
			for (int i = 0;i < life_heart.size();i++)
			{
				window.draw(life_heart[i]);
			}

			if (paddle1.isOnGunMode == true)
			{
				gun.turnOnGunMode(window, paddle1);
			}
			gun.turnOffGunMode(paddle1);
			grid.hitBullet(gun, paddle1);

			window.display();
			if (life == 0)
			{
				Name achievement_write;
				achievement_write.writeToFile(player_name, paddle1.getScore());

				Name achievement_draw;
				achievement_draw.drawAchievementBoard(window, playing);
			}
		}
	}

	
}