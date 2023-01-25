#pragma once
#include "Boost.h"
using namespace sf;
class Boost_invincible
	: public Boost 
{
public:
	static Texture BodyTexture;
	Boost_invincible(Vector2f vec, float factor);
	std::string GetClassName();
	void AnimateBoost();
	void AnimationCounterer();
};

