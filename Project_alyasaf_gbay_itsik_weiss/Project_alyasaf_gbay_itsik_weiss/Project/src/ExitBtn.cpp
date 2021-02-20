#include "ExitBtn.h"
#include "Controller.h"
//*****************************************************************************
ExitBtn::ExitBtn(const sf::Texture& texture, const sf::Vector2f& position)
	:Button(texture, position)
{
	m_sprite.setScale(0.99, 0.99);
}
//*****************************************************************************
bool ExitBtn::handleClick(const sf::Vector2f& clickLocation, Controller& ctrl) const
{
	if (m_sprite.getGlobalBounds().contains(clickLocation)) 
	{
		ctrl.exitGame();
		return true;
	}
		
	return false;
}
//------------------------------------------------------------