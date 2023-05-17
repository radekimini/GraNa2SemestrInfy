#include <iostream>
#include "Enemy_boost.h"
#include "EnemyBullet.h"

Texture Enemy_boost::BodyTexture;
Texture Enemy_boost::ExhaustTexture;

Enemy_boost::Enemy_boost(int pos, RenderWindow& window) {
	Body.setTexture(BodyTexture);
	Body.setScale(1.5f, 1.5f);
	Body.setOrigin(Body.getGlobalBounds().width / 2, Body.getGlobalBounds().height / 2);
	Body.setPosition(Vector2f(window.getSize().x, pos));
	Exhaust.setTexture(ExhaustTexture);
	Exhaust.setTextureRect(IntRect(0, 0, 32, 32));
	Exhaust.setPosition(Vector2f(window.getSize().x + 25, pos - 30));
	Exhaust.setScale(1.0f, 1.0f);
	SpawnTimer = 0;
}
std::string Enemy_boost::GetClassName() {
	return "BOOST";
}
void Enemy_boost::EnemyMovement(float factor, std::vector<Player*>& PlayablePlayers, float time, std::vector<Enemy*>& enemies) {
	Body.move((-6 - ((factor - 1) * time)), 0);
	Exhaust.move((-6 - ((factor - 1) * time)), 0);
	if (rand() % 201 == 1) {
		enemies.push_back(new EnemyBullet(sf::Vector2f(Body.getGlobalBounds().left,Body.getPosition().y + 5)));
		//std::cout << " BULLET " << std::endl;
	}
}