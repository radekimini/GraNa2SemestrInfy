#pragma once
#include "Parts.h"
class Parts_seeker :
    public Parts
{
public:
    static Texture BodyTexture;
    Parts_seeker(int x, int y, float TimeFactor);
};

