#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>
#include "Bullet.h"
#include "Enemy.h"
#include "Player.h"
using namespace sf;
class Game
{
protected:
	float DificultyFactor;
	unsigned int DificultyFactorCounter;
	unsigned int textEscCounter;
	Font font;
	Text LastScore;
	Text CurrentPoints;
	Text pressEsc;
	Player player;
public:
	std::vector<Bullet> projectiles;
	std::vector<Enemy> enemies;
	Game(RenderWindow& window);
	void Draw(RenderWindow &window);
	void Update(RenderWindow &window);
	void GameOver(RenderWindow &window);
	void Play(RenderWindow &window);
	void SetFont(RenderWindow &window);

	void GameFactor();

	// Gety
	//RenderWindow GetWindow();
	float GetDificultyFactor();
	unsigned int GetDificultyFactorCounter();
	unsigned int GetTextEscCounter();
	Text GetLastScore();
	Text GetCurrentPoints();
	Text GetPressEsc();
	Player GetPlayer();
	//Sety

};

