#pragma once
#include "StaticObject.h"
class Wall:public StaticObject
{
public:
	Wall(sf::Texture* texture, sf::Vector2f position, sf::FloatRect inrect);
private:

};