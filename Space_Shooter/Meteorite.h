#pragma once
#include <SFML/Graphics.hpp>;
#include <vector>
#include <iostream>
#include "SpaceShip.h"
#include "Bullet.h"
class Meteorite
{
private:
	sf::Sprite meteorite;
	sf::Texture meteorite_texture;
	sf::Vector2f meteorite_position;
	int meteorite_speed_x = 0;
	int meteorite_speed_y = 200;
	std::vector<Meteorite*>meteorites;
	int meteorite_spawn_time = 0;
public:
	Meteorite(sf::Vector2f pos);
	void meteorite_draw(sf::RenderWindow& window);
	void meteorite_update(sf::RenderWindow& window, sf::Time& elapsed);
	void meteorite_animation(sf::RenderWindow& window, sf::Time& elapsed, SpaceShip ship);
};

