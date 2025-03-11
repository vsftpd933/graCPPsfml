#include "Game.h"
#include <SFML/Graphics.hpp>

Game::Game()
{
    
}

void Game::showFps()
{
    // Calculate time elapsed since last frame
    deltaTime = clock.getElapsedTime();
    clock.restart();


    // Update FPS calculation
    frameCount++;
    elapsedTime += deltaTime;

    if (elapsedTime.asSeconds() >= 1.f)
    {
        std::cout << "FPS: " << frameCount << std::endl;
        frameCount = 0;
        elapsedTime = sf::Time::Zero;
    }
}
