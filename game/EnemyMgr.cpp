#include <cstdlib>
#include <ctime>
using namespace std;
#include "EnemyMgr.h"


// Constructor
// parameters: 
//   img: the texture to use for the enemy sprite
// return type: none
EnemyMgr::EnemyMgr(Texture &img)
{
	enemy.setTexture(img);
}

// draw: draws all of the enemies onto the window
// parameters: 
//   win: the window to draw to
// return type: void
void EnemyMgr::draw(RenderWindow &win)
{
	list<Enemy>::iterator it;

	for (it = enemyList.begin(); it != enemyList.end(); it++)
	{
		it->draw(win);
	}
}

// addEnemy: adds an enemy to the list
// parameters: 
//   pos: the position to spawn the enemy at
// return type: void
void EnemyMgr::addEnemy(Vector2f pos)
{
	enemyList.push_back(Enemy(pos, enemy));
}

// dropBomb: make a random enemy drop a bomb
// parameters: 
//   bombList: the list to add the bomb to
// return type: void
void EnemyMgr::dropBomb(BombMgr &bombList)
{
	if (enemyList.size() > 0)
	{
		int target = (rand() % (enemyList.size()));

		list<Enemy>::iterator it;
		it = enemyList.begin();
		advance(it, target);
		it->dropBomb(bombList);
	}
}

// descend: moves all of the enemies down one increment
// parameters: none
// return type: void
void EnemyMgr::descendAll()
{
	list<Enemy>::iterator it;

	for (it = enemyList.begin(); it != enemyList.end(); it++)
	{
		it->descend();
	}
}

// reset: move all of the enemies back to the top of the screen
// parameters: none
// return type: void
void EnemyMgr::resetPositions()
{
	list<Enemy>::iterator it;

	for (it = enemyList.begin(); it != enemyList.end(); it++)
	{
		it->reset();
	}
}

// clearList: removes all enemies from the list
// parameters: none
// return type: void
void EnemyMgr::clearList()
{
	list<Enemy>::iterator it;

	for (it = enemyList.begin(); it != enemyList.end(); )
	{
		it = enemyList.erase(it);
	}
}

// checkHits: check if any enemies were hit by a missile
// parameters: 
//   missileList: the list to check missiles from
// return type: bool
bool EnemyMgr::checkHits(MissileMgr &missileList)
{
	list<Enemy>::iterator it;
	bool isHit = false;

	for (it = enemyList.begin(); it != enemyList.end(); )
	{
		if (it->checkHit(missileList))
		{
			it = enemyList.erase(it);
			isHit = true;
		}
		else
		{
			it++;
		}
	}
	return isHit;
}

// checkPositions: check if any enemies are at the position of the ship
// parameters: 
//   ship: the ship to check the position of
// return type: bool
bool EnemyMgr::checkPosition(Ship &ship)
{
	list<Enemy>::iterator it;
	bool isAtBottom = false;

	for (it = enemyList.begin(); it != enemyList.end() && !isAtBottom; it++)
	{
		if (it->getPosition().y >= ship.getPosition().y)
		{
			isAtBottom = true;
		}
	}
	return isAtBottom;
}

// getEnemyCount: get the number of enemies in the list
// parameters: none
// return type: int
int EnemyMgr::getEnemyCount() const
{
	return enemyList.size();
}