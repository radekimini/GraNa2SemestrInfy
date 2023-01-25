#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;

#pragma once
class Bullet{
protected:	
	Sprite Body;
	int AnimationFrameCouner;
public:
	Bullet();
	virtual Sprite GetBody();
	virtual void BulletMove();
	virtual bool BulletDestroy(RenderWindow& window);
	virtual void AnimateBoolet();
	virtual int BulletType();
};

