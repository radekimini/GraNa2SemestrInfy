#include "Enemy_seeker.h"

Texture Enemy_seeker::BodyTexture;
Texture Enemy_seeker::ExhaustTexture;

Enemy_seeker::Enemy_seeker(int pos, RenderWindow& window, int _SeekingWhom) {
	SeekingWhom = _SeekingWhom;
	Body.setTexture(BodyTexture);
	Body.setTextureRect(IntRect(0, 0, 118, 39));
	Body.setScale(1.4f, 1.4f);
	Body.setOrigin(0, Body.getGlobalBounds().height / 2);
	Body.setPosition(Vector2f(window.getSize().x, pos));
	SpawnTimer = 0;
}
std::string Enemy_seeker::GetClassName() {
	return "SEEKER";
}
void Enemy_seeker::EnemyMovement(float factor, std::vector<Player*>& Players,float time, std::vector<Enemy*>& enemies) {
	Body.move((-6 - ((factor - 1) * time)), ((Players[SeekingWhom]->GetShip().getPosition().y + (Players[SeekingWhom]->GetShip().getGlobalBounds().height / 2)) - Body.getPosition().y) / (30 - (factor * (time/3))));
}
void Enemy_seeker::ExhaustAnimate(int ExhaustCounter) {
	if (ExhaustCounter == 10) {
		Body.setTextureRect(IntRect(0, 0, 118, 39));
	}
	if (ExhaustCounter == 20) {
		Body.setTextureRect(IntRect(118, 0, 118, 39));
	}
	if (ExhaustCounter == 30) {
		Body.setTextureRect(IntRect(236, 0, 118, 39));
	}
	if (ExhaustCounter == 40) {
		Body.setTextureRect(IntRect(354, 0, 118, 39));
	}
}
void Enemy_seeker::SetSeekingWhom(int _SeekingWhom) {
	SeekingWhom = _SeekingWhom;
}

