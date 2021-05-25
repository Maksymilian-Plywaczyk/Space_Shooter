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
		std::vector<Bullet>bullets;

	public:
	Bullet(float posx,float posy);
	void bullet_draw(sf::RenderWindow& window);
	void bullet_shooting ();
	
	
};

