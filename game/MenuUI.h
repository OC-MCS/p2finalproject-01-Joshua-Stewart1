#pragma once

#include <string>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;

class MenuUI
{
private:
	Text startText;			//The label for the start button
	Text livesText;			//The label for the lives counter
	Text livesCounter;		//The label for the number of lives
	Text killText;			//The label for the kill counter
	Text killCounter;		//The label for the number of kills
	Text gameOverLabel;		//The label for when someone wins
	int livesCount;			//The number of lives
	int killCount;			//The number of kills
public:
	MenuUI(Font &fnt);
	void draw(RenderWindow &win);
	void setLives(int lives);
	void setKills(int kills);
	void gameOver(bool HumansWin);
	void loseLife();
	void killEnemy();
	bool checkStart(Vector2f mousePos);
	int getLives() const;
	int getKills() const;
};