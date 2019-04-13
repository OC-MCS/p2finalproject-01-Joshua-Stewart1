#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

class Ship
{
private:
	Vector2f position;	//The location of the ship
	Sprite ship;		//Image for the ship
public:
	Ship(Vector2f pos);
	void move();
	void draw(RenderWindow &win);
	Sprite getSprite() const;
};