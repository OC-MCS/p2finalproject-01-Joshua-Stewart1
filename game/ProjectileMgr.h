#pragma once

#include <list>
using namespace std;
#include "Projectile.h"

class ProjectileMgr
{
private:
	list<Projectile> projectileList;	//The list of all projectiles currently on-screen
	Sprite projectile;					//The texture to be used by all of the projectiles
	float velocity;						//The speed the projectile moves at
	virtual bool outOfBounds(Projectile obj) = 0;
public:
	ProjectileMgr(Texture &img);
	void draw(RenderWindow &win);
	void moveProjectiles();
	void addProjectile(Vector2f pos);
	void clearProjectiles();
	void deleteProjectile(int index);
	void setVelocity(float vel);
	void clearList();
	list<Projectile> * getList();
};