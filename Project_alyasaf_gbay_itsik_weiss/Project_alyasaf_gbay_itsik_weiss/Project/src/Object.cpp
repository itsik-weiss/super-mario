#include "Object.h"


//*****************************************************************************
Object::Object(sf::Texture* texture, sf::Vector2f position, sf::FloatRect inrect, int power)
	:m_sprite(*texture, sf::IntRect( inrect)), m_power(power)
{
	m_sprite.setPosition(position);
}
//------------------------------------------------------------
void Object::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
}

sf::Vector2f Object::getPosition()
{
	return m_sprite.getPosition();
}

unsigned Object::getPower()
{
	return m_power;
}

sf::FloatRect Object::getGlobalBounds() const
{
	return m_sprite.getGlobalBounds();
}

bool Object::checkCollision(const sf::FloatRect& floatRect) const
{
	return getGlobalBounds().intersects(floatRect);
}