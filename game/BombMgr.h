#pragma once

#include <list>
using namespace std;
#include "Projectile.h"

class BombMgr
{
private:
	list<Projectile> bombList;	//The list of all projectiles currently on-screen
	Texture bombTexture;		//The texture to be used by all of the projectiles
public:
	BombMgr();
	void draw(RenderWindow &win);
	void moveBombs();
	void addBomb(Vector2f pos);
	void deleteBomb(int index);
};

//Figure out how to delete based on collision stuff