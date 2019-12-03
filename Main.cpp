// These "include" code from the C++ library and SFML too
#include "bat.h"
#include "ball.h"
#include "Brick.h"
#include "Grid.h"
#include "Hexagon.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

// Avoid having to put sf in front of all the SFML classes and functions
using namespace sf;


int main()
{
	int windowWidth = 1000;
	int windowHeight = 800;

	RenderWindow window(VideoMode(windowWidth, windowHeight), "Pong");
	Grid grid;
	grid.Level2();
	Texture tt;
	tt.loadFromFile("red rectangle.jpg");

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				// Someone closed the window- bye
				window.close();
		}

		window.clear();
		grid.draw(window);
		//br.draw(window);
		//window.draw(hex.getShape());
		window.display();
		
	}// This is the end of the "while" loop

	return 0;
}