#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf; 
#include "GameMgr.h"

//============================================================
// Joshua Stewart
// 4/13/19
// Programming Assignment #8
// Description: Space Invaders
//============================================================

int main()
{	
	const int WINDOW_WIDTH = 800;		//The width of the window
	const int WINDOW_HEIGHT = 600;		//The height of the window

	const float SHIP_X = WINDOW_WIDTH / 2.0f;		//The starting position of the ship in x
	const float SHIP_Y = WINDOW_HEIGHT - 100.0f;	//The starting position of the ship in y

	//Initialize Window

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "aliens!");		//The window to render
	window.setFramerateLimit(60);

	//Load Textures

	Texture starsTexture;	//The texture for the background
	if (!starsTexture.loadFromFile("stars.jpg"))
	{
		cout << "Unable to load stars texture!" << endl;
		exit(EXIT_FAILURE);
	}
	Texture shipTexture;	//The texture for the ship
	if (!shipTexture.loadFromFile("CustomShipSprite.png"))
	{
		cout << "Unable to load ship texture!" << endl;
		exit(EXIT_FAILURE);
	}
	Texture enemyTexture;	//The texture for the enemies
	if (!enemyTexture.loadFromFile("CustomAlienSprite.png"))
	{
		cout << "Unable to load enemy texture!" << endl;
		exit(EXIT_FAILURE);
	}
	Texture strongEnemyTexture;	//The texture for the enemies in round two
	if (!strongEnemyTexture.loadFromFile("CustomAlienSprite2.png"))
	{
		cout << "Unable to load big enemy texture!" << endl;
		exit(EXIT_FAILURE);
	}
	Texture missileTexture;	//The texture for the missiles
	if (!missileTexture.loadFromFile("CustomMissileSprite.png"))
	{
		cout << "Unable to load missile texture!" << endl;
		exit(EXIT_FAILURE);
	}
	Texture bombTexture;	//The texture for the bombs
	if (!bombTexture.loadFromFile("CustomBombSprite.png"))
	{
		cout << "Unable to load bomb texture!" << endl;
		exit(EXIT_FAILURE);
	}

	//Load Fonts
	
	Font font;	//The font for the labels
	if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
	{
		cout << "Unable to load font!" << endl;
		exit(EXIT_FAILURE);
	}

	//Initialize Background Sprite

	Sprite background;						//The sprite for the background of the game
	background.setTexture(starsTexture);
	background.setScale(1.5, 1.5);

	//Initialize Game Objects

	MenuUI menuUI(font);									//The menu interfacing object
	Ship ship (Vector2f(SHIP_X,SHIP_Y), shipTexture);		//The ship object
	BombMgr bombMgr(bombTexture);							//The manager for bomb objects
	MissileMgr missileMgr(missileTexture);					//The manager for missile objects
	EnemyMgr enemyMgr(enemyTexture);						//The manager for enemy objects
	GameMgr spaceInvaders;									//The manager for game functions

	//Initialize Timers

	Clock bombTimer;		//The timer for determining when to drop bombs
	Clock shootTimer;		//The timer for determining when the player can shoot again
	Clock descendTimer;		//The timer for determining when to move the enemies down

	double descentDelay = 0.2;	//The amount of time between each descent

	//Randomize Bomb Dropping

	srand(time(0));
	int bombDelay = 4;						//The maximum value for the bomb drop delay
	int delay = (rand() % bombDelay) + 1;	//The number of seconds to delay dropping the bomb

	//Run Game

	while (window.isOpen())
	{
		Event event;

		while (window.pollEvent(event))
		{
			//Check Close

			if (event.type == Event::Closed)
				window.close();
			else if (event.type == Event::KeyPressed)
			{
				//Check Shooting

				if (event.key.code == Keyboard::Space && shootTimer.getElapsedTime().asSeconds() >= 0.3)
				{
					ship.shootMissile(missileMgr);
					shootTimer.restart();
				}
			}
			else if (event.type == Event::MouseButtonReleased)
			{
				//Check Button Click

				Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));	//The position of the mouse
				if(menuUI.checkStart(mousePos))
				{
					spaceInvaders.startGame(menuUI, enemyMgr, bombMgr, missileMgr, ship,
						Vector2f(SHIP_X, SHIP_Y), enemyTexture);
					bombDelay = 4;
					descentDelay = 0.2;
					bombTimer.restart();
				}
			}
		}

		if(spaceInvaders.isGameActive())
		{
			//Check Hits on Ship

			if (ship.checkHit(bombMgr) || enemyMgr.checkPosition(ship))
			{
				menuUI.loseLife();
				enemyMgr.resetPositions();
			}

			//Check Hits on Aliens

			if (enemyMgr.checkHits(missileMgr))
			{
				menuUI.killEnemy();
			}

			//Manager Descent Speed

			if (descendTimer.getElapsedTime().asSeconds() >= descentDelay)
			{
				enemyMgr.descendAll();
				descendTimer.restart();
			}

			//Manage Bomb Drops

			if (bombTimer.getElapsedTime().asSeconds() >= delay)
			{
				enemyMgr.dropBomb(bombMgr);
				bombTimer.restart();
				delay = (rand() % bombDelay) + 1;
			}

			//Move and Erase Projectiles Out of Bounds

			ship.move();
			missileMgr.moveProjectiles();
			missileMgr.clearProjectiles();
			bombMgr.moveProjectiles();
			bombMgr.clearProjectiles();

			//Game Over

			if (menuUI.getLives() <= 0)
			{
				spaceInvaders.gameOver(menuUI);
			}

			if (enemyMgr.getEnemyCount() <= 0)
			{
				if (bombDelay == 4)
				{
					spaceInvaders.nextLevel(menuUI, enemyMgr, bombMgr, missileMgr, ship,
						Vector2f(SHIP_X, SHIP_Y), strongEnemyTexture);
					bombDelay = 2;
					descentDelay = 0.1;
				}
				else
				{
					spaceInvaders.gameOver(menuUI);
				}
				
			}
		}

		//Draw the Scene
		window.draw(background);
		menuUI.draw(window);
		ship.draw(window);
		missileMgr.draw(window);
		bombMgr.draw(window);
		enemyMgr.draw(window);

		//Display
		window.display();

	}

	return 0;
}

