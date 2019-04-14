#include "Enemy.h"

const int STEP_DISTANCE = 3;

Enemy::Enemy(Vector2f pos, Sprite spr)
{
	alien = spr;
	alien.setPosition(pos);
}

void Enemy::draw(RenderWindow &win)
{
	win.draw(alien);
}

void Enemy::descend()
{
	alien.move(0, STEP_DISTANCE);
}

bool Enemy::checkHit(MissileMgr &missileList)
{
	list<Projectile>::iterator it;
	list<Projectile> * ptr = missileList.getList();
	bool isHit = false;

	for (it = ptr->begin(); it != ptr->end() && !isHit; )
	{
		if (alien.getGlobalBounds().intersects(it->getSprite().getGlobalBounds()))
		{
			it = ptr->erase(it);
			isHit = true;
		}
		else
		{
			it++;
		}
	}
	return isHit;
}

void Enemy::dropBomb(BombMgr &bombList)
{
	bombList.addProjectile(alien.getPosition());
}