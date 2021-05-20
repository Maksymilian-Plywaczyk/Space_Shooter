#include "Map.h"

Map::Map(sf::Vector2f& position_) :position(position_)
{
	this->setPosition(position);
	if (!this->background_texture.loadFromFile("textures/background_SpaceShooter.png"))
	{
		std::cout << "Tekstura mapy zaladowana nie poprawnie" << std::endl;			
	}
	else
		std::cout << "Tekstura mapy zaladowana poprawnie" << std::endl;
	this->setTexture(background_texture);
}

