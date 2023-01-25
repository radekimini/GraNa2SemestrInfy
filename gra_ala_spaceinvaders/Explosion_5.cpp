#include "Explosion_5.h"

Texture Explosion_5::ExplosionTexture;
Explosion_5::Explosion_5(Vector2f vec) {
	Body.setTexture(ExplosionTexture);
	Body.setTextureRect(IntRect(0, 0, 128, 128));
	Body.setOrigin(Body.getGlobalBounds().width / 2, Body.getGlobalBounds().height / 2);
	Body.setPosition(vec);
}