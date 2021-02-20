#pragma once
#include "Level.h"
#include "CollisionHandling.h"
#include "Thorn.h"
#include "WinPoint.h"
#include <sstream>
#include <experimental/vector>

using std::istringstream;

int Level::m_numOfLevel = 0;


Level::Level(sf::RenderWindow& window, Resources& resources, bool next)
	:m_sprite(resources.m_backroundTxtr), m_clockCircle(160/3)
	, m_clock(resources.m_clockTxtr), m_textClock("time ",resources.m_font,30)
	, m_view(sf::Vector2f(window.getPosition()),sf::Vector2f( window.getSize())), m_monsterCount(0), m_readen(true)
{
	if (next)
	m_numOfLevel++;
	string fileName = LEVEL_FILE_NAME + to_string(m_numOfLevel) + TXT_SUFFIX;

	ifstream iFile;
	iFile.open(fileName);

	if (iFile)

		readFile(window, iFile, resources);
	else
		m_readen = false;


	iFile.close();

	
	

	if (m_readen) {

	
  	m_view.zoom(0.4);


	m_sprite.setScale((m_view.getSize().x / m_sprite.getTexture()->getSize().x),
					   m_view.getSize().y / m_sprite.getTexture()->getSize().y);

	//srand(time(NULL));
	m_shotShond.setBuffer(resources.m_shotBuffer);
	}
	m_clock.scale(0.3, 0.3);
	m_clockCircle.scale(0.35, 0.35);
	m_texPower.setFont(resources.m_font);
	//m_textClock.scale(0.3, 0.3);
}

void Level::play(sf::RenderWindow& window, Resources& resources)
{
	sf::Event event;

	//init clocks
	m_gameClock.restart();

	while (window.isOpen())
	{
		if (m_player->getPower() == 0 || m_player->isWin()  || m_player->isTimeOver()|| m_monsterCount==0)
			break;

		moveAll(m_gameClock.restart().asSeconds());

		while (window.pollEvent(event)) {
			// Window closed or escape key pressed: exit
			if (event.type == sf::Event::Closed)
			{
				window.close();
				break;
			}
			m_player->updat(event);
		}

		update(resources);

		drow(window);
	}
}

bool Level::isWin()
{
	return m_player->getPower() > 0;
}



void Level::readFile(sf::RenderWindow& window, ifstream& iFile, Resources& resources)
{
	string str;
	getline(iFile, str);
	auto ss = istringstream(str);


	ss >> m_width >> m_height;

	for (int c = 0; c < m_height; c++)
	{
		getline(iFile, str);

		for (int r = 0; r < str.size(); r++)
			if (str[r] != SPACE)
				createObject(str[r],  sf::Vector2f( r, c)* CUBE_SIZE , resources);
	}

	window.setView(m_view);

}

void Level::createObject(char type, sf::Vector2f position, Resources& resources)
{
	switch (type)
	{

	case WALL:
		m_statics.push_back(std::make_shared<Wall>(&resources.m_wallTxtr,
			position, sf::FloatRect({ 0 ,0 , CUBE_SIZE ,CUBE_SIZE })));
		break;
	case FOOD:
		m_statics.push_back(std::make_shared<Food>(&resources.m_coinsTxtr,
			position, sf::FloatRect({ 0 ,0 , 192 / 6 , 32 })));
		break;
	case THORN:
		m_statics.push_back(std::make_shared<Thorn>(&resources.m_spritesheetTxtr,
			position, sf::FloatRect({ 736 ,144 , 17,16 })));
		break;
	case GIFT:
		m_statics.push_back(std::make_shared<Gift>(&resources.m_giftTxtr,
			position, sf::FloatRect({ 0 ,0 , 215 ,234 })));
		break;
	case WIN_POINT:
		m_statics.push_back(std::make_shared<WinPoint>(&resources.m_spritesheetTxtr,
			position, sf::FloatRect({ 706 ,35 , 29 ,29 })));
		break;
	case MONSTER:
		m_moves.push_back(std::make_shared<Monster>(&resources.m_enemysTxtr,
			position, sf::FloatRect({ 5 * 261 / 9 ,4 * 436 / 15 ,CUBE_SIZE ,CUBE_SIZE }),50, 0 ));
		m_monsterCount++;
		break;
	case PLAYER:
		m_player = std::make_unique<Player>(&resources.m_marioTxtr,
			position, sf::FloatRect({ 0,10, CUBE_SIZE_MARIO_X ,CUBE_SIZE_MARIO_Y }));
		break;
	case PLAYER_SHOT:
		m_moves.push_back(std::make_shared<PlayerShot>(&resources.m_enemysTxtr,
			position, sf::FloatRect({ 0,0,CUBE_SIZE,CUBE_SIZE }), m_player->getDirection() *PLAYER_SHOT_SPEED , (m_player->getDirection()!=0 )? 200: -PLAYER_SHOT_SPEED));
	}
}

void Level::moveAll(float deltaTime)
{
	for (int i = 0; i < m_moves.size(); i++)
		m_moves[i]->move(deltaTime);
	m_player->move(deltaTime);
}

void Level::update(Resources& resources)
{
	checkCollision(); 

	m_player->updateInAir(m_statics);


	createNewObjects(resources);
	
	//remove deads
	std::experimental::erase_if(m_moves,	[](const auto& object) { return object->getPower() == 0; });
	std::experimental::erase_if(m_statics,	[](const auto& object) { return object->getPower() == 0; });
}

void Level::checkCollision()
{
	for (int i = 0; i < m_statics.size(); i++)
	{
		if (m_player->checkCollision(m_statics[i]->getGlobalBounds()))
			processCollision(*m_player, *m_statics[i]);

		for (int j = 0; j < m_moves.size(); j++)
			if (m_statics[i]->checkCollision(m_moves[j]->getGlobalBounds()))
				processCollision(*m_statics[i], *m_moves[j]);
	}

	for (int i = 0; i < m_moves.size(); i++) {

		if (m_player->checkCollision(m_moves[i]->getGlobalBounds()))
			processCollision(*m_player, *m_moves[i]);

		for (int j = i + 1; j < m_moves.size(); j++)
			if (m_moves[i]->checkCollision(m_moves[j]->getGlobalBounds()))
				processCollision(*m_moves[i], *m_moves[j]);
	}
}

void Level::createNewObjects(Resources& resources)////////////////////////////
{
	if (m_player->get_isShot())
	{ 
		m_shotShond.play();//////////////////////////////////////////////
		createObject(PLAYER_SHOT, m_player->getPosition(), resources);
	}
	for (int i = 0; i < m_moves.size(); i++)
		if (m_moves[i]->getPower() == 0
			&& typeid(*m_moves[i]) == typeid(Monster)) 
		{
			createObject(FOOD, m_moves[i]->getPosition(), resources);
			m_monsterCount--;
		}

}

void Level::drow(sf::RenderWindow& window)
{
	window.clear();

	m_view.setCenter(m_player->getPosition());
	m_sprite.setPosition(m_view.getCenter() - sf::Vector2f(m_view.getSize().x / 2, m_view.getSize().y / 2));
	window.setView(m_view);

	drawAll(window);


	window.display();
}

void Level::drawAll(sf::RenderWindow& window)
{
	window.draw(m_sprite);
	
	m_player->draw(window);

	for (int i = 0; i < m_moves.size(); i++)
		m_moves[i]->draw(window);
	
	for (int i = 0; i < m_statics.size(); i++)
		m_statics[i]->draw(window);

	drawClock(window);
	drawPower(window);
}

void Level::drawClock(sf::RenderWindow& window)
{
	if (m_player->get_time()>=0)
	{
		m_textClock.setString(
			(m_player->get_time() >= 10 ? EMPTY_STRING : "0") + to_string(m_player->get_time()));	
	}

	m_clock.setPosition(m_view.getCenter().x, m_view.getCenter().y- m_view.getSize().y / 2);
	m_clockCircle.setPosition(m_view.getCenter().x+9, m_view.getCenter().y - m_view.getSize().y / 2+12);
	//m_textClock.setPosition(m_view.getCenter().x, m_view.getCenter().y);// - m_view.getSize().y / 2 +50);
	m_textClock.setPosition(m_clockCircle.getPosition());

	m_textClock.setColor(sf::Color::Black);

	if (m_player->get_time() <= 10)
		m_clockCircle.setFillColor(RED);
	else
		m_clockCircle.setFillColor(GREEN);

	window.draw(m_clock);
	window.draw(m_clockCircle);
	window.draw(m_textClock);

}
//===============================================
void Level::drawPower(sf::RenderWindow& window)
{
	std::string strPower="power: ";
	m_texPower.setColor(sf::Color::Black);
	m_texPower.setString(strPower + to_string(m_player->getPoewr()));
	m_texPower.setPosition(m_view.getCenter().x - 380, m_view.getCenter().y - 216);
	window.draw(m_texPower);
}
//==============================================
void Level::initLiveAndScore()
{
	m_player->initLiveAndScore();
}
//================================================
void Level::initNumOfLevel()
{
	m_numOfLevel = 0;
}
//===================================================
bool Level::isReaden()
{
	return m_readen;
}
//==============================================
void Level::setNumOfLevel()
{
	m_numOfLevel = 0;
}
//------------------------------------------------------------
