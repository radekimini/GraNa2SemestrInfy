#include "Enemy_normal.h"

Texture Enemy_normal::BodyTexture;
Texture Enemy_normal::ExhaustTexture;

Enemy_normal::Enemy_normal(int posY, RenderWindow& window, int posX) {
	Body.setTexture(BodyTexture);
	Body.setScale(1.6f, 1.6f);
	Body.setOrigin(Body.getGlobalBounds().width / 2, Body.getGlobalBounds().height / 2);
	Exhaust.setTexture(ExhaustTexture);
	Exhaust.setTextureRect(IntRect(0, 0, 32, 32));
	Exhaust.setScale(1.0f, 1.0f);
	if (posX == 0) {
	Body.setPosition(Vector2f(window.getSize().x, posY));
	Exhaust.setPosition(Vector2f(window.getSize().x+20, posY-28));
	}
	else {
		Body.setPosition(Vector2f(posX, posY));
		Exhaust.setPosition(Vector2f(posX + 20, posY - 28));
	}
	SpawnTimer = 0;
}

std::string Enemy_normal::GetClassName() {
	return "NORMAL";
}