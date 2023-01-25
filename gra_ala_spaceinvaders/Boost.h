#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#pragma once
using namespace sf;
class Boost
{
protected:
	float SpawnDificultyFactor;
	Sprite Body;
	int AnimationCounter;
	int AnimationFrame;
	//Sprite Body;
public:
	Boost(Vector2f vec,float factor,Texture tex);
	Boost();
	virtual Sprite GetBody();
	virtual float GetSpawnDificultyFactor();
	virtual std::string GetClassName();
	virtual void AnimateBoost();
	virtual void AnimationCounterer();

};

