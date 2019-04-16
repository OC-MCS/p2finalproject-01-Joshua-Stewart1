#include <iostream>
using namespace std;
#include "MissileMgr.h"

const float SHOOT_SPEED = -5;		//The speed at which the missiles rise


// Constructor
// parameters: 
//   img: the texture to use for the missile sprites
// return type: none
MissileMgr::MissileMgr(Texture &img) : ProjectileMgr(img)
{
	setVelocity(SHOOT_SPEED);
}

// outOfBounds: checks if a missile is offscreen
// parameters: 
//   obj: the missile to check the position of
// return type: bool
bool MissileMgr::outOfBounds(Projectile obj)
{
	bool outOfBounds = false;

	if (obj.getPosition().y < 0)
	{
		outOfBounds = true;
	}

	return outOfBounds;
}