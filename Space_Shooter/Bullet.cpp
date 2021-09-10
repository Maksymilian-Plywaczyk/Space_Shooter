#include "Bullet.h"

Bullet::Bullet(sf::Vector2f position_):position(position_)
{
	
	if (!this->bullet_texture.loadFromFile("textures/bullets.png"))
	{
		std::cout << "Tekstury pociskow zaladowane nie poprawnie" << std::endl;
	}
	else
		std::cout << "Tekstury pociskow zaladowane poprawnie" << std::endl;
	bullet.setTexture(bullet_texture);
	bullet.setOrigin(bullet.getGlobalBounds().width / 2, bullet.getGlobalBounds().height / 2);
	bullet.setPosition(position);
    std::cout <<"BULLET"<< bullet.getPosition().x <<" "<< bullet.getPosition().y << std::endl;
}

void Bullet::bullet_draw(sf::RenderWindow& window)
{
	window.draw(bullet);
}

void Bullet::bullet_shooting()
{
	bullet.move(0, -speed_bullet);
}

void Bullet::player_shooting(sf::RenderWindow& window,SpaceShip spaceship)
{
    if (shootTime < 15)
        shootTime++;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && shootTime >= 15)
    {
        isShooting = true;
        shootTime = 0;
    }
    if (isShooting == true) {

        bullets.push_back(new Bullet(spaceship.getPosition()));
        isShooting = false;
    }
    for (int i = 0; i < bullets.size(); ++i)
    {
        bullets[i]->bullet_draw(window);
        bullets[i]->bullet_shooting();
    }

}







