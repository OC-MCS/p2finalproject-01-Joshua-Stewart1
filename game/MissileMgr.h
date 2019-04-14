#pragma once

#include <list>
using namespace std;
#include "ProjectileMgr.h"

class MissileMgr : public ProjectileMgr
{
private:
	bool outOfBounds(Projectile obj);
public:
	MissileMgr(Texture &img);
};
