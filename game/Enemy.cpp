#include "Enemy.h"

const int STEP_DISTANCE = 3;		//The distance the aliens move each time
const float ENEMY_START_Y = 10;		//The starting height for the enemies

// Constructor
// parameters: 
//   spr: the sprite to use for the enemy sprite
//   pos: the position to start the enemy in
// return type: none
Enemy::Enemy(Vector2f pos, Sprite spr)
{
	alien = spr;
	alien.setPosition(pos);
}

// draw: draws the enemy onto the window
// parameters: 
//   win: the window to draw to
// return type: void
void Enemy::draw(RenderWindow &win)
{
	win.draw(alien);
}

// dropBomb: make the enemy drop a bomb
// parameters: 
//   bombList: the list to add the bomb to
// return type: void
void Enemy::dropBomb(BombMgr &bombList)
{
	bombList.addProjectile(Vector2f(alien.getPosition().x + 10, alien.getPosition().y));
}

// descend: moves the enemy down one increment
// parameters: none
// return type: void
void Enemy::descend()
{
	alien.move(0, STEP_DISTANCE);
}

// reset: move the enemy back to the top of the screen
// parameters: none
// return type: void
void Enemy::reset()
{
	alien.setPosition(alien.getPosition().x, ENEMY_START_Y);
}

// checkHit: check if the enemy was hit by a missile
// parameters: 
//   missileList: the list to check missiles from
// return type: bool
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

// getPosition: get the position of the enemy
// parameters: none
// return type: Vector2f
Vector2f Enemy::getPosition() const
{
	return alien.getPosition();
}