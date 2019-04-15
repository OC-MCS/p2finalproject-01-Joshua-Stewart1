#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;
#include "BombMgr.h"
#include "MissileMgr.h"

class Ship
{
private:
	Sprite ship;	//Image for the ship
public:
	Ship(Vector2f pos, Texture &img);
	void draw(RenderWindow &win);
	void move();
	void shootMissile(MissileMgr &missileList);
	void setPosition(Vector2f pos);
	bool checkHit(BombMgr &bombList);
	Vector2f getPosition() const;
};