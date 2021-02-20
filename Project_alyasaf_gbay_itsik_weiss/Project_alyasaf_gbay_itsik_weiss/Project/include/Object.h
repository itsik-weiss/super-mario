#pragma once
#include "SFML/Graphics.hpp"
#include "Macros.h"

class Object {
public:
	Object(sf::Texture* texture, sf::Vector2f position, sf::FloatRect inrect,int power=1);

	void draw(sf::RenderWindow& window) const;
	sf::Vector2f getPosition();
	unsigned getPower();

	sf::FloatRect getGlobalBounds() const;//..of the object sprite
	bool checkCollision(const sf::FloatRect& floatRect) const;

	virtual ~Object() = 0 {};
protected:
	sf::Sprite m_sprite;
	unsigned int m_power;
private:
};