#pragma once
#include "Enemy.h"
class EnemyBullet :
	public Enemy
{
protected:
	int AnimationFrameCouner;
public:
	EnemyBullet(sf::Vector2f pos);
	static sf::Texture BodyTexture;
	void EnemyMovement(float factor, std::vector<Player*>& PlayablePlayers, float time, std::vector<Enemy*> &enemies);
	void ExhaustAnimate(int ExhaustCounter);
	std::string GetClassName();
};

