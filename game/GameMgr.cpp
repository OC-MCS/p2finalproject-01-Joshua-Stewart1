#include "GameMgr.h"

const int ENEMY_COUNT = 10;			//The number of enemies to spawn on-screen
const float ENEMY_START_Y = 10;		//The starting height for the enemies

GameMgr::GameMgr()
{
	gameActive = false;
}

void GameMgr::resetRound(MenuUI &menuUI, EnemyMgr &enemyMgr, BombMgr &bombMgr, 
	MissileMgr &missileMgr, Ship &ship, Vector2f shipPos)
{
	enemyMgr.clearList();
	bombMgr.clearList();
	missileMgr.clearList();

	for (int i = 0; i < ENEMY_COUNT; i++)
	{
		enemyMgr.addEnemy(Vector2f(i*80.0f + 20, ENEMY_START_Y));
	}
	ship.setPosition(shipPos);
	menuUI.setLives(3);
}

void GameMgr::startGame(MenuUI &menuUI, EnemyMgr &enemyMgr, BombMgr &bombMgr, 
	MissileMgr &missileMgr, Ship &ship, Vector2f shipPos, Texture &newEnemy)
{
	enemyMgr = EnemyMgr(newEnemy);
	resetRound(menuUI, enemyMgr, bombMgr, missileMgr, ship, shipPos);

	menuUI.setKills(0);

	gameActive = true;
}

void GameMgr::gameOver(MenuUI &menuUI)
{
	gameActive = false;
	if (menuUI.getLives() > 0)
	{
		menuUI.gameOver(true);
	}
	else
	{
		menuUI.gameOver(false);
	}
}

void GameMgr::nextLevel(MenuUI &menuUI, EnemyMgr &enemyMgr, BombMgr &bombMgr, 
	MissileMgr &missileMgr, Ship &ship, Vector2f shipPos, Texture &newEnemy)
{
	enemyMgr = EnemyMgr(newEnemy);
	resetRound(menuUI, enemyMgr, bombMgr, missileMgr, ship, shipPos);
}

bool GameMgr::isGameActive() const
{
	return gameActive;
}