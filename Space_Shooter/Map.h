 #pragma once

#include<SFML/Graphics.hpp>
#include <iostream>

class Map:public sf::Sprite
{
	private:
		sf::Texture background_texture;
		sf::Vector2f position;
	public:
		Map(sf::Vector2f& position_);
};

