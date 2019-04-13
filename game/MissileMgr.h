#pragma once

#include <list>
using namespace std;
#include "Projectile.h"

class MissileMgr
{
private:
	list<Projectile> missileList;	//The list of all projectiles currently on-screen
	Texture missileTexture;			//The texture to be used by all of the projectiles
public:
	MissileMgr();
	void draw(RenderWindow &win);
	void moveMissiles();
	void addMissile(Vector2f pos);
	void deleteMissile(int index);
};
