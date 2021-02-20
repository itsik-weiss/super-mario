#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

//#include "Player.h"
//#include "Monster.h"
//#include "Wall.h"
#include "Level.h"
#include "Macros.h"
#include "Menu.h"

class Controller
{	
public:
	Controller();
	void run();
	void setMenuView();
	void initLiveAndScore();
	void newGame();
	void exitGame();

protected:
	Resources m_resources;//images;fonts;text files
	//std::unique_ptr<Level> m_level;//keep the current level of the game
	sf::RenderWindow m_window;
	std::unique_ptr<Level> m_level;
	sf::View m_view;

private:

	void initLevel(bool moveToNextLevel);
	Menu m_menu;
	void windowWin();
	sf::Sprite m_spriteWin;
	Resources resource;
};