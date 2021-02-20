#include "..\include\MovObject.h"

MovObject::MovObject(sf::Texture* texture, sf::Vector2f position, sf::FloatRect inrect, float LRspeed, float UDspeed, unsigned int power )
	:Object(texture,position, inrect, power), m_LRspeed(LRspeed), m_UDspeed(UDspeed)
{
}

void MovObject::move(float deltaTime)
{
	m_moved = sf::Vector2f(deltaTime * m_LRspeed, deltaTime * m_UDspeed);
	m_sprite.move(m_moved);
}

void MovObject::moveBack()
{
	m_sprite.move(-m_moved);
}
