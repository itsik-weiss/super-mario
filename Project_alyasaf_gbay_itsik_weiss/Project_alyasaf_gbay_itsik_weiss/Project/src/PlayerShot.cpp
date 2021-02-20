#include "PlayerShot.h"

PlayerShot::PlayerShot(sf::Texture* texture, sf::Vector2f position, sf::FloatRect inrect, float LRspeed, float UDspeed)
	:MovObject(texture, position, inrect, LRspeed, UDspeed)
{
}

void PlayerShot::move(float deltaTime)
{
	MovObject ::move(deltaTime);
}

void PlayerShot::CollisionWithMonster()
{
	m_power = 0;
}

void PlayerShot::CollisionWithWall()
{
	m_power = 0;
}
