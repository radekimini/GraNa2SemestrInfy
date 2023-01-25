#pragma once
#include "Bullet.h"
class Bullet_6 :
    public Bullet
{
public:
    static Texture BodyTexture;
    Bullet_6(Vector2f vect);
    int BulletType();
};

