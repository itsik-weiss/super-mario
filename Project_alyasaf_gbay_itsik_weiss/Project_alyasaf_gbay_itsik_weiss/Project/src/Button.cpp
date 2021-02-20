#include "Button.h"
//#include "Macros.h"
//*****************************************************************************
Button::Button(const sf::Texture& texture,const sf::Vector2f& position)
	:m_sprite(texture)
{
	m_sprite.setScale(BUTTON_SCALE);
	m_sprite.setOrigin(BUTTON_ORIGIN);
	m_sprite.setPosition(position);
}
//*****************************************************************************
void Button::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
}
//------------------------------------------------------------
sf::FloatRect Button::getGlobalBounds() const
{
	return m_sprite.getGlobalBounds();
}
//------------------------------------------------------------