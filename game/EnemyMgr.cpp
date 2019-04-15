#include <cstdlib>
#include <ctime>
using namespace std;
#include "EnemyMgr.h"

EnemyMgr::EnemyMgr(Texture &img)
{
	enemy.setTexture(img);
}

void EnemyMgr::draw(RenderWindow &win)
{
	list<Enemy>::iterator it;

	for (it = enemyList.begin(); it != enemyList.end(); it++)
	{
		it->draw(win);
	}
}

void EnemyMgr::descendAll()
{
	list<Enemy>::iterator it;

	for (it = enemyList.begin(); it != enemyList.end(); it++)
	{
		it->descend();
	}
}

void EnemyMgr::resetPositions()
{
	list<Enemy>::iterator it;

	for (it = enemyList.begin(); it != enemyList.end(); it++)
	{
		it->reset();
	}
}

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

bool EnemyMgr::checkPosition(Ship &ship)
{
	list<Enemy>::iterator it;
	bool isAtBottom = false;

	for (it = enemyList.begin(); it != enemyList.end() && !isAtBottom; it++)
	{
		if (it->getPosition().y >= ship.getPosition().y)
		{
			it = enemyList.erase(it);
			isAtBottom = true;
		}
	}
	return isAtBottom;
}

void EnemyMgr::addEnemy(Vector2f pos)
{
	enemyList.push_back(Enemy(pos, enemy));
}

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

void EnemyMgr::clearList()
{
	list<Enemy>::iterator it;

	for (it = enemyList.begin(); it != enemyList.end(); )
	{
		it = enemyList.erase(it);
	}
}

int EnemyMgr::getEnemyCount() const
{
	return enemyList.size();
}