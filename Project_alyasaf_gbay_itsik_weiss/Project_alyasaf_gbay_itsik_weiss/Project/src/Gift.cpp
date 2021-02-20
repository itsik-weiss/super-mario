#include "Gift.h"

Gift::Gift(sf::Texture* texture, sf::Vector2f position, sf::FloatRect inrect)
	:StaticObject(texture, position, inrect)
{
	m_sprite.setScale(0.25, 0.25);
}

void Gift::CollisionWithPlayer()
{
	m_power = 0;
}
