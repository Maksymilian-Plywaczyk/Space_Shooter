#include <SFML/Graphics.hpp>
#include "SpaceShip.h"
#include "Map.h"

int main()
{
    const unsigned int width = 1000;
    const unsigned int height = 1000;
    sf::RenderWindow window(sf::VideoMode(width, height), "SpaceShooter");
    sf::Vector2f position(width/2,height-31);
    sf::Vector2f position_map(0,0);
    SpaceShip spaceship(position);
    Map map1(position_map);
    
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
        window.draw(spaceship);
        
        window.display();
    }

    return 0;
}
