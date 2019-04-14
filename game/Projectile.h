#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

class Projectile
{
private:
	Sprite projectile;	//Image for the projectile
public:
	Projectile(Vector2f pos, Sprite img);
	void draw(RenderWindow &win);
	void move(float dist);
	Sprite getSprite() const;
	Vector2f getPosition() const;
};