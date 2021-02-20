#pragma once
#include "Enemy.h"
//class MovObject;
class Monster :public Enemy
{
public:
	Monster(sf::Texture* texture, sf::Vector2f position, sf::FloatRect inrect, float LRspeed = 0, float UDspeed = 0, unsigned int power =1);
	void move(float deltaTime)override;

	void CollisionWithWall();
	void CollisionWithPlayer();
	void CollisionWithPlayerShot();

private:

};

