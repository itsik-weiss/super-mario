#pragma once

#include "macros.h"

class Controller;

class Button
{
public:
	Button(const sf::Texture& texture, const sf::Vector2f& position);
	void draw(sf::RenderWindow& window) const;
	virtual bool handleClick(const sf::Vector2f& clickLocation, Controller& ctrl) const = 0;
	sf::FloatRect getGlobalBounds() const;

protected:
	sf::Sprite m_sprite;
};