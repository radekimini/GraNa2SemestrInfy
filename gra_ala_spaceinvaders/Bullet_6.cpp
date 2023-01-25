#include "Bullet_6.h"
Texture Bullet_6::BodyTexture;

Bullet_6::Bullet_6(Vector2f vect) {
	Body.setTexture(BodyTexture);
	Body.setTextureRect(IntRect(0, 0, 58, 12));
	Body.setOrigin(Vector2f(40.f, 6.f));
	Body.setScale(2.f, 2.f);
	Body.setPosition(vect);
}
int Bullet_6::BulletType() { return 6; }