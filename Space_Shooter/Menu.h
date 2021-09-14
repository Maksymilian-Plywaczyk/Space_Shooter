#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
class Menu
{
public:

    Menu(float width, float height);
    sf::Texture textureMenu;
    sf::Sprite spriteMenu;

    void initializeSpriteMenu();
    void draw(sf::RenderWindow& window);
    void Up();
    void Down();
    int GetItemP() { return Ind; }
    int Ind;
    sf::Font F;
    sf::Text menu[3];

};

};

