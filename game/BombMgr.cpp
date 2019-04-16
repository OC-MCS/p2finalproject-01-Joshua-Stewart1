#include <iostream>
using namespace std;
#include "BombMgr.h"

const float DROP_SPEED = 5;		//The speed at which the bombs fall

// Constructor
// parameters: 
//   img: the texture to use for the bomb sprites
// return type: none
BombMgr::BombMgr(Texture &img) : ProjectileMgr(img)
{
	setVelocity(DROP_SPEED);
}

// outOfBounds: checks if a bomb is offscreen
// parameters: 
//   obj: the bomb to check the position of
// return type: bool
bool BombMgr::outOfBounds(Projectile obj)
{
	bool outOfBounds = false;
	
	if(obj.getPosition().y > 600)
	{
		outOfBounds = true;
	}
	return outOfBounds;
}