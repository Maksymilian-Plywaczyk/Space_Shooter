#include "Meteorite.h"

Meteorite::Meteorite(sf::Vector2f pos):meteorite_position(pos)
{
	if (!this->meteorite_texture.loadFromFile("textures/meteorite.png")) {
		std::cout << "Blad odczytu pliku" << std::endl;
	}
	else
		std::cout << "Poprawne wczytanie pliku" << std::endl;

	this->meteorite_texture.setSmooth(true);
	meteorite.setTexture(meteorite_texture);
	meteorite.setPosition(meteorite_position);
}

void Meteorite::meteorite_draw(sf::RenderWindow& window)
{
	window.draw(meteorite);
}

void Meteorite::meteorite_update(sf::RenderWindow& window, sf::Time& elapsed)
{
	meteorite.move(meteorite_speed_x * elapsed.asSeconds(), meteorite_speed_y * elapsed.asSeconds());
	for (auto itr = meteorites.begin(); itr != meteorites.end();)
	{
		if ((*itr)->meteorite.getPosition().y >= window.getSize().y - (*itr)->meteorite.getGlobalBounds().height) {
			itr = meteorites.erase(itr);
		}
		else
		{
			itr++;
			(*itr)->meteorite_draw(window);
		}
	}
}

void Meteorite::meteorite_animation(sf::RenderWindow& window, sf::Time& elapsed, SpaceShip ship)
{
	if (meteorite_spawn_time < 50)
	{
		meteorite_spawn_time++;
	}
	if (meteorite_spawn_time >= 50)
	{

		sf::Vector2f position(std::rand() % (window.getSize().x), 0);
		meteorites.push_back(new Meteorite(position));
		meteorite_spawn_time = 0;
	}

	for (auto itr = meteorites.begin(); itr != meteorites.end();)
	{
		(*itr)->meteorite_update(window, elapsed);
		if ((*itr)->meteorite.getGlobalBounds().intersects(ship.getBounds()))
		{
			itr = meteorites.erase(itr);
			std::cout << "KOLIZJA STATKU Z PRZECIWNIKIEM" << std::endl;
			ship.HP--;
			std::cout << ship.HP << std::endl;
		}
		else
		{
			(*itr)->meteorite_draw(window);
			itr++;
		}
	}
}


