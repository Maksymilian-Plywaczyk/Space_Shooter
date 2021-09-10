#pragma once

#include <SFML/Graphics.hpp>;
#include <vector>
#include <memory>
#include "SpaceShip.h"

class Bullet
{
	private:
		const int speed_bullet = 10;
		sf::Sprite bullet;
		sf::Texture bullet_texture;
		sf::Vector2f position;
		std::vector<Bullet*>bullets;
		bool isShooting = false;
		int shootTime = 20;
		
	public:
	
	Bullet(sf::Vector2f position_);
	void bullet_draw(sf::RenderWindow& window);
	void bullet_shooting ();
	void player_shooting(sf::RenderWindow& window,SpaceShip spaceship);
	const sf::FloatRect getBounds();
	
};

