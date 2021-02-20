#include "CreditBtn.h"

CreditBtn::CreditBtn(const sf::Texture& texture, const sf::Vector2f& position, int score)
	:Button(texture, position), m_score(score)
{
}
