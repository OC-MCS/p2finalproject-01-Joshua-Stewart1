#include <iostream>
using namespace std;
#include "MissileMgr.h"

const float SHOOT_SPEED = -5;

MissileMgr::MissileMgr()
{

	if (!missileTexture.loadFromFile("missile.jpg"))
	{
		cout << "Unable to load bomb texture!" << endl;
		exit(EXIT_FAILURE);
	}
}

void MissileMgr::draw(RenderWindow &win)
{
	list<Projectile>::iterator it;

	for (it = missileList.begin(); it != missileList.end(); it++)
	{
		it->draw(win);
	}
}

void MissileMgr::moveMissiles()
{
	list<Projectile>::iterator it;

	for (it = missileList.begin(); it != missileList.end(); it++)
	{
		it->move(SHOOT_SPEED);
	}
}

void MissileMgr::addMissile(Vector2f pos)
{
	missileList.push_back(Projectile(pos, missileTexture));
}

void MissileMgr::deleteMissile(int index)
{
	list<Projectile>::iterator it;

	it = missileList.begin();
	advance(it, index);
	missileList.erase(it);
}