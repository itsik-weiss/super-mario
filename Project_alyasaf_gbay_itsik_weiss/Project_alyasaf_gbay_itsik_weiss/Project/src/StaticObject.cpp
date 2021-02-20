#pragma once
#include "StaticObject.h"

StaticObject::StaticObject(sf::Texture* texture, sf::Vector2f position, sf::FloatRect inrect)
	:Object(texture, position, inrect)
{
}
