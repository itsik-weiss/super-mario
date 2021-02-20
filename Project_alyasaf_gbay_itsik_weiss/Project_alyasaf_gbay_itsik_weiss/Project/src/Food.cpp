#include "Food.h"
//#include "StaticObject.h"

Food::Food(sf::Texture* texture, sf::Vector2f position, sf::FloatRect inrect)
	:StaticObject(texture, position, inrect)
{
}

void Food::CollisionWithPlayer()
{
	m_power = 0;
}
