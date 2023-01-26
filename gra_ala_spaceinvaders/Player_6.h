#pragma once
#include "Player.h"
#include "Bullet_6.h"
class Player_6 :
    public Player
{
public:
    Player_6(RenderWindow& window,bool playable);
    void Schoot(std::vector<Bullet*>& projectiles);
    void setTexture();
    static Texture ExhaustTexture;
    static Texture BodyTexture;
    void UseSkill(std::vector<Bullet*>& projectiles, RenderWindow& window);
    void ShowSkill(float i, RenderWindow& window, int PlayerNumer = 1);
    int GetWich();

};

