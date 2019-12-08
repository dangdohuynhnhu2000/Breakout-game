#include "Header.h"

void gamePlay(sf::RenderWindow& window, sf::Font font, float padSpeed, float ballSpeed, float defaultSpeed, bool& playing, bool AIMode) {

	
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
	paddle1.setColor(255, 85, 45, 255);
	//tao 4 buc tuong
	Wall wall;

	//tao bong
	Ball ball({ 10 });

	//ai dat vi tri ban dau
	defaultPos(paddle1, ball);

	//khoi tao event
	sf::Event event;
	//tao clock de do thoi gian
	sf::Clock clock;

	Grid grid;
	grid.Level2();
	Texture tt;
	tt.loadFromFile("red rectangle.jpg");
	float vx = ballSpeed;
	float vy = ballSpeed;

	int n = 0;
	
	while (playing == true) {
		
		n++;
		if (n == 5)
		{
			cout << "fdfds";
		}
		bool check = true;
		/*float timeElapse = clock.restart().asSeconds() * 1000;//do thoi gian moi lan thuc hien vong lap de ket hop toc do di chuyen de giam khong phu thuoc vao toc do cpu
		if (timeElapse > 3) {
			timeElapse = 3; //gioi han toc do tranh truong hop bong di chuyen nhieu pixel trong truong hop may bi giat va lag
		}*/
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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && (paddle1.getPosition().top  + paddle1.getPosition().height)  <720) {
			paddle1.move({0, padSpeed * timeElapse });
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && paddle1.getPosition().left > 50) {
			paddle1.move({ -padSpeed / 3 * 2 * timeElapse , 0});
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && (paddle1.getPosition().left + paddle1.getPosition().width) < 850) {
			paddle1.move({ padSpeed / 3 * 2 * timeElapse, 0 });
		}

		//Player2 Movement
		//su dung cac nut de di chuyen
		//gioi han khong gian di chuyen
		/*if (AIMode == false) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && paddle2.getPos().y > 210) {
				paddle1.move({ 0, -padSpeed * timeElapse });
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && paddle2.getPos().x < 860) {
				paddle1.move({ padSpeed / 3 * 2 * timeElapse, 0 });
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && paddle2.getPos().y < 700) {
				paddle1.move({ 0, padSpeed * timeElapse });
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && paddle2.getPos().x > 790) {
				paddle1.move({ -padSpeed / 3 * 2 * timeElapse, 0 });
			}
		}*/
		//Computer Movement
		//gioi han khong gian di chuyen
		/*else {
			//di chuyen theo huong qua bong
			if (ball.getPos().y >= paddle2.getPos().y + 41 && paddle2.getPos().y < 700) {
				paddle2.move({ 0,padSpeed * timeElapse });
			}
			if (ball.getPos().y < paddle2.getPos().y + 41 && paddle2.getPos().y > 210) {
				paddle2.move({ 0, -padSpeed * timeElapse });
			}
			//dieu chinh huong danh len hay xuong
			if (goingUp == false && goingDown == false) {
				if (ball.getPos().y >= paddle1.getPos().y + 41) {
					AIgoingDown = true;
				}
				if (ball.getPos().y < paddle1.getPos().y + 41) {
					AIgoingUp = true;
				}
			}
			//danh ve phia truoc neu doi phuong xa huong doi dien
			if ((ball.getPos().y > paddle1.getPos().y + 230 || ball.getPos().y < paddle1.getPos().y - 230) && ball.getPos().x > 760) {
				if (paddle2.getPos().x > 790) {
					paddle2.move({ -padSpeed * timeElapse, 0 });
				}
				AIgoingLeft = true;
				AIgoingUp = AIgoingDown = false;
			}
			//lui ve khi den do
			else if (paddle2.getPos().x < 860) {
				paddle2.move({ padSpeed / 3 * 2 * timeElapse, 0 });
				AIgoingLeft = false;
			}
		}*/

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

		//speed
		//faster, do+ day bong di thi toc do tang len
		/*if (paddle1.isHitBall(ball) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && ballSpeed < defaultSpeed + 2) {
			ballSpeed += defaultSpeed / 5;
			/*goingUp = false;
			goingDown = false;
			vy = -vy;
		}*/
		/*if (paddle2.isHitBall(ball) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || AIgoingLeft == true) && ballSpeed < defaultSpeed + 2) {
			ballSpeed += defaultSpeed / 5;
			AIgoingUp = AIgoingDown = false;

			goingUp = false;
			goingDown = false;
		}*/

		//speed
		//slower, do lui thi giam toc do
		/*if (paddle1.isHitBall(ball) && sf::Keyboard::isKeyPressed(sf::Keyboard::A) && ballSpeed >= defaultSpeed) {
			ballSpeed -= defaultSpeed / 5;
			goingUp = false;
			goingDown = false;
		}*/
		/*if (paddle1.isHitBall(ball) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && ballSpeed >= defaultSpeed) {
			ballSpeed -= defaultSpeed / 5;
			goingUp = false;
			goingDown = false;
		}*/
		/*if (paddle1.isHitBall(ball) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && ballSpeed >= defaultSpeed) {
			ballSpeed -= defaultSpeed / 5;
			goingUp = false;
			goingDown = false;
		}*/

		//Huong danh bong
		//va cham di khi chuyen len qua bong se huogn len
		/*if (paddle1.isHitBall(ball) && sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			goingUp = true;
			goingDown = false;
		}*/
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


		//va cham khi di chuyen xuong qua bong se huong xuong
		/*if (paddle1.isHitBall(ball) && sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			goingDown = true;
			goingUp = false;
		}
		if (paddle2.isHitBall(ball) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || AIgoingDown == true)) {
			goingDown = true;
			goingUp = false;
		}*/ 

		//Hit pad, di chuyen cho den khi va cham vao menu
		/*if (goingLeft == true && paddle1.isHitBall(ball) == false) {
			if (goingUp == true) {
				//vy = -ballSpeed * timeElapse / 3;
				vy = -fabs(vy) * timeElapse / 3;
				//ball.move({ 0,  vy});
			}
			if (goingDown == true) {
				//vy = ballSpeed * timeElapse / 3;
				vy = fabs(vy) * timeElapse / 3;
				//ball.move({ 0, vy});
			}
			//vx = -ballSpeed * timeElapse;
			vx = -fabs(vx) * timeElapse/3;
			//ball.move({ vx, 0 });
		}
		else if (goingLeft == true && paddle1.isHitBall(ball) == true) {
			if (fabs(vx) < 3)
			{
				vx = 1.1*vx;
				vy = vy * 1.1;
			}
				
				ballSpeed += ballSpeed / 10; //tang toc 10% khi cham
			//doi huong
			goingRight = true;
			goingLeft = false;
			
		}*/

		/*if (goingRight == true && paddle2.isHitBall(ball) == false) {
			if (goingUp == true) {
				vy = -ballSpeed * timeElapse / 3;
				//vy = -fabs(vy) * timeElapse / 3;
				//ball.move({ 0, vy });
			}
			if (goingDown == true) {
				vy = ballSpeed * timeElapse / 3;
				//vy = fabs(vy) * timeElapse / 3;
				//ball.move({ 0, vy });
			}
			//vx = ballSpeed * timeElapse;
			vx = fabs(vx) * timeElapse/3;
			//ball.move({ vx, 0 });
		}
		else if (goingRight == true && paddle2.isHitBall(ball) == true) {
			if (fabs(vx) < 3)
			{
				vx = 1.1*vx;
				vy = 1.1*vy;
			}
				

				//ballSpeed += ballSpeed / 10; //tang toc 10% khi cham
			//doi huong
			goingRight = false;
			goingLeft = true;
		}*/

		//doi huong khi va cham tren va duoi
		if (wall.Top.isHitBall(ball) == true) {
			/*vy = ballSpeed / 3 * timeElapse;
			//vy = fabs(vy) * timeElapse/3;
			//ball.move({ 0,  vy});
			goingUp = false;
			goingDown = true;*/

			vy = -vy;
		}

		//score board
		sf::Text Score;
		Score.setString(std::to_string(scoreLeft) + ":" + std::to_string(scoreRight));//chuyen int thanh string va set cac gia tri cho text
		Score.setFont(font);
		Score.setCharacterSize(78);
		Score.setFillColor(sf::Color::Color(100, 255, 35));
		Score.setPosition(390, 110);


		if (wall.Bottom.isHitBall(ball) == true) {
			scoreRight++;
			Score.setString(std::to_string(scoreLeft) + ":" + std::to_string(scoreRight));
			//ve cac chi tiet
			drawToWindow(window, paddle1, ball, wall, Guide);
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

		

		//Rectangle HCN;
		//HCN.setBrick(500, 500, 200, 100, 4);
		//HCN.Collision(ball, vx, vy);
		//ball.move({ vx, vy });
		//HCN.reflex(ball, vx, vy, AIgoingUp, goingDown, AIgoingLeft, goingRight, check);
		grid.Reflex(ball,vx, vy);
		ball.move({ vx, vy });
		/*if (check == false) // khong hieu tai sao goingLeft no khong thay doi gia tri khi ra khoi ham
		{
			goingLeft = true;
		}*/
		

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
		//window.draw(HCN.getShape());
		grid.draw(window);

		window.display();//hien thi ra man hinh
	}
}