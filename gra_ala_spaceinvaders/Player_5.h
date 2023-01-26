#pragma once
#include "Player.h"
#include "Bullet_5.h"

class Player_5 :
    public Player
{
public:
    Player_5(RenderWindow& window, bool playable);
    void Schoot(std::vector<Bullet*>& projectiles);
    void setTexture();
    static Texture ExhaustTexture;
    static Texture BodyTexture;
    void UseSkill(std::vector<Bullet*>& projectiles, RenderWindow& window);
    void ShowSkill(float i, RenderWindow& window, int PlayerNumer = 1);
    int GetWich();
};

