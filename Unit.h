#pragma once
#include <SFML/Graphics.hpp>

//abstract class
class Unit 
{
public:

	virtual void attack()=0;
	virtual void walk(sf::Time deltaTime) = 0;
	virtual sf::Sprite* getSprite()=0;

	int hp;
	int damage;
	double walkingSpeed;
	int attackSpeed;
	bool alive;

};

