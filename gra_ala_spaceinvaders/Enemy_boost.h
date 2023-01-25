#pragma once
#include "Enemy.h"
class Enemy_boost :
    public Enemy
{
public:
    static Texture BodyTexture;
    static Texture ExhaustTexture;
    Enemy_boost(int pos, RenderWindow& window);
    std::string GetClassName();
};

