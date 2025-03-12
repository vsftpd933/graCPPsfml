#include "Caveman1.h"
#include <string>

Caveman1::Caveman1() 
{
	texture = new sf::Texture;
	texture->loadFromFile("animations/Caveman1/fromLeft/walk_attack_die.png");
	sf::IntRect rectangle({ 0,0 }, { 140,180 });
	sprite = new sf::Sprite(*texture);
	sprite->setTextureRect(rectangle);
}

void Caveman1::walk(sf::Time deltaTime)
{
	sf::Vector2f currentPosition = sprite->getPosition();
	sprite->setPosition(currentPosition + sf::Vector2f(walkingSpeed * deltaTime.asSeconds(), 0.f));
	
	timeFromLastAnimation += deltaTime;
	if (timeFromLastAnimation.asSeconds() >= 0.22f)
	{
		timeFromLastAnimation = sf::Time::Zero;
		sf::IntRect rectangle({ 140*walkAnimationFrameCount,180*0 }, { 140,180 });
		sprite->setTextureRect(rectangle);
		walkAnimationFrameCount++;
		if (walkAnimationFrameCount == 3)
		{
			walkAnimationFrameCount = 0;
		}
	}
}

void Caveman1::attack()
{
}

sf::Sprite* Caveman1::getSprite()
{
	return sprite;
}

