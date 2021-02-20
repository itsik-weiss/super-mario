#include "..\include\Wall.h"

Wall::Wall(sf::Texture* texture, sf::Vector2f position, sf::FloatRect inrect)
	: StaticObject(texture, position, inrect)
{
}
