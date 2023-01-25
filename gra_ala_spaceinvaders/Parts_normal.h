#pragma once
#include "Parts.h"
class Parts_normal :
    public Parts
{
public:
    static Texture BodyTexture;
    Parts_normal(int x, int y,float TimeFactor);
};

