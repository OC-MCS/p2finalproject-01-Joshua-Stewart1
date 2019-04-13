#include "Bomb.h"

Bomb::Bomb(Vector2f pos, Texture &img)
{
	position = pos;
	bomb.setTexture(img);
}

void Bomb::move(float dist)
{
	bomb.move(0, dist);
}

void Bomb::draw(RenderWindow &win)
{
	win.draw(bomb);
}