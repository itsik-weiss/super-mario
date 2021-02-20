#pragma once
#include "StaticObject.h"

class Food:public StaticObject
{
public:
	Food(sf::Texture* texture, sf::Vector2f position, sf::FloatRect inrect);
	void CollisionWithPlayer();
	//~Food();

private:

};

