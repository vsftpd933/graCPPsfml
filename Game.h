#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Game
{
public:
    sf::Clock clock;
    sf::Time deltaTime;
	Game();
    void showFps();

    // Variables for FPS calculation
    sf::Clock fpsClock;
    int frameCount = 0;
    sf::Time elapsedTime = sf::Time::Zero;
};

