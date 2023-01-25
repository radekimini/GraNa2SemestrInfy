#pragma once
#include <iostream>
#include "Player.h"
#include "Bullet.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace sf;

class Player
{
protected:
	int hp;
	int SkillUsageLeft;
	unsigned int Points;
	float movementX;
	float movementY;
	float MovementFactor;
	bool Invincible;
	float DificultyFactorWhenInvinciblility;
	float InvincibilityTime;
	Sprite ship;
	Sprite Exhaust;
public:
	Player();
	virtual void PlayerMovement(RenderWindow &window);
	virtual void Schoot(std::vector<Bullet*>& projectiles);
	virtual void ReciveDamage();
	virtual void ShowHp(float i, RenderWindow& window);
	virtual void ShowSkill(float i, RenderWindow& window);
	virtual void GetKill(float factor);
	virtual void TakePoints(unsigned int ptk);
	virtual unsigned int GetPoints();
	virtual Sprite GetShip();
	virtual Sprite GetExhaust();
	virtual void SetMovementFactor(float factor);
	virtual int Gethp();
	virtual int GetSkillUsageLeft();
	virtual void addhp();
	virtual void AddSkillUsage();
	virtual bool IsInvincible();
	virtual void MakeInvincibleFor(float sec, float factor);
	virtual void InvincibilityEndCheck(float factor);
	virtual void setTexture();
	static Texture HeartTexture;
	virtual void UseSkill(std::vector<Bullet*>& projectiles, RenderWindow& window);
	virtual void ExhaustAnimation(int ExhaustCounter);
};

