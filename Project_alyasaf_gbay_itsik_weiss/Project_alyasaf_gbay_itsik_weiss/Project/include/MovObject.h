#pragma once
#include "Object.h"

class MovObject :public Object
{
public:
	 MovObject(sf::Texture* texture, sf::Vector2f position, sf::FloatRect inrect, float LRspeed = 0, float UDspeed = 0,unsigned int power = 1);
	 virtual void move( float deltaTime) =0;
	 virtual void moveBack();
protected:
	sf::Vector2f m_moved;
	float m_LRspeed;
	float m_UDspeed;
};