#include <iostream>
using namespace std;
#include "MissileMgr.h"

const float SHOOT_SPEED = -5;

MissileMgr::MissileMgr(Texture &img) : ProjectileMgr(img)
{
	setVelocity(SHOOT_SPEED);
}

bool MissileMgr::outOfBounds(Projectile obj)
{
	bool outOfBounds = false;

	if (obj.getPosition().y < 0)
	{
		outOfBounds = true;
	}

	return outOfBounds;
}