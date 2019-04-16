#include "MenuUI.h"

const int FONT_SIZE = 20;								//The size to make the font

const Vector2f START_POSITION = Vector2f(360, 260);		//The position of the start text
const Vector2f LIVES_POSITION = Vector2f(20, 560);		//The position of the live counter
const Vector2f KILL_POSITION = Vector2f(600, 560);		//The position of the kill counter
const Vector2f GAME_OVER = Vector2f(250, 200);			//The position of the game over text

const int LIFE_COUNT = 3;

// Constructor
// parameters: 
//   fnt: the font to use for the text labels
// return type: none
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

// draw: draws the text labels onto the window
// parameters: 
//   win: the window to draw to
// return type: void
void MenuUI::draw(RenderWindow &win)
{
	win.draw(startText);
	win.draw(livesText);
	win.draw(livesCounter);
	win.draw(killText);
	win.draw(killCounter);
	win.draw(gameOverLabel);
}

// setLives: set the number of lives remaining
// parameters: 
//   lives: the number of lives to be set
// return type: void
void MenuUI::setLives(int lives)
{
	livesCount = lives;
	livesCounter.setString(to_string(livesCount));
}

// setKills: set the number of aliens killed
// parameters: 
//   kills: the number of kills to be set
// return type: void
void MenuUI::setKills(int kills)
{
	killCount = kills;
	killCounter.setString(to_string(killCount));
}

// gameOver: change text display for the end of a game
// parameters: 
//   HumansWin: whether or not the player won
// return type: void
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

// loseLife: decrement the number of lives by one
// parameters: none
// return type: void
void MenuUI::loseLife()
{
	livesCount -= 1;
	livesCounter.setString(to_string(livesCount));
}

// killEnemy: increment the number of kills by one
// parameters: none
// return type: void
void MenuUI::killEnemy()
{
	killCount += 1;
	killCounter.setString(to_string(killCount));
}

// checkStart: change if the mouse is inside the start text when clicked
// parameters: 
//   mousePos: the current position of the mouse
// return type: bool
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

// getPosition: get the number of lives remaining
// parameters: none
// return type: int
int MenuUI::getLives() const
{
	return livesCount;
}

// getPosition: get the number of aliens killed
// parameters: none
// return type: int
int MenuUI::getKills() const
{
	return killCount;
}