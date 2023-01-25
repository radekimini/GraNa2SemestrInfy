#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace sf;
class Parts
{
protected:
	Sprite parts[6];
	float SpawnTimeFactor;
public:
	Parts();
	Sprite GetPart(int i);
	void PartsMove(float MoveFactor);
	void PartsDraw(RenderWindow& window);
	bool PartsDissaper(float CurrentTimeFactor);
};

