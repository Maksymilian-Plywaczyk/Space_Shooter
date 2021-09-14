#pragma once
#include <SFML/Graphics.hpp>;
#include <vector>
#include <memory>
#include <iostream>
#include "SpaceShip.h"
#include "Bullet.h"


class Enemies
{
private:		
	sf::Sprite enemies;
	sf::Texture enemies_texture;
	sf::Vector2f position;
	 int enemies_speed_x = 0;
	 int enemies_speed_y = 100;
	 std::vector<Enemies*>enemies_;
	 int EnemiesSpawnTime = 0;
	 int HP;
	 int HPMax;



public:
	Enemies(sf::Vector2f position_);
	void enemies_draw(sf::RenderWindow& window);
	void enemies_bounds(sf::RenderWindow& window,sf::Time&elapsed);
	void enemies_animation(sf::RenderWindow& window, sf::Time& elapsed,SpaceShip ship,std::vector<Bullet*>&bullets, std::vector<Bullet*>& bullets2);
	const sf::FloatRect getBounds();





};

