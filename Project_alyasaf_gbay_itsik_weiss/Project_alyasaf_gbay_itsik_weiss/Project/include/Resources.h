#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Resources
{
public:
	Resources()
	{
		m_marioTxtr.loadFromFile("mario.png");
		m_enemysTxtr.loadFromFile("Enemys.png");
		m_wallTxtr.loadFromFile("wall.jpg");
		m_coinsTxtr.loadFromFile("coin.png");
		m_giftTxtr.loadFromFile("gift.png");
		m_menuBackgroundTxtr.loadFromFile("menuBackground.png");
		m_spritesheetTxtr.loadFromFile("spritesheet.png");
		m_GameCompletedTxtr.loadFromFile("game_completed.png");

		m_menuBuffer.loadFromFile("musicloop.wav");
		m_shotBuffer.loadFromFile("killEnemy.wav");


		
		m_clockTxtr.loadFromFile("clock.png");

		m_backroundTxtr.loadFromFile("Game_Background1.png");
		m_newGameBtnTxtr.loadFromFile("btn_play.png");
		m_exitBtnTxtr.loadFromFile("btn_exit.png");
		m_helpBtnTxtr.loadFromFile("btn_help.png");
		m_helpTxtr.loadFromFile("help.png");
		
		m_font.loadFromFile("Alger.ttf");
	};
	sf::Texture m_marioTxtr;
	sf::Texture m_enemysTxtr;
	sf::Texture m_wallTxtr;
	sf::Texture m_coinsTxtr; 
	sf::Texture m_giftTxtr;
	sf::Texture m_menuBackgroundTxtr; 
	sf::Texture m_exitBtnTxtr; 
	sf::Texture m_helpTxtr; 
	sf::Texture m_helpBtnTxtr;
	sf::Texture m_spritesheetTxtr;
	sf::Texture m_GameCompletedTxtr;
	sf::Texture m_clockTxtr;
	sf::Texture m_newGameBtnTxtr;
	sf::Texture m_backroundTxtr;
	sf::Font m_font;
	sf::SoundBuffer m_menuBuffer;
	sf::SoundBuffer m_shotBuffer;

};
