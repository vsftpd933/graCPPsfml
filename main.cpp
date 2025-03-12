#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Unit.h"
#include "Caveman1.h"
#include "Game.h"


int main()
{
    Game game;
    std::vector<Unit*> units;

    sf::RenderWindow window(sf::VideoMode({ 1920, 1080}), "GRA");

    sf::Texture background("background.png");
    sf::Sprite bg(background);

    while (window.isOpen())
    {
        //show fps
        game.showFps();

        // Process events
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Space)
                {
                    units.push_back(new Caveman1());
                    units[units.size() - 1]->getSprite()->setPosition(sf::Vector2f(0.f, 650.f));
                }
            }
            
        }

        // Clear and draw
      
        //background
        window.draw(bg);
        
        //window.clear();  //background clears

        for (int i = 0; i < units.size(); i++)
        {
            //walking
            units[i]->walk(game.deltaTime);

            window.draw(*units[i]->getSprite());
        }
        window.display();
    }

    return 0;
}
