#include "Menu.h"

#include "HelpBtn.h"
#include "ExitBtn.h"
#include "NewGameBtn.h"
#include "Controller.h"


//*****************************************************************************
Menu::Menu(const Resources& resources, const string& msg)
	:m_sprite(resources.m_menuBackgroundTxtr)//, m_text(msg, resources.m_font, MENU_MSG_CHAR_SIZE)
	//, //m_scoreText(EMPTY_STRING, resources.m_font, SCORE_TEXT_CHAR_SIZE)
{
	//backgroud
	m_sprite.setScale(1.59, 1.9);

	//message
	//m_text.setFillColor(sf::Color::Black);
	//sf::FloatRect textRect = m_text.getLocalBounds();
	//m_text.setOrigin((textRect.width - WINDOW_WIDTH) / 2 + textRect.left,
	//				 (textRect.height - MENU_MSG_DEFAULT_ORIGIN_HEIGHT) / 2 + textRect.top);

	m_scoreText.setFillColor(sf::Color::Black);

	//init buttons
	m_buttons.push_back(std::make_unique<NewGameBtn>(
		resources.m_newGameBtnTxtr, 
		sf::Vector2f((m_sprite.getPosition().x / 2)+210, NEW_BTN_POS_HEIGH)
		));

	m_buttons.push_back(std::make_unique<ExitBtn>(
		resources.m_exitBtnTxtr,
		sf::Vector2f((m_sprite.getPosition().x / 2) + 250, EXIT_BTN_POS_HEIGH-20)
		));

	m_buttons.push_back(std::make_unique<HelpBtn>(
		resources.m_helpBtnTxtr,
		sf::Vector2f((m_sprite.getPosition().x / 2) + 450, NEW_BTN_POS_HEIGH+40)
		));

	m_sound.setBuffer(resorce.m_menuBuffer);
	m_sound.setLoop(true);
}
//*****************************************************************************
void Menu::show(Controller& ctrl, sf::RenderWindow& window) 
{
	bool actionSelected = false;
	ctrl.setMenuView();
	ctrl.initLiveAndScore();
	m_sound.play();

	while (window.isOpen() && actionSelected == false)
	{
		window.clear();
		drawAll(window);
		window.display();

		if (auto event = sf::Event{}; window.waitEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
					window.close();
					break;


			case sf::Event::MouseButtonReleased:
			{
				auto clickLocation = window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
				if (handleClick(clickLocation, ctrl)) {
					actionSelected = true;
					m_sound.stop();
				}
			}
			break;

			/*
			case sf::Event::MouseMoved:
			case sf::Event::MouseLeft:
				auto moveLocation = m_window.mapPixelToCoords({ event.mouseMove.x, event.mouseMove.y });
				handleMove(moveLocation);
				break;
				*/
			}
		}
	}
}
//------------------------------------------------------------
void Menu::drawAll(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
	//window.draw(m_text);
	window.draw(m_scoreText);

	for (auto& btn : m_buttons)
		btn->draw(window);
}
////------------------------------------------------------------
//void Menu::setMessage(const string& message, unsigned int score)
//{
//	m_text.setString(message);
//
//	sf::FloatRect textRect = m_text.getLocalBounds();
//	m_text.setOrigin((textRect.width - WINDOW_WIDTH) / 2 + textRect.left,
//		(textRect.height - MENU_MSG_ORIGIN_HEIGHT) / 2 + textRect.top);
//
//	m_scoreText.setString(SCORE_MSG + to_string(score));
//	textRect = m_scoreText.getLocalBounds();
//	m_scoreText.setOrigin((textRect.width - WINDOW_WIDTH) / 2 + textRect.left,
//		(textRect.height - SCORE_MSG_ORIGIN_HEIGHT) / 2 + textRect.top);
//}
//------------------------------------------------------------
bool Menu::handleClick(const sf::Vector2f& clickLocation, Controller& ctrl) const
{
	for (auto& btn : m_buttons)
		if(btn->handleClick(clickLocation, ctrl))
			return true;

	return false;
}
//------------------------------------------------------------