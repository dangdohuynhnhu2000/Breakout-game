#pragma once
#include <SFML/Graphics.hpp>
#include <conio.h>
#include <sstream>
#include <cstdlib>
#include <iostream>
using namespace std;
using namespace sf;
#include "Paddle.h"
#include "Ball.h"
#include "Wall.h"
#include "Menu.h"
#include <string>
#include <ctime>
#include "Rectangle.h"
#include "Figure.h"
#include "Grid.h"



void defaultPos(Paddle& paddle1, Paddle& paddle2, Ball& ball); //dua ban do, bong ve vi tri mac dinh
void drawToWindow(sf::RenderWindow& window, Paddle paddle1, Paddle paddle2, Ball ball, Wall wall, sf::Text Exit); //thao tac ve bang tuong bong
void changeSpeed(sf::RenderWindow& window, sf::Event& event, sf::Text& Level, int& speed, Menu); //tang giam toc do
void changeSetting(sf::RenderWindow& window, sf::Event& event, sf::Text& Level, float& defaulSpeed, float& ballSpeed, float& padSpeed, int& speed, bool& AIMode, sf::Text & Mode); //thay doi mode, speed
void changeMode(sf::RenderWindow& window, sf::Event& event, Menu optionScreen, bool& AImode, sf::Text &Mode); //doi che do 1 player hoac 2 player
void gamePlay(sf::RenderWindow& window, sf::Font font, float padSpeed, float ballSpeed, float defaultSpeed, bool& playing, bool AIMode); //thuc hien cac hoat dong cua game
void result(int scoreLeft, int scoreRight, sf::Text& Result); //thống kê điểm

