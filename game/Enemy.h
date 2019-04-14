#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;
#include "BombMgr.h"
#include "MissileMgr.h"

class Enemy
{
private:
	Sprite alien;	//The sprite for the alien
public:
	Enemy(Vector2f pos, Sprite spr);
	void draw(RenderWindow &win);
	void descend();
	bool checkHit(MissileMgr &missileList);
	void dropBomb(BombMgr &bombList);
};