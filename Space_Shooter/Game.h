#pragma once
#include <SFML/Graphics.hpp>
#include "GameWindow.h"
#include "Menu.h"

class Game
{
public:
	sf::RenderWindow* windowMenu;
	Menu* menu;
	void iMenu();
	void run();
	void start();
	void uPollEventsMenu();
	Game();
	~Game();
};

