#pragma once

#include <list>
using namespace std;
#include "ProjectileMgr.h"

class BombMgr : public ProjectileMgr
{
private:
	bool outOfBounds(Projectile obj);
public:
	BombMgr(Texture &img);
};