#include "GameWindow.h"

void GameWindow::GameLoop()
{
    const unsigned int width = 1000;
    const unsigned int height = 1000;
    sf::RenderWindow window(sf::VideoMode(width, height), "SpaceShooter");

    sf::Vector2f position_map(0, 0);
    sf::Vector2f position_bullet(200, 200);
    SpaceShip spaceship(sf::Vector2f(width / 2, height - 42));
    Map map1(position_map);
    Bullet bullet(sf::Vector2f(0, 0));
    Enemies enemies(sf::Vector2f(200.0, 300.0));
    Meteorite meteorite(sf::Vector2f(0, 0));
    window.setFramerateLimit(60);
    sf::Clock clock;
    srand(time(NULL));
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
        //enemies.enemies_bounds(window,elapsed);
        window.clear();
        window.draw(map1);

        bullet.player_shooting(window, spaceship);
        meteorite.meteorite_animation(window, elapsed, spaceship,bullet.bullets,bullet.bullets2);
        enemies.enemies_animation(window, elapsed, spaceship, bullet.bullets, bullet.bullets2);



        spaceship.SpaceShip_draw(window);


        window.display();
    }

}
