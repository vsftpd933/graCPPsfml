#include "Caveman1.h"

Caveman1::Caveman1()
{
	texture = new sf::Texture("caveman1.png");
	sprite = new sf::Sprite(*texture);
}

void Caveman1::walk(sf::Time deltaTime)
{
	sf::Vector2f currentPosition = sprite->getPosition();
	sprite->setPosition(currentPosition + sf::Vector2f(walkingSpeed * deltaTime.asSeconds(), 0.f));
}

void Caveman1::attack()
{
}

sf::Sprite* Caveman1::getSprite()
{
	return sprite;
}

