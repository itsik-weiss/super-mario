#include "Monster.h"

Monster::Monster(sf::Texture* texture, sf::Vector2f position, sf::FloatRect inrect, float LRspeed, float UDspeed, unsigned int power)
	:Enemy(texture, position, inrect, LRspeed, UDspeed, power)
{
}

void Monster::move(float deltaTime)
{
	MovObject::move(deltaTime);
}

void Monster::CollisionWithWall()
{
	moveBack();
	m_LRspeed *= -1;
	m_UDspeed *= -1;
}

void Monster::CollisionWithPlayer()
{
	if (m_power > 0)
		m_power--;
}

void Monster::CollisionWithPlayerShot()
{
	if (m_power > 0)
		m_power--;
}


