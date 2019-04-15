#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

#include "MenuUI.h"
#include "Ship.h"
#include "MissileMgr.h"
#include "BombMgr.h"
#include "EnemyMgr.h"

class GameMgr
{
private:
	bool gameActive;
	void resetRound(MenuUI &menuUI, EnemyMgr &enemyMgr, BombMgr &bombMgr, 
		MissileMgr &missileMgr, Ship &ship, Vector2f shipPos);
public:
	GameMgr();
	void startGame(MenuUI &menuUI, EnemyMgr &enemyMgr, BombMgr &bombMgr, 
		MissileMgr &missileMgr, Ship &ship, Vector2f shipPos, Texture &newEnemy);
	void gameOver(MenuUI &menuUI);
	void nextLevel(MenuUI &menuUI, EnemyMgr &enemyMgr, BombMgr &bombMgr, 
		MissileMgr &missileMgr, Ship &ship, Vector2f shipPos, Texture &newEnemy);
	bool isGameActive() const;
};