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

void Enemies::enemies_animation(sf::RenderWindow& window, sf::Time& elapsed, SpaceShip ship)
{
	std::vector<Bullet*> bullet;
	if (EnemiesSpawnTime < 50)
	{
		EnemiesSpawnTime++;
	}
	if (EnemiesSpawnTime >= 50)
	{
		
		sf::Vector2f position(std::rand() % (window.getSize().x),0);
		enemies_.push_back(new Enemies(position));
		EnemiesSpawnTime = 0;
	}
	for (auto i = 0; i < enemies_.size(); i++)
	{
	
		enemies_[i]->enemies_bounds(window, elapsed);
		if (enemies_[i]->enemies.getPosition().y >= window.getSize().y - enemies_[i]->enemies.getGlobalBounds().height)
		{
			enemies_.erase(enemies_.begin() + i);
		}
		if (enemies_[i]->enemies.getGlobalBounds().intersects(ship.getBounds()))
		{
			enemies_.erase(enemies_.begin() + i);
			std::cout << "KOLIZJA STATKU Z PRZECIWNIKIEM" << std::endl;
		}
		for (auto k = 0; k< bullet.size(); k++)
		{
			if (enemies_[i]->enemies.getGlobalBounds().intersects(bullet[k]->getBounds()))
			{
				enemies_.erase(enemies_.begin() + i);
				bullet.erase(bullet.begin() + k);
				std::cout <<"KOLIZJA POCISKU Z PRZECIWNIKIEM" << std::endl;
				break;
			}
		}
		
	}
	for (auto i = 0; i <enemies_.size(); i++)
	{
		enemies_[i]->enemies_draw(window);
	}
}

const sf::FloatRect Enemies::getBounds()
{
	return enemies.getGlobalBounds();
}



