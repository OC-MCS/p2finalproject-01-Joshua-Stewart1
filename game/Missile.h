#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

class Missile
{
private:
	Vector2f position;	//The location of the missile
	Sprite missile;		//Image for the missile
public:
	Missile(Vector2f pos, Texture &img);
	void move(float dist);
	void draw(RenderWindow &win);
};