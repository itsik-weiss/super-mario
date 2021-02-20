#pragma once
#include "Object.h"
class StaticObject:public Object
{
public:
	StaticObject(sf::Texture* texture, sf::Vector2f position, sf::FloatRect inrect);
private:

};
