#pragma once
#include "Enemy.h"
class Enemy_normal :
    public Enemy
{
public:
	static Texture BodyTexture;
	static Texture ExhaustTexture;
	Enemy_normal(int pos, RenderWindow& window, int posY=0);
	std::string GetClassName();

};

