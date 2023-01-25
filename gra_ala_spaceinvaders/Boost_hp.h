#pragma once
#include "Boost.h"
class Boost_hp :
    public Boost
{
public:
	static Texture BodyTexture;
	Boost_hp(Vector2f vec, float factor);
	std::string GetClassName();
	//void AnimateBoost();
	//void AnimationCounterer();

};

