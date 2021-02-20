#pragma once
#include "MovObject.h"

class PlayerShot:public MovObject
{
public:
	PlayerShot(sf::Texture* texture, sf::Vector2f position, sf::FloatRect inrect, float LRspeed = 0, float UDspeed = 0);
	void move(float deltaTime)override;

	void CollisionWithMonster();
	void CollisionWithWall();


private:

};

