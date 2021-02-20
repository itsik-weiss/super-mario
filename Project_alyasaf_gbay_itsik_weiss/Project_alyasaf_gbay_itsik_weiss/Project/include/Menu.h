#pragma once
#include <SFML/Audio.hpp>
#include "macros.h"
#include "Button.h"
#include "Resources.h"

class Controller;//Forward Decleration

class Menu
{
public:
	Menu(const Resources& resources, const string& message);
	//display the menu
	void show(Controller& ctrl, sf::RenderWindow& window) ;
	void drawAll(sf::RenderWindow& window) const;

	//set the main message that is displayed in the menu
	//void setMessage(const string& message, unsigned int score);
	bool handleClick(const sf::Vector2f& clickLocation, Controller& ctrl) const;

protected:
	vector<std::unique_ptr<Button>> m_buttons;
	sf::Sprite m_sprite;//for menu background
	sf::Text m_text;//for displaying the main meessage on the menu
	sf::Text m_scoreText;//for displaying the score that has been accumulated in the game
	sf::Sound m_sound;
	Resources resorce;
};