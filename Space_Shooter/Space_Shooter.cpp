#include <SFML/Graphics.hpp>
#include "SpaceShip.h"
#include "Map.h"

int main()
{
    const unsigned int width = 1000;
    const unsigned int height = 1000;
    sf::RenderWindow window(sf::VideoMode(width, height), "SpaceShooter");
    
    sf::Vector2f position_map(0,0);
    sf::Vector2f position_bullet(200, 200);
    SpaceShip spaceship(sf::Vector2f(width/2,height-42));
    Map map1(position_map);
    std::vector<Bullet*>bullets;
    bool isShooting = false;
    int shootTime = 20;

    
    window.setFramerateLimit(60);
    sf::Clock clock;
    while (window.isOpen())
    {
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        sf::Time elapsed = clock.restart();
        
        spaceship.SpaceShip_animate(elapsed);
        window.clear();
        window.draw(map1);
        if (shootTime < 15)
            shootTime++;
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)&&shootTime>=15)
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

        spaceship.SpaceShip_draw(window);
    

        window.display();
    }

    return 0;
}
