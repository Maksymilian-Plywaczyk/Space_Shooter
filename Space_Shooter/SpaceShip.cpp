#include "SpaceShip.h"

SpaceShip::SpaceShip(sf::Vector2f& position_) :position(position_){
	
	this->setPosition(position_); //set Position of SpaceShip
	if (!this->spaceship_texture.loadFromFile("textures/spaceship.png")) {
		std::cout << "Blad odczytu pliku" << std::endl;
	}
	else
		std::cout << "Poprawne wczytanie pliku" << std::endl;
	auto textureSize = this->spaceship_texture.getSize();
	this->setTexture(spaceship_texture);
	this->setOrigin(this->getGlobalBounds().width / 2, this->getGlobalBounds().height / 2); //Set Origin to middle of sprite
	std::cout <<"Size x:"<< spaceship_texture.getSize().x <<" Size y:"<< spaceship_texture.getSize().y << std::endl;
}

void SpaceShip::SpaceShip_animate(sf::Time& elapsed)
{
	sf::FloatRect spaceship_bounds = getGlobalBounds();
	std::cout << spaceship_bounds.left + spaceship_bounds.width << " " << spaceship_bounds.top + spaceship_bounds.height << std::endl;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (spaceship_bounds.left >= 0)
		{
			this->move(-speed_of_direction_x * elapsed.asSeconds(),0);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (spaceship_bounds.top >= 0)
		{
			this->move(0, -speed_of_direction_y*elapsed.asSeconds());
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (spaceship_bounds.left+spaceship_bounds.width <= 1000)
		{
			this->move(speed_of_direction_x * elapsed.asSeconds(), 0);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (spaceship_bounds.top+spaceship_bounds.height <= 1000)
		{
			this->move(0, speed_of_direction_y * elapsed.asSeconds());
		}
	}


}
