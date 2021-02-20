#include "HelpBtn.h"

HelpBtn::HelpBtn(const sf::Texture& texture, const sf::Vector2f& position)
	:Button(texture, position)
{
	m_sprite.setScale(0.99, 0.99);
	m_spriteBackground.setTexture(resources.m_helpTxtr);
	m_spriteBackground.setScale(1.6, 1.6);
	m_spriteBackground.setScale(1.6, 1.6);
}

bool HelpBtn::handleClick(const sf::Vector2f& clickLocation, Controller& ctrl) const
{
	
	sf::RenderWindow m_window(sf::VideoMode::getDesktopMode(), "help");
	sf::Event event;
	if (m_sprite.getGlobalBounds().contains(clickLocation))
	{
		while (m_window.isOpen())
		{
			m_window.clear();
			m_window.draw(m_spriteBackground);
			m_window.display();
			while (m_window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				m_window.close();
			}
			
		}
		return false;
		
	}

	return false;
}

