#pragma once

#include <string>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;

class MenuUI
{
private:
	Text startText;
	Text livesText;
	Text livesCounter;
	Text killText;
	Text killCounter;
	Text gameOverLabel;
	int livesCount;
	int killCount;
public:
	MenuUI(Font &fnt);
	void draw(RenderWindow &win);
	void setLives(int lives);
	void setKills(int kills);
	int getLives() const;
	int getKills() const;
	void loseLife();
	void killEnemy();
	bool checkStart(Vector2f mousePos);
	void gameOver(bool HumansWin);
};