#include "GameMgr.h"

const int ENEMY_COUNT = 10;			//The number of enemies to spawn on-screen
const float ENEMY_START_Y = 10;		//The starting height for the enemies


// Constructor
// parameters: none
// return type: none
GameMgr::GameMgr()
{
	gameActive = false;
}

// resetRound: reset the positions of objects and clear projectiles
// parameters: 
//   menuUI: the menu to modify the lives of
//   enemyMgr: the enemy list to add the enemies to
//   bombMgr: the bomb list to clear
//   missileMgr: the missile list to clear
//   ship: the ship to reset the position of
//   shipPos: the position to reset the ship to
// return type: void
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

// startGame: start the gameplay
// parameters: 
//   menuUI: the menu to modify to reset lives and kills and hide start label
//   enemyMgr: the enemy list to add the enemies to
//   bombMgr: the bomb list to clear
//   missileMgr: the missile list to clear
//   ship: the ship to reset the position of
//   shipPos: the position to reset the ship to
//   newEnemy: the texture for the regular enemies
// return type: void
void GameMgr::startGame(MenuUI &menuUI, EnemyMgr &enemyMgr, BombMgr &bombMgr, 
	MissileMgr &missileMgr, Ship &ship, Vector2f shipPos, Texture &newEnemy)
{
	enemyMgr = EnemyMgr(newEnemy);
	resetRound(menuUI, enemyMgr, bombMgr, missileMgr, ship, shipPos);

	menuUI.setKills(0);

	gameActive = true;
}

// nextLevel: advance the game to the second level
// parameters: 
//   menuUI: the menu to modify to reset lives
//   enemyMgr: the enemy list to add the new enemies to
//   bombMgr: the bomb list to clear
//   missileMgr: the missile list to clear
//   ship: the ship to reset the position of
//   shipPos: the position to reset the ship to
//   newEnemy: the new texture for the new enemies
// return type: void
void GameMgr::nextLevel(MenuUI &menuUI, EnemyMgr &enemyMgr, BombMgr &bombMgr, 
	MissileMgr &missileMgr, Ship &ship, Vector2f shipPos, Texture &newEnemy)
{
	enemyMgr = EnemyMgr(newEnemy);
	resetRound(menuUI, enemyMgr, bombMgr, missileMgr, ship, shipPos);
}

// gameOver: end the game and decide which game over text to display
// parameters: 
//   menuUI: the menu to modify to display the game over
// return type: void
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

// isGameActive: check if the game is currently active
// parameters: none
// return type: bool
bool GameMgr::isGameActive() const
{
	return gameActive;
}