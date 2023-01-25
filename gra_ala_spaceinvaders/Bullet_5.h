#pragma once
#include "Bullet.h"
class Bullet_5 :
    public Bullet
{
public:
	static Texture BodyTexture;
	Bullet_5(Vector2f vect);
	int BulletType();
};

