#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>
#include "Bullet.h"
#include "Bullet_5.h"
#include "Bullet_6.h"
#include "Enemy.h"
#include "Player.h"
#include "Player_5.h"
#include "Player_6.h"
#include "Enemy_boost.h"
#include "Enemy_normal.h"
#include "Enemy_seeker.h"
#include "Boost.h"
#include "Boost_invincible.h"
#include "Boost_hp.h"
#include "Boost_Skill.h"
#include "Explosion.h"
#include "Explosion_5.h"
#include "Explosion_6.h"
#include "Parts.h"
#include "Parts_seeker.h"
#include "Parts_boost.h"
#include "Parts_normal.h"

using namespace sf;
class Game
{
protected:

	std::vector<Player*>PlayablePlayers;
	Player* CharacterPickerPlayers[2];

	bool CharacterPicked;
	bool secondPlayerGotKilled;
	int NumberOfPlayers = 0;

	
	Font font;
	std::vector<Text> CurrentPoints;
	Text OnePlayer;
	Text TwoPlayer;
	Text LastScore;
	Text ChoicePlayer;
	Text pressEsc;
	Text PlayedTime;

	Texture BackGroundGalaxyTexture;
	Sprite BackGroundGalaxyImage;
	Texture BackGroundTexture;
	Sprite BackGroundImage;
	Texture Planet1BackGroundTexture;
	Sprite Planet1BackGroundImage;


public:
	std::vector<Parts*> enemiesParts;
	std::vector<Bullet*> projectiles;
	std::vector<Explosion*> explosions;
	std::vector<Enemy*> enemies;
	std::vector<Boost*> boosts;
	Game(RenderWindow& window);
	void Draw(RenderWindow &window);
	void Update(RenderWindow &window);
	void GameOver(RenderWindow &window);
	void Play(RenderWindow &window);
	void SetFont(RenderWindow &window);

	void GameFactor();
	void DrawCharacterPicker(RenderWindow& window);
	void UpdateCharacterPicker(RenderWindow& window);
	void EnemySpawner(RenderWindow& window);
	void ExhaustCount();

	//Countery
	float TimeFactor;
	unsigned int TimeFactorCounter;
	float DificultyFactor;
	unsigned int DificultyFactorCounter;
	unsigned int textEscCounter;
	int ExhaustCounter;
	unsigned long long FramesCounter;
	unsigned int GalaxyBackGroundCounter;
	unsigned int GalaxyBackGroundFrame;
	 
	 
	// Gety
	//RenderWindow GetWindow();
	float GetDificultyFactor();
	unsigned int GetDificultyFactorCounter();
	unsigned int GetTextEscCounter();
	Text GetLastScore();
	std::vector<Text> GetCurrentPoints();
	Text GetPressEsc();
	std::vector<Player*> GetPlayer();
	//Sety
	void CurrentPointsFontSet(RenderWindow &window);
};

