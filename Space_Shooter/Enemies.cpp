#include "Enemies.h"

Enemies::Enemies(sf::Vector2f position_):position(position_)
{
	if (!this->enemies_texture.loadFromFile("textures/enemies.png"))
	{
		std::cout << "Tekstury pociskow zaladowane nie poprawnie" << std::endl;
	}
	else
		std::cout << "Tekstury pociskow zaladowane poprawnie" << std::endl;
	enemies.setTexture(enemies_texture);
	this->enemies_texture.setSmooth(true);
	enemies.setOrigin(enemies.getGlobalBounds().width / 2, enemies.getGlobalBounds().height / 2);
	enemies.setPosition(position);
	std::cout << "Enemies" << enemies.getPosition().x << " " <<	enemies.getPosition().y << std::endl;	
	
	this->HPMax = rand() % 10 + 1;
	this->HP = this->HPMax;
}

void Enemies::enemies_draw(sf::RenderWindow& window)
{
	window.draw(enemies);
}

void Enemies::enemies_bounds(sf::RenderWindow& window,sf::Time&elapsed)
{
	auto enemies_bounds = enemies.getGlobalBounds();

	if (enemies_bounds.left<=0)
	{
		enemies_speed_x = std::abs(enemies_speed_x);
	}
	if (enemies_bounds.left + enemies_bounds.width >= window.getSize().x)
	{
		enemies_speed_x=-std::abs(enemies_speed_x);
	}
	enemies.move(enemies_speed_x * elapsed.asSeconds(), enemies_speed_y * elapsed.asSeconds());
}

void Enemies::enemies_animation(sf::RenderWindow& window, sf::Time& elapsed, SpaceShip ship, std::vector<Bullet*>&bullets, std::vector<Bullet*>& bullets2)
{

	if (EnemiesSpawnTime < 50)
	{
		EnemiesSpawnTime++;
	}
	if (EnemiesSpawnTime >= 50)
	{

		sf::Vector2f position(std::rand() % (window.getSize().x), 0);
		enemies_.push_back(new Enemies(position));
		EnemiesSpawnTime = 0;
	}
	for (auto itr = enemies_.begin(); itr != enemies_.end();)
	{

		(*itr)->enemies_bounds(window, elapsed);
		if ((*itr)->enemies.getPosition().y >= window.getSize().y - (*itr)->enemies.getGlobalBounds().height)
		{
			itr = enemies_.erase(itr);
		}
		else
		{
			(*itr)->enemies_draw(window);
			itr++;
		}
	}
	for (auto itr = enemies_.begin(); itr != enemies_.end();)
	{
		if ((*itr)->enemies.getGlobalBounds().intersects(ship.getBounds()))
		{
			itr = enemies_.erase(itr);
			std::cout << "KOLIZJA STATKU Z PRZECIWNIKIEM" << std::endl;
			ship.HP--;
			std::cout << ship.HP<< std::endl;
		}
		else
		{
			(*itr)->enemies_draw(window);
			itr++;
		}
	}
	for (auto itr = enemies_.begin(); itr != enemies_.end();)
	{
		bool czyUsunietoPrzeciwnika = false;
		for (auto itr2 = bullets.begin(); itr2 != bullets.end();)
		{
			if ((*itr)->getBounds().intersects((*itr2)->getBounds()))
			{
				if ((*itr)->HP <= 1)
				{
					itr = enemies_.erase(itr);
				}
				else
				{
					(*itr)->HP--;
				}
				itr2 = bullets.erase(itr2);
				std::cout << "Usunieto przeciwnika" << std::endl;
				czyUsunietoPrzeciwnika = true;
				break;
			}
			else {
				(*itr)->enemies_draw(window);
				itr2++;
			}
		}
		if (!czyUsunietoPrzeciwnika) {
			itr++;
		}
	}
	for (auto itr = enemies_.begin(); itr != enemies_.end();)
	{
		bool czyUsunietoPrzeciwnika = false;
		for (auto itr2 = bullets2.begin(); itr2 != bullets2.end();)
		{
			if ((*itr)->getBounds().intersects((*itr2)->getBounds()))
			{
				if ((*itr)->HP <= 1)
				{
					itr = enemies_.erase(itr);
				}
				else
				{
					(*itr)->HP--;
				}
			
				itr2 = bullets2.erase(itr2);
				std::cout << "Usunieto przeciwnika" << std::endl;
				czyUsunietoPrzeciwnika = true;
				break;
			}
			else {
				(*itr)->enemies_draw(window);
				itr2++;
			}
		}
		if (!czyUsunietoPrzeciwnika) {
			itr++;
		}
	}
	ship.playerKilling(window);
}

const sf::FloatRect Enemies::getBounds()
{
	return enemies.getGlobalBounds();
}



