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

void EnemyMgr::checkHits(MissileMgr &missileList)
{
	list<Enemy>::iterator it;

	for (it = enemyList.begin(); it != enemyList.end(); )
	{
		if (it->checkHit(missileList))
		{
			it = enemyList.erase(it);
		}
		else
		{
			it++;
		}
	}
}

void EnemyMgr::addEnemy(Vector2f pos)
{
	enemyList.push_back(Enemy(pos, enemy));
}