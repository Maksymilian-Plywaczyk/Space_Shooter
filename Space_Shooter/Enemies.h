#pragma once
#include <SFML/Graphics.hpp>;
#include <vector>
#include <memory>
#include <iostream>
class Enemies
{
private:		
	sf::Sprite enemies;
	sf::Texture enemies_texture;
	sf::Vector2f position;

public:
	Enemies(sf::Vector2f position_);
	void enemies_draw(sf::RenderWindow& window);



};

