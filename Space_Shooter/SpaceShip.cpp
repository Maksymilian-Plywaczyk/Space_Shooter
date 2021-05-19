#include "SpaceShip.h"

SpaceShip::SpaceShip(sf::Vector2f& position_) :position(position_){

	this->setPosition(position_);
	if (!this->spaceship_texture.loadFromFile("textures/spaceship.png")) {
		std::cout << "Blad odczytu pliku" << std::endl;
	}
	else
		std::cout << "Poprawne wczytanie pliku" << std::endl;
	auto textureSize = this->spaceship_texture.getSize();
	this->setTexture(spaceship_texture);
	std::cout <<"Size x:"<< spaceship_texture.getSize().x <<" Size y:"<< spaceship_texture.getSize().y << std::endl;
}
