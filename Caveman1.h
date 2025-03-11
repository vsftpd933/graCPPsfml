#pragma once
#include "Unit.h"
#include <SFML/Graphics.hpp>

class Caveman1 :
    public Unit
{
public:
    //constructors
    Caveman1();
    void walk(sf::Time deltaTime);
    void attack();

    sf::Sprite* getSprite();

    sf::Texture* texture;
    sf::Sprite* sprite;
};

