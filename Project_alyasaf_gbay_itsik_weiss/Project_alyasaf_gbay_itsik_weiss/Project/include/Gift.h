#pragma once
#include "StaticObject.h"

class Gift:public StaticObject
{
public:
	Gift(sf::Texture* texture, sf::Vector2f position, sf::FloatRect inrect);
	void CollisionWithPlayer();

	//~Gift();

private:

};

