#include <iostream>
using namespace std;
#include "BombMgr.h"

const float DROP_SPEED = 5;

BombMgr::BombMgr()
{
	
	if (!bombTexture.loadFromFile("bomb.jpg"))
	{
		cout << "Unable to load bomb texture!" << endl;
		exit(EXIT_FAILURE);
	}
}

void BombMgr::draw(RenderWindow &win)
{
	list<Projectile>::iterator it;

	for (it = bombList.begin(); it != bombList.end(); it++)
	{
		it->draw(win);
	}
}

void BombMgr::moveBombs()
{
	list<Projectile>::iterator it;

	for (it = bombList.begin(); it != bombList.end(); it++)
	{
		it->move(DROP_SPEED);
	}
}

void BombMgr::addBomb(Vector2f pos)
{
	bombList.push_back(Projectile(pos, bombTexture));
}

void BombMgr::deleteBomb(int index)
{
	list<Projectile>::iterator it;

	it = bombList.begin();
	advance(it, index);
	bombList.erase(it);
}