#include "Enemy.h"

Enemy::Enemy(sf::Texture* texture, sf::Vector2f position, sf::FloatRect inrect, float LRspeed, float UDspeed, unsigned int power)
	: MovObject(texture, position, inrect, LRspeed, UDspeed, power)
{
}
