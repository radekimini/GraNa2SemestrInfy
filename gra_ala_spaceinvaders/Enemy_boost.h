#pragma once
#include "Enemy.h"
class Enemy_boost :
    public Enemy
{
public:
    static Texture BodyTexture;
    static Texture ExhaustTexture;
    Enemy_boost(int pos, RenderWindow& window);
    void EnemyMovement(float factor, std::vector<Player*>& PlayablePlayers, float time, std::vector<Enemy*>& enemies);
    std::string GetClassName();
    void Schoot();
};

