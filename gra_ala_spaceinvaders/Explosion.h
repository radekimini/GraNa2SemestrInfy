#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
using namespace sf;
class Explosion
{
protected:
	Sprite Body;
	int FrameCounter;
public:
	Explosion();
	void Display();
	int GetFrameCounter();
	Sprite GetBody();
};

