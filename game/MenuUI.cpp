#include "MenuUI.h"

const int FONT_SIZE = 20;

const Vector2f START_POSITION = Vector2f(360, 260);
const Vector2f LIVES_POSITION = Vector2f(20, 560);
const Vector2f KILL_POSITION = Vector2f(600, 560);
const Vector2f GAME_OVER = Vector2f(250, 200);

const int LIFE_COUNT = 3;

MenuUI::MenuUI(Font &fnt)
{
	livesCount = LIFE_COUNT;
	killCount = 0;
	
	startText = Text("Start", fnt, FONT_SIZE * 2);
	startText.setPosition(START_POSITION);

	livesText = Text("Lives: ", fnt, FONT_SIZE);
	livesText.setPosition(LIVES_POSITION);

	livesCounter = Text(to_string(livesCount), fnt, FONT_SIZE);
	livesCounter.setPosition(LIVES_POSITION.x + 60, LIVES_POSITION.y);

	killText = Text("Aliens Defeated: ", fnt, FONT_SIZE);
	killText.setPosition(KILL_POSITION);

	killCounter = Text(to_string(killCount), fnt, FONT_SIZE);
	killCounter.setPosition(KILL_POSITION.x + 160, KILL_POSITION.y);

	gameOverLabel = Text("", fnt, FONT_SIZE * 2);
	gameOverLabel.setPosition(GAME_OVER);
}

void MenuUI::draw(RenderWindow &win)
{
	win.draw(startText);
	win.draw(livesText);
	win.draw(livesCounter);
	win.draw(killText);
	win.draw(killCounter);
	win.draw(gameOverLabel);
}

void MenuUI::setLives(int lives)
{
	livesCount = lives;
	livesCounter.setString(to_string(livesCount));
}

void MenuUI::setKills(int kills)
{
	killCount = kills;
	killCounter.setString(to_string(killCount));
}

int MenuUI::getLives() const
{
	return livesCount;
}

int MenuUI::getKills() const
{
	return killCount;
}

void MenuUI::loseLife()
{
	livesCount -= 1;
	livesCounter.setString(to_string(livesCount));
}

void MenuUI::killEnemy()
{
	killCount += 1;
	killCounter.setString(to_string(killCount));
}

bool MenuUI::checkStart(Vector2f mousePos)
{
	bool startClicked = false;

	if (startText.getGlobalBounds().contains(mousePos))
	{
		startClicked = true;
		startText.setString("");
		gameOverLabel.setString("");
	}
	return startClicked;
}

void MenuUI::gameOver(bool HumansWin)
{
	startText.setString("Start");
	if (HumansWin)
	{
		gameOverLabel.setString("The Humans Win!");
	}
	else
	{
		gameOverLabel.setString("The Aliens Win!");
	}
}