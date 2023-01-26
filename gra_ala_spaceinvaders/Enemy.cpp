#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace sf;

int Enemy::SpawnTimer = 0;
Enemy::Enemy(int pos, RenderWindow& window) {
	SpawnTimer = 0;
	Body.setPosition(Vector2f(window.getSize().x, pos));
}
Enemy::~Enemy() {
	
}
Enemy::Enemy() {
}
Sprite Enemy::GetBody() {
	return Body;
}
Sprite Enemy::GetExhaust() {
	return Exhaust;
}
bool Enemy::EnemyAtEnd(RenderWindow& window) {
	if (Body.getPosition().x <= 0) {
		return true;
	}
	else {
		return false;
	}
}
void Enemy::EnemyMovement(float factor, std::vector<Player*>& PlayablePlayers) {
	Body.move(-6 - ((factor-1) * 10), 0);
	Exhaust.move(-6 - ((factor-1) * 10), 0);
}
std::string Enemy::GetClassName() {
	return "BASIC";
}
void Enemy::ExhaustAnimate(int ExhaustCounter) {
	if (ExhaustCounter == 10) {
		Exhaust.setTextureRect(IntRect(32, 0, 32, 32));
	}
	if (ExhaustCounter == 20) {
		Exhaust.setTextureRect(IntRect(64, 0, 32, 32));
	}
	if (ExhaustCounter == 30) {
		Exhaust.setTextureRect(IntRect(96, 0, 32, 32));
	}
	if (ExhaustCounter == 40) {
		Exhaust.setTextureRect(IntRect(0, 0, 32, 32));
	}
}
void Enemy::SetSeekingWhom(int _SeekingWhom) {}
