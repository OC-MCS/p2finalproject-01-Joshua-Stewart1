#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

class Bomb
{
private:
	Vector2f position;	//The location of the bomb
	Sprite bomb;		//Image for the bomb
public:
	Bomb(Vector2f pos, Texture &img);
	void move(float dist);
	void draw(RenderWindow &win);
};