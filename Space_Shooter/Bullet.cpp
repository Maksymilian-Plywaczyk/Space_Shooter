#include "Bullet.h"

Bullet::Bullet(float posx,float posy)
{
	bullet.setPosition(sf::Vector2f(posx,posy));
	if (!this->bullet_texture.loadFromFile("textures/bullets.png"))
	{
		std::cout << "Tekstury pociskow zaladowane nie poprawnie" << std::endl;
	}
	else
		std::cout << "Tekstury pociskow zaladowane poprawnie" << std::endl;
	bullet.setTexture(bullet_texture);

}

void Bullet::bullet_draw(sf::RenderWindow& window)
{
	window.draw(bullet);
}

void Bullet::bullet_shooting()
{
	bullet.move(0, -speed_bullet);
}







