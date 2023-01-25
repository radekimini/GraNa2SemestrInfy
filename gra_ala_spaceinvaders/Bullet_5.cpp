#include "Bullet_5.h"
Texture Bullet_5::BodyTexture;

Bullet_5::Bullet_5(Vector2f vect) {
	Body.setTexture(BodyTexture);
	Body.setTextureRect(IntRect(0, 0, 58, 12));
	Body.setOrigin(Vector2f(40.f, 6.f));
	Body.setScale(2.f, 2.f);
	Body.setPosition(vect);
}
int Bullet_5::BulletType() { return 5; }