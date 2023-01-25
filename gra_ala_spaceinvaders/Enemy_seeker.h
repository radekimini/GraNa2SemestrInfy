#pragma once
#include "Enemy.h"
class Enemy_seeker :
    public Enemy
{
    public:
        static Texture BodyTexture;
        static Texture ExhaustTexture;
        Enemy_seeker(int pos, RenderWindow& window);
        std::string GetClassName();
        void EnemyMovement(float factor,Player player);
        void ExhaustAnimate(int ExhaustCounter);
};

