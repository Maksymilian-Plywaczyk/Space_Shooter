#pragma once

#include <SFML/Graphics.hpp>;
#include <vector>
#include <memory>
#include "SpaceShip.h"


class Bullet
{
	private:
		 int speed_bullet = 0;
		sf::Sprite bullet;
		sf::Texture bullet_texture;
		sf::Vector2f position;
		std::vector<Bullet*>bullets;
		std::vector<Bullet*>bullets2;
		bool isShooting = false;
		bool isShooting2 = false;
		int shootTime1 = 0;
		int shootTime = 0;
		int bulletDamage = 0;
		
	public:
	
	Bullet(sf::Vector2f position_);
	void bullet_draw(sf::RenderWindow& window);
	void bullet_shooting ();
	void player_shooting(sf::RenderWindow& window,SpaceShip spaceship);
	const sf::FloatRect getBounds();
	const sf:: Vector2f getPos();
	
};

