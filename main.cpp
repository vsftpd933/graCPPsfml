#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

int main()
{
    const float speed = 200.f; // Speed in pixels per second
    sf::Clock clock;
    sf::RenderWindow window(sf::VideoMode({ 800, 800 }), "SFML works!");

    // Variables for FPS calculation
    sf::Clock fpsClock;
    int frameCount = 0;
    sf::Time elapsedTime = sf::Time::Zero;

    //rectangles array
    std::vector<sf::Sprite*> rectangles;
    //sprite texture
    sf::Texture texture("caveman1.png");

    while (window.isOpen())
    {
        // Calculate time elapsed since last frame
        sf::Time deltaTime = clock.getElapsedTime();
        clock.restart();

        // Move the rectangles
        for (int i = 0; i < rectangles.size(); i++)
        {
            sf::Vector2f currentPosition = rectangles[i]->getPosition();
            rectangles[i]->setPosition(currentPosition + sf::Vector2f(speed * deltaTime.asSeconds(), 0.f));
            
        }
        
        

        // Update FPS calculation
        frameCount++;
        elapsedTime += deltaTime;

        if (elapsedTime.asSeconds() >= 1.f)
        {
            std::cout << "FPS: " << frameCount << std::endl;
            frameCount = 0;
            elapsedTime = sf::Time::Zero;
        }

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
                    rectangles.push_back(new sf::Sprite(texture));
                    rectangles[rectangles.size() - 1]->setPosition(sf::Vector2f(0.f, 500.f));
                    //rectangles[rectangles.size() - 1]->setColor(sf::Color::Green);
                    //window.close();
                }
            }

            
        }

        
        // Clear and draw
      
        window.clear();
        for (int i = 0; i < rectangles.size(); i++)
        {
            window.draw(*rectangles[i]);
        }
        window.display();
    }

    return 0;
}
