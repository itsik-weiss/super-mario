#pragma once

#include "Button.h"

class ExitBtn : public Button
{
public:
	ExitBtn(const sf::Texture& texture, const sf::Vector2f& position);
	bool handleClick(const sf::Vector2f& clickLocation, Controller& ctrl) const override;
};