#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Player.h"
using namespace sf;
#pragma once
class Enemy{
protected:
	Sprite Body;
	Sprite Exhaust;
public:
	Enemy(int pos, RenderWindow& window);
	Enemy();
	~Enemy();
	static int SpawnTimer;
	virtual bool EnemyAtEnd(RenderWindow& window);
	virtual void EnemyMovement(float factor,Player player);
	virtual void ExhaustAnimate(int ExhaustCounter);
	virtual Sprite GetBody();
	virtual Sprite GetExhaust();
	virtual std::string GetClassName();
};

