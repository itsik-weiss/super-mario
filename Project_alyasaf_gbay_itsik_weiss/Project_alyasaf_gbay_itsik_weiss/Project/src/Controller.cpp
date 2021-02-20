#include "Controller.h"
#include "Level.h"
//#include "Macros.h"



Controller::Controller():m_window(sf::VideoMode::getDesktopMode(),"sf::View demo"),
	m_menu(m_resources, MARIO_MSG)
{
	m_spriteWin.setTexture(resource.m_GameCompletedTxtr);
	m_spriteWin.setScale(0.5, 0.5);
}

void Controller::run()
{
	while (m_window.isOpen())
	{
		m_menu.show(*this, m_window);
		//initLevel(true);
		while (m_window.isOpen())
		{
			m_level->play(m_window,m_resources);

				initLevel(m_level->isWin());
				if (!m_level->isReaden()) {
					m_level->setNumOfLevel();
				windowWin();
				break;
			}
			
		}

	}
}
//======================================================================
void Controller::initLevel(bool moveToNextLevel)
{
	m_level = std::make_unique<Level>(m_window, m_resources, moveToNextLevel);
}
//======================================================================
void Controller::windowWin()
{
	sf::RenderWindow window(sf::VideoMode(600,600), "win");
	sf::Event event;
	
		while (window.isOpen())
		{
			window.clear(sf::Color::White);
			window.draw(m_spriteWin);
			window.display();
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

		}
}
//=============================================
void Controller::setMenuView()
{
	m_window.setView(m_view);
}
//==============================================
void Controller::initLiveAndScore()
{
	if (m_level&& m_level->isReaden())
		m_level->initLiveAndScore();
}

//==================================
void Controller::newGame()
{
	m_level->initNumOfLevel();
	initLevel(true);//new game
}
//========================================================
void Controller::exitGame()
{
	m_window.close();
}
//===============================================================