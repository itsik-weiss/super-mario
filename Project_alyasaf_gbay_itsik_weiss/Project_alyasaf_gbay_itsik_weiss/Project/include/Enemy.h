#pragma once
#include "MovObject.h"
class Enemy: public MovObject
{
public:
	Enemy(sf::Texture* texture, sf::Vector2f position, sf::FloatRect inrect, float LRspeed = 0, float UDspeed = 0, unsigned int power = 1);

private:

};


