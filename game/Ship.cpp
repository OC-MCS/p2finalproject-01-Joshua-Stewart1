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
	else if (Keyboard::isKeyPressed(Keyboard::Right) && ship.getPosition().x < 768)
	{
		ship.move(DISTANCE, 0);
	}
}

void Ship::setPosition(Vector2f pos)
{
	ship.setPosition(pos);
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

void Ship::shootMissile(MissileMgr &missileList)
{
	missileList.addProjectile(Vector2f(ship.getPosition().x + 12, ship.getPosition().y));
}

Vector2f Ship::getPosition() const
{
	return ship.getPosition();
}