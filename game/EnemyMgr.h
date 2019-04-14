#pragma once

#include <list>
using namespace std;
#include "Enemy.h"

class EnemyMgr
{
private:
	list<Enemy> enemyList;	//The list of all enemies on-screen
	Sprite enemy;			//The texture to be used for all (regular) enemies
public:
	EnemyMgr(Texture &img);
	void draw(RenderWindow &win);
	void descendAll();
	void checkHits(MissileMgr &missileList);
	void addEnemy(Vector2f pos);
	
};