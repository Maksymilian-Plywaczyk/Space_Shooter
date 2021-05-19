#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>

class SpaceShip :public sf::Sprite
{
private:
	sf::Texture spaceship_texture;
	sf::Vector2f position;
	const  int speed_of_direction_x = 250;
	const  int speed_of_direction_y = 250;

public:
	SpaceShip(sf::Vector2f& position_);
	void SpaceShip_animate(sf::Time& elapsed);

};

