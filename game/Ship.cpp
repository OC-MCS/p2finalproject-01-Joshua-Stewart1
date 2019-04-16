#include <iostream>
using namespace std;
#include "Ship.h"

// Constructor
// parameters: 
//   img: the texture to use for the ship sprite
//   pos: the position to start the ship in
// return type: none
Ship::Ship(Vector2f pos, Texture &img)
{
	ship.setTexture(img);
	ship.setPosition(pos);
}

// draw: draws the ship onto the window
// parameters: 
//   win: the window to draw to
// return type: void
void Ship::draw(RenderWindow &win)
{
	win.draw(ship);
}

// shootMissile: make the ship shoot a missile
// parameters: 
//   missileList: the list to add the bomb to
// return type: void
void Ship::shootMissile(MissileMgr &missileList)
{
	missileList.addProjectile(Vector2f(ship.getPosition().x + 12, ship.getPosition().y));
}

// setPosition: set the position of the ship
// parameters: 
//   pos: the position to move the ship to
// return type: void
void Ship::setPosition(Vector2f pos)
{
	ship.setPosition(pos);
}

// move: moves the ship sideways on input
// parameters: none
// return type: void
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

// checkHit: check if the ship was hit by a bomb
// parameters: 
//   bombList: the list to check bombs from
// return type: bool
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

// getPosition: get the position of the ship
// parameters: none
// return type: Vector2f
Vector2f Ship::getPosition() const
{
	return ship.getPosition();
}