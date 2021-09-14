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
	this->meteoriteHPMax = rand() % 3 + 1;
	this->meteoriteHP=this->meteoriteHPMax;
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

void Meteorite::meteorite_animation(sf::RenderWindow& window, sf::Time& elapsed, SpaceShip ship, std::vector<Bullet*>& bullets, std::vector<Bullet*>& bullets2)
{
	if (meteorite_spawn_time < 100)
	{
		meteorite_spawn_time++;
	}
	if (meteorite_spawn_time >= 100)
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
	for (auto itr = meteorites.begin(); itr != meteorites.end();)
	{
		bool czyUsunietoPrzeciwnika = false;
		for (auto itr2 = bullets.begin(); itr2 != bullets.end();)
		{
			if ((*itr)->meteorite.getGlobalBounds().intersects((*itr2)->getBounds()))
			{
				if ((*itr)->meteoriteHP <= 1)
				{
					itr = meteorites.erase(itr);
				}
				else
				{
					(*itr)->meteoriteHP--;
				}
				itr2 = bullets.erase(itr2);
				std::cout << "Usunieto przeciwnika" << std::endl;
				czyUsunietoPrzeciwnika = true;
				break;
			}
			else {
				(*itr)->meteorite_draw(window);
				itr2++;
			}
		}
		if (!czyUsunietoPrzeciwnika) {
			itr++;
		}
	}
	for (auto itr = meteorites.begin(); itr != meteorites.end();)
	{
		bool czyUsunietoPrzeciwnika = false;
		for (auto itr2 = bullets2.begin(); itr2 != bullets2.end();)
		{
			if ((*itr)->meteorite.getGlobalBounds().intersects((*itr2)->getBounds()))
			{
				if ((*itr)->meteoriteHP <= 1)
				{
					itr = meteorites.erase(itr);
				}
				else
				{
					(*itr)->meteoriteHP--;
				}
				itr2 = bullets2.erase(itr2);
				std::cout << "Usunieto przeciwnika" << std::endl;
				czyUsunietoPrzeciwnika = true;
				break;
			}
			else {
				(*itr)->meteorite_draw(window);
				itr2++;
			}
		}
		if (!czyUsunietoPrzeciwnika) {
			itr++;
		}
	}
	ship.playerKilling(window);
}


