#include "CollisionHandling.h"


#include <functional>
#include <iostream>
#include <map>
#include <typeindex>

#include "Food.h"
#include "Gift.h"
#include "Monster.h"
#include "Player.h"
#include "PlayerShot.h"
#include "Wall.h"
#include "Thorn.h"
#include "WinPoint.h"

namespace { // anonymous namespace — the standard way to make function "static"

// primary collision-processing functions
	void PlayerWall(Object& player0, Object& wall0)
	{
		Player& player = static_cast<Player&>(player0);
		player.CollisionWithWall(wall0);
	}

	void PlayerGift(Object& player0, Object& gift0)
	{
		Player& player = static_cast<Player&>(player0);
		Gift& gift = static_cast<Gift&>(gift0);

		player.CollisionWithGift();
		gift.CollisionWithPlayer();
	}
	void PlayerFood(Object& player0, Object& food0)
	{
		Player& player = static_cast<Player&>(player0);
		Food& food = static_cast<Food&>(food0);

		player.CollisionWithFood();
		food.CollisionWithPlayer();
	}

	void PlayerMonster(Object& player0, Object& monster0)
	{
		Player& player = static_cast<Player&>(player0);
		Monster& monster = static_cast<Monster&>(monster0);

		if (player.CollisionWithMonster(monster))
			monster.CollisionWithPlayer();
	}

	void PlayerThorn(Object& player0, Object& thorn0)
	{
		Player& player = static_cast<Player&>(player0);
		player.CollisionWithThorn();
	}
	void PlayerWinPoint(Object& player0, Object& winPoint0)
	{
		Player& player = static_cast<Player&>(player0);
		player.CollisionWithWinPoint();
	}

	void MonsterWall(Object& monster0, Object& wall0)
	{
		Monster& monster = static_cast<Monster&>(monster0);
		monster.CollisionWithWall();
	}

	void MonsterPlayerShot(Object& monster0, Object& playerShot0)
	{
		PlayerShot& playerShot = static_cast<PlayerShot&>(playerShot0);
		Monster& monster = static_cast<Monster&>(monster0);

		playerShot.CollisionWithMonster();
		monster.CollisionWithPlayerShot();
	}

	void PlayerShotWall(Object& playerShot0, Object& wall0)
	{
		PlayerShot& playerShot = static_cast<PlayerShot&>(playerShot0);
		playerShot.CollisionWithWall();
	}


	//...



	void WallPlayer(Object& wall, Object& player)
	{
		PlayerWall(player, wall);
	}

	void GiftPlayer(Object& gift, Object& player)
	{
		PlayerGift(gift, player);
	}

	void FoodPlayer(Object& food, Object& player)
	{
		PlayerFood(player, food);
	}

	void MonsterPlayer(Object& monster, Object& player)
	{
		PlayerMonster(player, monster);
	}

	void ThornPlayer(Object& thorn, Object& player)
	{
		PlayerThorn(player, thorn);
	}
	void WinPointPlayer(Object& winPoint, Object& player)
	{
		PlayerWinPoint(player, winPoint);
	}

	void WallMonster(Object& wall, Object& monster)
	{
		MonsterWall(monster, wall);
	}
	void PlayerShotMonster(Object& playerShot, Object& monster)
	{
		MonsterPlayerShot(monster, playerShot);
	}

	void WallPlayerShot(Object& wall, Object& playerShot)
	{
		PlayerShotWall(playerShot, wall);
	}

	//...

	using HitFunctionPtr = std::function<void(Object&, Object&)>;
	using Key = std::pair<std::type_index, std::type_index>;
	using HitMap = std::map<Key, HitFunctionPtr>;

	HitMap initializeCollisionMap()
	{
		HitMap phm;
		phm[Key(typeid(Player), typeid(Gift))] = &PlayerGift;
		phm[Key(typeid(Gift), typeid(Player))] = &GiftPlayer;
		phm[Key(typeid(Player), typeid(Wall))] = &PlayerWall;
		phm[Key(typeid(Wall), typeid(Player))] = &WallPlayer;
		phm[Key(typeid(Player), typeid(Food))] = &PlayerFood;
		phm[Key(typeid(Food), typeid(Player))] = &FoodPlayer;
		phm[Key(typeid(Player), typeid(Monster))] = &PlayerMonster;
		phm[Key(typeid(Monster), typeid(Player))] = &MonsterPlayer;
		phm[Key(typeid(Player), typeid(Thorn))] = &PlayerThorn;
		phm[Key(typeid(Thorn), typeid(Player))] = &ThornPlayer;
		phm[Key(typeid(Player), typeid(WinPoint))] = &PlayerWinPoint;
		phm[Key(typeid(WinPoint), typeid(Player))] = &WinPointPlayer;

		phm[Key(typeid(Monster), typeid(PlayerShot))] = &MonsterPlayerShot;
		phm[Key(typeid(PlayerShot), typeid(Monster))] = &PlayerShotMonster;
		phm[Key(typeid(Monster), typeid(Wall))] = &MonsterWall;
		phm[Key(typeid(Wall), typeid(Monster))] = &WallMonster;

		phm[Key(typeid(PlayerShot), typeid(Wall))] = &PlayerShotWall;
		phm[Key(typeid(Wall), typeid(PlayerShot))] = &WallPlayerShot;
		//...
		return phm;
	}

	HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2)
	{
		static HitMap collisionMap = initializeCollisionMap();
		const auto mapEntry = collisionMap.find(std::make_pair(class1, class2));
		if (mapEntry == collisionMap.end())
		{
			return nullptr;
		}
		return mapEntry->second;
	}

} // end namespace

void processCollision(Object& object1, Object& object2)
{
	const auto collisionHandler = lookup(typeid(object1), typeid(object2));
	if (!collisionHandler)
	{
		return;
		// throw UnknownCollision(object1, object2);
	}
	collisionHandler(object1, object2);
}

