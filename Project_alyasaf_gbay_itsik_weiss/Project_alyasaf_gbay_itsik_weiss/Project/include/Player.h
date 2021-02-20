#pragma once
#include "SFML/Graphics.hpp"
#include "MovObject.h"
#include "Object.h"
class StaticObject;
class Wall;

class Player :public MovObject {
public:
	Player(sf::Texture* texture, sf::Vector2f position, sf::FloatRect inrect, float LRspeed = 0, float UDspeed = 0);
	void move(float deltaTime)override;
	void updat(const sf::Event& event);
	void updateInAir(std::vector<std::shared_ptr<StaticObject>> &staticVec);
	bool get_isShot();
	int get_time();

	bool isTimeOver();
	bool isWin();

	bool isprotected();
	int getDirection();
	void initLiveAndScore();


	void CollisionWithWall(Object& wall);	
	bool CollisionWithMonster(Object& monster);//rturn true if kill the monster
	void CollisionWithGift();
	void CollisionWithFood();
	void CollisionWithThorn();
	void CollisionWithWinPoint();
	bool CollisionWithGround(float groundYPos);

	//....
	int getPoewr();

protected:
	unsigned int m_live;
	//static unsigned int m_live;
	unsigned int m_currScore;//the score accumulated in the current level
	//static unsigned int m_score;//the whole score accumulated in the previous levels

	sf::Clock m_timePast;//the clock of the time past from the beginning of the current Level
	sf::Clock m_timeProtected;//the clock of the time past from the beginning of the current Level

private:	
	sf::Clock m_clock;

	bool m_inAir;
	bool m_loadingShot;
	bool m_shot;
	bool m_win;
	int m_direction;
	int m_score;
	sf::IntRect m_rectSourceSprite;
};