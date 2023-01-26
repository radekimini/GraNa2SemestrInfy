#pragma once
#include "Enemy.h"
class Enemy_seeker :
    public Enemy
{
protected:
    int SeekingWhom;
public:
    static Texture BodyTexture;
    static Texture ExhaustTexture;
    Enemy_seeker(int pos, RenderWindow& window,int _SeekingWhom = 0);
    std::string GetClassName();
    void EnemyMovement(float factor, std::vector<Player*>& PlayablePlayers);
    void ExhaustAnimate(int ExhaustCounter);
    void SetSeekingWhom(int _SeekingWhom);

};

