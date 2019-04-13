#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

class Projectile
{
private:
	Vector2f position;	//The location of the projectile
	Sprite projectile;	//Image for the projectile
public:
	Projectile(Vector2f pos, Texture &img);
	void move(float dist);
	void draw(RenderWindow &win);
	Sprite getSprite() const;
};