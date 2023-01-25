#pragma once
#include "Boost.h"
class Boost_Skill :
    public Boost
{
public:
	Boost_Skill(Vector2f vec, float factor,int which);
	std::string GetClassName();
};

