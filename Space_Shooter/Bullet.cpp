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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
    {
        this->speed_bullet = 10;
        this->shootTime = 20;
        this->bulletDamage = 3;

    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        this->speed_bullet = 5;
        this->shootTime = 30;
        this->bulletDamage = 5;
    }
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
    
    if (shootTime1 < 35)
        shootTime1++;
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && shootTime >= 15)
    {
        isShooting = true;
        shootTime = 0;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && shootTime1 >=35 )
    {
        isShooting2 = true;
        shootTime1 = 0;
    }
    if (isShooting == true) {

        bullets.push_back(new Bullet(spaceship.getPosition()));
        isShooting = false;
    }
    if (isShooting2 == true) {

        bullets.push_back(new Bullet(sf::Vector2f(spaceship.getPosition().x-20,spaceship.getPosition().y)));
        bullets2.push_back(new Bullet(sf::Vector2f(spaceship.getPosition().x + 20, spaceship.getPosition().y)));
        isShooting2 = false;
    }
    for (auto itr = bullets.begin(); itr != bullets.end();)
    {

        if ((*itr)->getPos().y < window.getPosition().y)
        {
            itr= bullets.erase(itr);
            std::cout << "Usunieto kule" << std::endl;
        }
    
        else {
            (*itr)->bullet_draw(window);
            (*itr)->bullet_shooting();
            itr++;

        }
    }
    for (auto itr = bullets2.begin(); itr != bullets2.end();)
    {

        if ((*itr)->getPos().y < window.getPosition().y)
        {
            itr = bullets2.erase(itr);
            std::cout << "Usunieto kule" << std::endl;
        }
        else {
            (*itr)->bullet_draw(window);
            (*itr)->bullet_shooting();
            itr++;

        }
    }

   
}

const sf::FloatRect Bullet::getBounds()
{
    return bullet.getGlobalBounds();
}

const sf::Vector2f Bullet::getPos()
{
    return bullet.getPosition();
}







