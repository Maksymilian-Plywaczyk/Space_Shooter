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
		bool isShooting = false;
		bool isShooting2 = false;
		int shootTime1 = 0;
		int shootTime = 0;
		int bulletDamage = 0;
		
	public:
	std::vector<Bullet*>bullets;
	std::vector<Bullet*>bullets2;
	Bullet(sf::Vector2f position_);
	void bullet_draw(sf::RenderWindow& window);
	void bullet_shooting ();
	void player_shooting(sf::RenderWindow& window,SpaceShip spaceship);
	const sf::FloatRect getBounds();
	const sf:: Vector2f getPos();

	
};

