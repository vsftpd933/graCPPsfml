#pragma once
#include "Unit.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "Game.h"

class Caveman1 :
    public Unit
{
public:
    Caveman1();
    void walk(sf::Time deltaTime);
    void attack();

    double walkingSpeed=70.0;

    sf::Sprite* getSprite();

    sf::Texture* texture;
    sf::Sprite* sprite;

    std::vector<sf::Texture*> walkTextures;
    int walkAnimationFrameCount=0; 
    sf::Time timeFromLastAnimation = sf::Time::Zero;
};

