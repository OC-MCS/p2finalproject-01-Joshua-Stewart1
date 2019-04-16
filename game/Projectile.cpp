#include "Projectile.h"

// Constructor
// parameters: 
//   img: the texture to use for the projectile sprite
//   pos: the position to start the projectile in
// return type: none
Projectile::Projectile(Vector2f pos, Sprite img)
{
	projectile = img;
	projectile.setPosition(pos);
}

// draw: draws the projectile onto the window
// parameters: 
//   win: the window to draw to
// return type: void
void Projectile::draw(RenderWindow &win)
{
	win.draw(projectile);
}

// moveProjectiles: moves the projectile one increment
// parameters: 
//   dist: the distance to move the projectile
// return type: void
void Projectile::move(float dist)
{
	projectile.move(0, dist);
}

// getSprite: get the sprite of the projectile
// parameters: none
// return type: Sprite
Sprite Projectile::getSprite() const
{
	return projectile;
}

// getPosition: get the position of the projectile
// parameters: none
// return type: Vector2f
Vector2f Projectile::getPosition() const
{
	return projectile.getPosition();
}