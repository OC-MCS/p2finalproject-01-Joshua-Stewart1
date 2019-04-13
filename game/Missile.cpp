#include "Missile.h"

Missile::Missile(Vector2f pos, Texture &img)
{
	position = pos;
	missile.setTexture(img);
}

void Missile::move(float dist)
{
	missile.move(0, -dist);
}

void Missile::draw(RenderWindow &win)
{
	win.draw(missile);
}