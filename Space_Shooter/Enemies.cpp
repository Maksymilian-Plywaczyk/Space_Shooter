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
