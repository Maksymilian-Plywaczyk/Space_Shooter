#pragma once
#include <SFML/Graphics.hpp>
#include "GameWindow.h"
#include "Menu.h"

class Game
{
public:
	Game();
	void run();
	void start();
	void iMenu();
	void uPollEventsMenu();
	sf::RenderWindow* windowMenu;
	Menu* menu;

};

