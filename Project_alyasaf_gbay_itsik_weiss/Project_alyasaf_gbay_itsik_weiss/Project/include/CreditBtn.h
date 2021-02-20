#pragma once
#include "Button.h"

class CreditBtn : public Button
{
public:
	CreditBtn(const sf::Texture& texture, const sf::Vector2f& position, int score);
	//~CreditBtn();

private:
	int m_score;
	sf::RenderWindow m_window;
};


