#include "Enemy.h"

const int STEP_DISTANCE = 3;		//The distance the aliens move each time
const float ENEMY_START_Y = 10;		//The starting height for the enemies

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

void Enemy::reset()
{
	alien.setPosition(alien.getPosition().x, ENEMY_START_Y);
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
	bombList.addProjectile(Vector2f(alien.getPosition().x + 10, alien.getPosition().y));
}

Vector2f Enemy::getPosition() const
{
	return alien.getPosition();
}