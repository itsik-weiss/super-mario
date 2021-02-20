#pragma once

#include "Button.h"

class HelpBtn:public Button
{
public:
	HelpBtn(const sf::Texture& texture, const sf::Vector2f& position);
	bool handleClick(const sf::Vector2f& clickLocation, Controller& ctrl) const override;
	


private:
	sf::RenderWindow m_window;
	Resources resources;
	sf::Sprite m_spriteBackground;
};

