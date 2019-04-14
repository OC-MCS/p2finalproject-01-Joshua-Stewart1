#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf; 
#include "Ship.h"
#include "MissileMgr.h"
#include "BombMgr.h"
#include "EnemyMgr.h"

//============================================================
// Joshua Stewart
// 4/13/19
// Programming Assignment #8
// Description: Space Invaders
//============================================================

int main()
{
	const int ENEMY_COUNT = 10;			//The number of enemies to spawn on-screen
	
	const int WINDOW_WIDTH = 800;		//The width of the window
	const int WINDOW_HEIGHT = 600;		//The height of the window

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "aliens!");		//The window to render
	window.setFramerateLimit(60);

	//Load Textures

	Texture starsTexture;	//The teture for the background
	if (!starsTexture.loadFromFile("stars.jpg"))
	{
		cout << "Unable to load stars texture!" << endl;
		exit(EXIT_FAILURE);
	}
	Texture shipTexture;	//The teture for the ship
	if (!shipTexture.loadFromFile("CustomShipSprite.png"))
	{
		cout << "Unable to load ship texture!" << endl;
		exit(EXIT_FAILURE);
	}
	Texture enemyTexture;	//The teture for the enemies
	if (!enemyTexture.loadFromFile("CustomAlienSprite.png"))
	{
		cout << "Unable to load ship texture!" << endl;
		exit(EXIT_FAILURE);
	}
	Texture missileTexture;	//The teture for the missiles
	if (!missileTexture.loadFromFile("CustomMissileSprite.png"))
	{
		cout << "Unable to load ship texture!" << endl;
		exit(EXIT_FAILURE);
	}
	Texture bombTexture;	//The teture for the bombs
	if (!bombTexture.loadFromFile("CustomBombSprite.png"))
	{
		cout << "Unable to load ship texture!" << endl;
		exit(EXIT_FAILURE);
	}

	//Load Fonts
	
	Font font; //The font for the labels
	if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
	{
		cout << "Unable to load font!" << endl;
		exit(EXIT_FAILURE);
	}



	Sprite background;
	background.setTexture(starsTexture);
	background.setScale(1.5, 1.5);

	float shipX = window.getSize().x / 2.0f;
	float shipY = window.getSize().y - 100.0f;

	Ship ship (Vector2f(shipX,shipY), shipTexture);
	BombMgr bombMgr(bombTexture);
	MissileMgr missileMgr(missileTexture);
	EnemyMgr enemyMgr(enemyTexture);

	for (int i = 0; i < ENEMY_COUNT; i++)
	{
		enemyMgr.addEnemy(Vector2f(static_cast<float>(20 + (i*80)),10.0f));
	}

	while (window.isOpen())
	{
		Event event;

		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == Event::Closed)
				window.close();
			else if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Space)
				{
					// handle space bar
					ship.shootMissile(missileMgr);
				}
				
			}
		}
		
		ship.move();
		missileMgr.moveProjectiles();
		missileMgr.clearProjectiles();
		//enemyMgr.descendAll();
		enemyMgr.checkHits(missileMgr);

		window.draw(background);
		ship.draw(window);
		missileMgr.draw(window);
		enemyMgr.draw(window);

		window.display();

	}

	return 0;
}

