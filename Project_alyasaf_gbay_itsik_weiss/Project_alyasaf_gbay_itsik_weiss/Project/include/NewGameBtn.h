#pragma once

#include "Button.h"

class NewGameBtn : public Button
{
public:
	NewGameBtn(const sf::Texture& texture, const sf::Vector2f& position);
	bool handleClick(const sf::Vector2f& clickLocation, Controller& ctrl) const override;
};