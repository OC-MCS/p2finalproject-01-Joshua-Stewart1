#include <iostream>
using namespace std;
#include "BombMgr.h"

const float DROP_SPEED = 5;

BombMgr::BombMgr(Texture &img) : ProjectileMgr(img)
{
	setVelocity(DROP_SPEED);
}

bool BombMgr::outOfBounds(Projectile obj)
{
	bool outOfBounds = false;
	
	if(obj.getPosition().y > 600)
	{
		outOfBounds = true;
	}
	return outOfBounds;
}