#include "Projectile.h"

Projectile::Projectile(Vector2f pos, Texture &img)
{
	position = pos;
	projectile.setTexture(img);
}

void Projectile::move(float dist)
{
	projectile.move(0, dist);
}

void Projectile::draw(RenderWindow &win)
{
	win.draw(projectile);
}

Sprite Projectile::getSprite() const
{
	return projectile;
}