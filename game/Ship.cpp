#include <iostream>
using namespace std;
#include "Ship.h"

Ship::Ship(Vector2f pos, Texture &img)
{
	ship.setTexture(img);
	ship.setPosition(pos);
}

void Ship::draw(RenderWindow &win)
{
	win.draw(ship);
}

void Ship::move()
{
	const float DISTANCE = 5.0;

	if (Keyboard::isKeyPressed(Keyboard::Left) && ship.getPosition().x > 0)
	{
		ship.move(-DISTANCE, 0);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right) && ship.getPosition().x < 780)
	{
		ship.move(DISTANCE, 0);
	}
}

bool Ship::checkHit(BombMgr &bombList)
{
	list<Projectile>::iterator it;
	list<Projectile> * ptr = bombList.getList();
	bool isHit = false;

	for (it = ptr->begin(); it != ptr->end() && !isHit; )
	{
		if (ship.getGlobalBounds().intersects(it->getSprite().getGlobalBounds()))
		{
			ptr->erase(it);
			isHit = true;
		}
		else
		{
			it++;
		}
	}
	return isHit;
}

void Ship::shootMissile(MissileMgr &missileList)
{
	missileList.addProjectile(ship.getPosition());
}