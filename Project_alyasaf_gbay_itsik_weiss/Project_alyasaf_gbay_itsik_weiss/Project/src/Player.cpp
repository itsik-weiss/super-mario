#include "Player.h"
#include "Level.h"

//#include <math.h>
//unsigned int Player::m_live = INITIAL_LIVES;
//unsigned int Player::m_score = INITIAL_SCORE;

Player::Player(sf::Texture* texture, sf::Vector2f position, sf::FloatRect inrect, float LRspeed , float UDspeed )
	:MovObject(texture, position, inrect, LRspeed, UDspeed,2) , m_inAir(true), m_loadingShot(false), m_shot(false),
	m_win(false),m_currScore(0),m_live(3),m_direction(0), m_rectSourceSprite(inrect)
{
	m_timeProtected.restart();
}

void Player::move(float deltaTime)
{
	if (m_inAir) {
	
		m_UDspeed += GRAVITY* deltaTime;
	}
	else
	{
		m_UDspeed = 0;
	}
	MovObject::move(deltaTime);
}



void Player::updat(const sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed)
		switch (event.key.code)
		{
		case sf::Keyboard::Right:
			m_LRspeed = PLAYER_SPEED;
			m_direction = 1;
			m_rectSourceSprite = { 205, 111, 17,33 };
			m_sprite.setTextureRect(m_rectSourceSprite);
			break;
		case sf::Keyboard::Left:
			m_LRspeed = -PLAYER_SPEED;
			m_direction = -1;
			m_rectSourceSprite = { 168, 116, 17,33 };
			m_sprite.setTextureRect(m_rectSourceSprite);
			break;
		case sf::Keyboard::Up:
 			if (!m_inAir)
			{
				m_inAir = true;
				m_UDspeed = PLAYER_JUMP_SPEED;
			}
			m_rectSourceSprite = { 208, 194, 17,33 };
			m_sprite.setTextureRect(m_rectSourceSprite);
			break;

		case sf::Keyboard::Down:
			m_direction = 0;
			break;
		case sf::Keyboard::Space:
			if(m_power>=3)
				m_loadingShot = true;
			break;
		}
	else if(event.type == sf::Event::KeyReleased)
		switch (event.key.code)
		{
		case sf::Keyboard::Right:
			if (m_direction == 1)
				m_LRspeed = 0;
			break;
		case sf::Keyboard::Left:
			if (m_direction == -1)
				m_LRspeed = 0;
			break;
		case sf::Keyboard::Space:
			if (m_loadingShot) {
					m_shot = true;
				m_loadingShot = false;
			}
			break;
		}
}

void Player::updateInAir(std::vector<std::shared_ptr<StaticObject>> &staticVec)
{
	m_sprite.move(0, 3.f);
	if(m_UDspeed>=0)
		for (int i = 0; i < staticVec.size(); i++)
			if (typeid(*staticVec[i]) == typeid(Wall)
				&& checkCollision(staticVec[i]->getGlobalBounds()))
			{
				m_sprite.move(0, -3.f);//back
				m_inAir = false;
				return;
			}
	m_sprite.move(0, -3.f);//back
	m_inAir = true;
}

bool Player::get_isShot()
{
	if (m_shot) {
		m_shot = false;
		return true;
	}
	return false;
}

int Player::get_time()
{
	return PLAYER_TIME - m_timePast.getElapsedTime().asSeconds();
}

bool Player::isTimeOver()
{
	if (m_timePast.getElapsedTime().asSeconds() < PLAYER_TIME)
		return false;
	//if(m_power>0)
	//	m_power--;
	m_power = 0;
	return true;
}

bool Player::isWin()
{
	return m_win;
}

bool Player::isprotected()
{
	return m_timePast.getElapsedTime().asSeconds() < PROTECTED_TIME;
}

int Player::getDirection()
{
	return m_direction;
}

void Player::CollisionWithWall(Object& wall)
{
	moveBack();

	if (m_UDspeed < 0)//go up
		m_UDspeed = 0;

	//if Collision with graond
	if (m_sprite.getGlobalBounds().top + m_sprite.getGlobalBounds().height < wall.getGlobalBounds().top
		&& m_UDspeed > 0) {
		m_inAir = false;
		m_UDspeed = 0;

	}
	//if Collision from right or left
	else if (m_sprite.getGlobalBounds().top < wall.getGlobalBounds().top + wall.getGlobalBounds().height)
	{
		m_LRspeed = 0;
	}
}

bool Player::CollisionWithMonster(Object& monster)
{
	moveBack();
	bool kill = false;

	 //if jump on it
	if (m_sprite.getGlobalBounds().top + m_sprite.getGlobalBounds().height < monster.getGlobalBounds().top)
	{
		m_UDspeed = PLAYER_JUMP_SPEED;
		m_inAir = true;
		kill = true;
	}
	else if(m_timeProtected.getElapsedTime().asSeconds() >PROTECTED_TIME)//no Protected
	{
		if(m_power>0)
			m_power--;
		m_timeProtected.restart();
	}
	m_sprite.move(m_moved);
	return kill;
}

void Player::CollisionWithGift()
{
	if (m_power < 3)
		m_power++;
	m_currScore += 30;
}

void Player::CollisionWithFood()
{
	m_currScore += 30;
	m_timePast.restart();
}

bool Player::CollisionWithGround(float groundYPos)
{
	return m_sprite.getPosition().y + 1.f >= groundYPos;
}
int Player::getPoewr()
{
	return m_power;
}
void Player::CollisionWithWinPoint()
{
	m_win = true;
}
void Player::CollisionWithThorn()
{
	if (m_timeProtected.getElapsedTime().asSeconds() > PROTECTED_TIME)//no Protected
	{
		if (m_power > 0)
			m_power--;
		m_timeProtected.restart();
	}
}

void Player::initLiveAndScore()
{
	m_live = INITIAL_LIVES;
	m_score = INITIAL_SCORE;
}
