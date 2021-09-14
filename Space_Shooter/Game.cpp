#include "Game.h"

Game::Game()
{
    this->iMenu();
}
void Game::run()
{
    GameWindow game;
    game.GameLoop();
}

void Game::start()
{
    while (this->windowMenu)
    {
        this->uPollEventsMenu();
    }
}
void Game::iMenu()
{
    this->windowMenu = new sf::RenderWindow(sf::VideoMode(1000, 1000), "Menu", sf::Style::Close | sf::Style::Titlebar);
    this->windowMenu->setFramerateLimit(60);
    this->windowMenu->setVerticalSyncEnabled(false);
    this->menu = new Menu(windowMenu->getSize().x, windowMenu->getSize().y);
}
void Game::uPollEventsMenu()
{
    sf::Event action;
    while (this->windowMenu->pollEvent(action))
    {
        switch (action.type)
        {
        case sf::Event::KeyReleased:
            switch (action.key.code)
            {
            case sf::Keyboard::Up:
                menu->Up();
                
                break;

            case sf::Keyboard::Down:
                menu->Down();
               
                break;

            case sf::Keyboard::Return:
                switch (menu->GetItemP())
                {
                case 0:
                    system("cls");
                    std::cout << "Play!" << std::endl;
                    
                    this->windowMenu->close();

                    delete this->windowMenu;
                    this->run();
                    break;
                case 1:
                    system("cls");
                    std::cout << "Quit" << std::endl;
                    
                    this->windowMenu->close();
                    delete this->windowMenu;
                    break;
                case 2:
                    system("cls");
                    std::cout << "-------------------------" << std::endl;
                    std::cout << "UP/DOWN/LEFT/RIGHT- moving your player" << std::endl;
                    std::cout << "LeftCTRL - Shoot, Style 1" << std::endl;
                    std::cout << "SPACE - Shoot, Style 2" << std::endl;
                    std::cout << "You got 45 seconds, go go go!" << std::endl;
                    std::cout << "-------------------------" << std::endl;
                    
                    break;
                }
                break;
            }
            break;
        case sf::Event::Closed:
            windowMenu->close();
            delete this->windowMenu;
            break;
        }
    }

    this->windowMenu->clear();

    menu->draw(*windowMenu);

    windowMenu->display();
}