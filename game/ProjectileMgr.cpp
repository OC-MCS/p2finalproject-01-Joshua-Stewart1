#include <iostream>
using namespace std;
#include "ProjectileMgr.h"

// Constructor
// parameters: 
//   img: the texture to use for the projectile sprites
// return type: none
ProjectileMgr::ProjectileMgr(Texture &img)
{
	velocity = 0;
	projectile.setTexture(img);
}

// draw: draws all of the projectiles onto the window
// parameters: 
//   win: the window to draw to
// return type: void
void ProjectileMgr::draw(RenderWindow &win)
{
	list<Projectile>::iterator it;

	for (it = projectileList.begin(); it != projectileList.end(); it++)
	{
		it->draw(win);
	}
}

// moveProjectiles: moves all of the projectiles one increment
// parameters: none
// return type: void
void ProjectileMgr::moveProjectiles()
{
	list<Projectile>::iterator it;

	for (it = projectileList.begin(); it != projectileList.end(); it++)
	{
		it->move(velocity);
	}
}

// addProjectile: adds a projectile to the list
// parameters: 
//   pos: the position to spawn the projectile at
// return type: void
void ProjectileMgr::addProjectile(Vector2f pos)
{
	projectileList.push_back(Projectile(pos, projectile));
}

// clearProjectiles: clear all of the projectiles offscreen
// parameters: none
// return type: void
void ProjectileMgr::clearProjectiles()
{
	list<Projectile>::iterator it;

	for (it = projectileList.begin(); it != projectileList.end(); )
	{
		if (outOfBounds(*it))
		{
			it = projectileList.erase(it);
		}
		else
		{
			it++;
		}
	}
}

// deleteProjectile: removes a projectile from the list
// parameters: 
//   index: the index of the projectile to remove
// return type: void
void ProjectileMgr::deleteProjectile(int index)
{
	list<Projectile>::iterator it;
	it = projectileList.begin();
	advance(it, index);
	projectileList.erase(it);
}

// setVelocity: change the speed of the projectiles
// parameters: 
//   vel: the new speed for velocity to be set to
// return type: void
void ProjectileMgr::setVelocity(float vel)
{
	velocity = vel;
}

// clearList: removes all projectiles from the list
// parameters: none
// return type: void
void ProjectileMgr::clearList()
{
	list<Projectile>::iterator it;

	for (it = projectileList.begin(); it != projectileList.end(); )
	{
		it = projectileList.erase(it);
	}
}

// getList: get the list of projectiles
// parameters: none
// return type: list<Projectile>*
list<Projectile> * ProjectileMgr::getList()
{
	return &projectileList;
}