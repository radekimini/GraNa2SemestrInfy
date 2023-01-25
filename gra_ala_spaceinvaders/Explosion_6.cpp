#include "Explosion_6.h"

Texture Explosion_6::ExplosionTexture;

Explosion_6::Explosion_6(Vector2f vec) {
	Body.setTexture(ExplosionTexture);
	Body.setTextureRect(IntRect(0, 0, 128, 128));
	Body.setOrigin(Body.getGlobalBounds().width / 2, Body.getGlobalBounds().height / 2);
	Body.setPosition(vec);
}