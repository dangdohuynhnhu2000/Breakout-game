
#include "Header.h"

void gamePlay(sf::RenderWindow & window, sf::Font font, float padSpeed, float ballSpeed, float defaultSpeed, bool& playing, bool AIMode) {


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
	Result.setPosition(220, 50);

	//diem ban dau ca hai = 0
	int scoreLeft = 0;
	int scoreRight = 0;

	//tao paddle
	Paddle paddle1({ 120, 10 });
	paddle1.isOnGunMode = false;
	paddle1.setColor(255, 85, 45, 255);
	//tao 4 buc tuong
	Wall wall;

	
	//tao bong
	Ball ball({ 10 });

	//cai dat vi tri ban dau
	defaultPos(paddle1, ball);

	//khoi tao event
	sf::Event event;
	//tao clock de do thoi gian
	sf::Clock clock;

	Grid grid;
	float vt = 0.5;
	float windowHeight = 900; 
	grid.Level3();

	//GunMode gun;
	//gun.setAmountOfBullets(5);
	int limitGunMode = 0;//gioi han ma tai do ta tat che do GunMode

	bool isOnGunMode = false;//cho biet co dang o che do gunMode hay khong
	
	float vx = ballSpeed;
	float vy = ballSpeed;

	int n = 0;
	GunMode gun;
	gun.setAmountOfBullets(5);

	int frameCount = 0;//dem xem bao nhieu frame cua game da duoc thuc hien
	while (playing == true)
	{
		frameCount++;
		bool check = true;

		//huong di chuyen cua bong, mac dinh ban dau di chuyen ve ben trai, huong thay doi lien tuc

		float timeElapse = 3;
		static bool goingUp = false;
		static bool goingDown = false; 
		static bool goingLeft = true;
		static bool goingRight = false;

		//huong di chuyen cua may
		//sau moi vong lap tu tra ve mac dinh
		bool AIgoingUp = false;
		bool AIgoingDown = false;
		bool AIgoingLeft = false;
		bool AIgoingRight = false;

		//Player1 Movement:
		//su dung cac nut w a s d de di chuyen
		//gioi han khong gian di chuyen
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && paddle1.getPosition().top > 690) {
			paddle1.move({ 0, -padSpeed * timeElapse });
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && (paddle1.getPosition().top + paddle1.getPosition().height) < 720) {
			paddle1.move({ 0, padSpeed * timeElapse });
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && paddle1.getPosition().left > 50) {
			paddle1.move({ -padSpeed / 3 * 2 * timeElapse , 0 });
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && (paddle1.getPosition().left + paddle1.getPosition().width) < 850) {
			paddle1.move({ padSpeed / 3 * 2 * timeElapse, 0 });
		}

		//Vong lap doi lenh
		//Neu khong co lenh nao doi thuc hien thi tra ve false
		//neu co lenh thi thuc hien
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed: //click nut tat bang chuot
				window.close();
				exit(0);
			case sf::Event::KeyReleased:
				switch (event.key.code) //nhan lenh tu ban phim
				{
				case sf::Keyboard::Escape:
					window.close();
					exit(0);
				case sf::Keyboard::Tab:
					playing = goingUp = goingDown = goingRight = false;// reset bong va tro ve menu
					goingLeft = true;
					ballSpeed = defaultSpeed;// reset speed
					defaultPos(paddle1, ball);//reset position
					break;
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
							goingLeft = true;
							goingDown = goingUp = goingRight = false;
							playing = false;//tro ve main menu
							break;
						}
					}
				}
			}
		}

		if (paddle1.reflex(ball, vx, vy))
		{
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
		if (wall.Top.isHitBall(ball) == true) {
			vy = -vy;
		}

		//score board
		sf::Text Score;
		Score.setString(std::to_string(scoreLeft) + ":" + std::to_string(scoreRight));//chuyen int thanh string va set cac gia tri cho text
		Score.setFont(font);
		Score.setCharacterSize(78);
		Score.setFillColor(sf::Color::Color(100, 255, 35));
		Score.setPosition(390, 110);


		if (wall.Bottom.isHitBall(ball) == true)
		{
			scoreRight++;
			Score.setString(std::to_string(scoreLeft) + ":" + std::to_string(scoreRight));
			//ve cac chi tiet
			drawToWindow(window, paddle1, ball, wall, Guide);
			grid.draw(paddle1, window);
			window.draw(Score);
			window.draw(Start);
			result(scoreLeft, scoreRight, Result);
			window.draw(Result);
			window.display(); //hien thi ra man hinh

			//reset game
			ballSpeed = defaultSpeed;
			defaultPos(paddle1, ball);
			goingDown = goingUp = false;
			//tam dung doi nguoi choi san sang
			while (window.waitEvent(event)) {
				switch (event.type) {
				case sf::Event::Closed:
					window.close();
					exit(0);
				}
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
		}
		grid.Reflex(ball, vx, vy);
		ball.move({ vx, vy });
	
		//Player score
		if (wall.Left.isHitBall(ball) == true) {
			vx = -vx;
		}

		//Player score
		if (wall.Right.isHitBall(ball) == true) {
			vx = -vx;
		}
		
		//ve chi tiet
		drawToWindow(window, paddle1, ball, wall, Guide);
		window.draw(Score);
		grid.draw(paddle1, window);
		if (frameCount % 5000 == 0)
		{
			grid.moveDown(5, 900);
		}
		if (paddle1.isOnGunMode == true)
		{
			gun.turnOnGunMode(window, paddle1);
		}
		gun.turnOffGunMode(paddle1);
		grid.hitBullet(gun);
		window.display();//hien thi ra man hinh		
	}
}
