#pragma once

#include "macros.h"

#include "Player.h"
#include "PlayerShot.h"

#include "Monster.h"
#include "Wall.h"
#include "Food.h"
#include "Gift.h"


#include <fstream>
using std::ifstream;


class Level
{
public:
	Level(sf::RenderWindow& window, Resources& resources, bool next = true);
	void play(sf::RenderWindow& window, Resources& resources);
	bool isWin();
	void initLiveAndScore();
	void initNumOfLevel();
	bool isReaden();
	void setNumOfLevel();
protected:

	static int m_numOfLevel;
	sf::Clock m_gameClock;//the clock used to calculate how much the dynamic object has to move

	int m_height, m_width;//height and width of the board in the current level

private:
	unsigned int m_monsterCount;
	sf::Sprite m_sprite;
	sf::View m_view;
	std::vector<std::shared_ptr<MovObject>>m_moves;
	std::vector<std::shared_ptr<StaticObject>>m_statics;
	std::unique_ptr<Player> m_player;
	sf::Sound m_shotShond;
	sf::Text m_textClock;
	sf::CircleShape m_clockCircle;
	sf::Sprite m_clock;
	sf::Text m_texPower;
	
	void drawPower(sf::RenderWindow& window) ;
	bool m_readen;

	void readFile(sf::RenderWindow& window, ifstream&, Resources&);//read the text file of the level and init the objects accordingly
	
	void createObject(char type, sf::Vector2f position, Resources& resources);
	void moveAll(float deltaTime);
	void update(Resources& resources);
	void checkCollision();
	void createNewObjects(Resources& resources);
	void drow(sf::RenderWindow& window);
	void drawAll(sf::RenderWindow& window);
	void drawClock(sf::RenderWindow& window);
};
