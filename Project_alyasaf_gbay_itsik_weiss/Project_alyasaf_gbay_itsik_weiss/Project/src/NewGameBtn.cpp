#include "NewGameBtn.h"
#include "Controller.h"
//*****************************************************************************
NewGameBtn::NewGameBtn(const sf::Texture& texture, const sf::Vector2f& position)
	:Button(texture, position)
{
	m_sprite.setScale(0.75, 0.75);
}
//*****************************************************************************
bool NewGameBtn::handleClick(const sf::Vector2f& clickLocation, Controller& ctrl) const
{
	if (m_sprite.getGlobalBounds().contains(clickLocation))
	{
		ctrl.newGame();
		return true;
	}

	return false;
}
//------------------------------------------------------------