#include <iostream>
using namespace std;
#include "ProjectileMgr.h"

ProjectileMgr::ProjectileMgr(Texture &img)
{
	velocity = 0;
	projectile.setTexture(img);
}

void ProjectileMgr::draw(RenderWindow &win)
{
	list<Projectile>::iterator it;

	for (it = projectileList.begin(); it != projectileList.end(); it++)
	{
		it->draw(win);
	}
}

void ProjectileMgr::moveProjectiles()
{
	list<Projectile>::iterator it;

	for (it = projectileList.begin(); it != projectileList.end(); it++)
	{
		it->move(velocity);
	}
}

void ProjectileMgr::addProjectile(Vector2f pos)
{
	projectileList.push_back(Projectile(pos, projectile));
}

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

void ProjectileMgr::deleteProjectile(int index)
{
	list<Projectile>::iterator it;
	it = projectileList.begin();
	advance(it, index);
	projectileList.erase(it);
}

void ProjectileMgr::setVelocity(float vel)
{
	velocity = vel;
}

list<Projectile> * ProjectileMgr::getList()
{
	return &projectileList;
}