#include "SpaceShip.h"
#include "Bullet.h"

SpaceShip::SpaceShip(sf::Vector2f position_) :position( position_){
	

	if (!this->spaceship_texture.loadFromFile("textures/spaceship.png")) {
		std::cout << "Blad odczytu pliku" << std::endl;
	}
	else
		std::cout << "Poprawne wczytanie pliku" << std::endl;
	
	this->spaceship_texture.setSmooth(true);
	ship.setTexture(spaceship_texture);
	ship.setOrigin(ship.getGlobalBounds().width / 2, ship.getGlobalBounds().height / 2);

	std::cout <<"Origin x: "<< ship.getOrigin().x<<"Origin y:"<< ship.getOrigin().y << std::endl;
	ship.setPosition(position_);
	std::cout << spaceship_texture.getSize().x << spaceship_texture.getSize().y << std::endl;
}

void SpaceShip::SpaceShip_animate(sf::Time& elapsed)
{
	sf::FloatRect spaceship_bounds = ship.getGlobalBounds();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (spaceship_bounds.left >= 0)
		{
			ship.move(-speed_of_direction_x * elapsed.asSeconds(),0);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (spaceship_bounds.top >= 0)
		{
			ship.move(0, -speed_of_direction_y*elapsed.asSeconds());
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (spaceship_bounds.left+spaceship_bounds.width <= 1000)
		{
			ship.move(speed_of_direction_x * elapsed.asSeconds(), 0);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (spaceship_bounds.top+spaceship_bounds.height <= 1000)
		{
			ship.move(0, speed_of_direction_y * elapsed.asSeconds());
		}
	}


}

void SpaceShip::SpaceShip_draw(sf::RenderWindow& window)
{
	window.draw(ship);
}

const sf::FloatRect SpaceShip::getBounds()
{
	return ship.getGlobalBounds();
}

const sf::Vector2f SpaceShip::getPosition()
{
	return ship.getPosition();
}

