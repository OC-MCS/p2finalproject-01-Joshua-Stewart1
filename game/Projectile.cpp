#include "Projectile.h"

Projectile::Projectile(Vector2f pos, Sprite img)
{
	projectile = img;
	projectile.setPosition(pos);
}

void Projectile::draw(RenderWindow &win)
{
	win.draw(projectile);
}

void Projectile::move(float dist)
{
	projectile.move(0, dist);
}

Sprite Projectile::getSprite() const
{
	return projectile;
}

Vector2f Projectile::getPosition() const
{
	return projectile.getPosition();
}