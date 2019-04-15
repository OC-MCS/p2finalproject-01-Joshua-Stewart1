#pragma once

#include <list>
using namespace std;
#include "Enemy.h"
#include "Ship.h"

class EnemyMgr
{
private:
	list<Enemy> enemyList;	//The list of all enemies on-screen
	Sprite enemy;			//The texture to be used for all (regular) enemies
public:
	EnemyMgr(Texture &img);
	void draw(RenderWindow &win);
	void descendAll();
	void resetPositions();
	bool checkHits(MissileMgr &missileList);
	bool checkPosition(Ship &ship);
	void addEnemy(Vector2f pos);
	void dropBomb(BombMgr &bombList);
	void clearList();
	int getEnemyCount() const;
};