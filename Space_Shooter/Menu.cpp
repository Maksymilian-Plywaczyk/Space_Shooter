#include "Menu.h"
Menu::Menu(float width, float height)
{
    if (!F.loadFromFile("Fonts/font.ttf"))
    {

    }

    this->initializeSpriteMenu();

    menu[0].setFont(F);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setString("Play");
    menu[0].setOrigin(menu[0].getGlobalBounds().width / 2, menu[0].getGlobalBounds().height / 2);
    menu[0].setPosition(sf::Vector2f(width / 2, height / 4 * 1 + 60));

    menu[1].setFont(F);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Exit");
    menu[1].setOrigin(menu[1].getGlobalBounds().width / 2, menu[1].getGlobalBounds().height / 2);
    menu[1].setPosition(sf::Vector2f(width / 2, height / 4 * 2 + 60));

    menu[2].setFont(F);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("Controls");
    menu[2].setOrigin(menu[2].getGlobalBounds().width / 2, menu[2].getGlobalBounds().height / 2);
    menu[2].setPosition(sf::Vector2f(width / 2, height / 4 * 3 + 60));

    Ind = 0;
}

void Menu::initializeSpriteMenu()
{
    if (!this->textureMenu.loadFromFile("Textures/space1.png"))
    {
        std::cout << "Could not load texture file." << "\n";
    }
    this->spriteMenu.setTexture(this->textureMenu);

}

void Menu::draw(sf::RenderWindow& window)
{
    window.draw(spriteMenu);

    for (int i = 0; i < 3; i++)
    {
        window.draw(menu[i]);
    }
}

void Menu::Up()
{
    if (Ind - 1 >= 0)
    {
        menu[Ind].setFillColor(sf::Color::White);
        Ind--;
        menu[Ind].setFillColor(sf::Color::Red);
    }
}

void Menu::Down()
{
    if (Ind + 1 < 3)
    {
        menu[Ind].setFillColor(sf::Color::White);
        Ind++;
        menu[Ind].setFillColor(sf::Color::Red);
    }
}