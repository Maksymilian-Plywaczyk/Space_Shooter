#pragma once


#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>
#include "Bullet.h"

class SpaceShip
{
private:
	sf::Sprite ship;
	sf::Texture spaceship_texture;
	sf::Vector2f position;
	const  int speed_of_direction_x = 400;
	const  int speed_of_direction_y = 400;
	bool isShooting=false;
	

public:
	
	SpaceShip(sf::Vector2f position_);
	void SpaceShip_animate(sf::Time& elapsed);
	void SpaceShip_draw(sf::RenderWindow& window);
	const sf::FloatRect getBounds();
	const sf::Vector2f getPosition();
	//void shipShooting(std::vector<Bullet*>&bullets,sf::RenderWindow& window);

};

