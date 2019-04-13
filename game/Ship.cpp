#include <iostream>
using namespace std;
#include "Ship.h"

Ship::Ship(Vector2f pos)
{
	Texture shipTexture;
	if (!shipTexture.loadFromFile("ship.png"))
	{
		cout << "Unable to load ship texture!" << endl;
		exit(EXIT_FAILURE);
	}

	position = pos;
	ship.setTexture(shipTexture);
}

void Ship::move()
{
	const float DISTANCE = 5.0;

	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		ship.move(-DISTANCE, 0);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		ship.move(DISTANCE, 0);
	}
}

void Ship::draw(RenderWindow &win)
{
	win.draw(ship);
}

Sprite Ship::getSprite() const
{
	return ship;
}