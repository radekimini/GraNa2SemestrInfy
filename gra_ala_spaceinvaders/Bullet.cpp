#include "Bullet.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace sf;

Bullet::Bullet() {
	AnimationFrameCouner = 0;
}
Sprite Bullet::GetBody() { return Body; }
void Bullet::BulletMove() {
	Body.move(9, 0);
}
bool Bullet::BulletDestroy(RenderWindow& window) {
	if (Body.getPosition().x > window.getSize().x) {
		return true;
	}
	else {
		return false;
	}
}
void Bullet::AnimateBoolet() {
	if (AnimationFrameCouner <= 32) {
		if (AnimationFrameCouner == 8) {
			Body.setTextureRect(IntRect(58, 0, 58, 12));
		}
		if (AnimationFrameCouner == 16) {
			Body.setTextureRect(IntRect(116, 0, 58, 12));
		}
		if (AnimationFrameCouner == 24) {
			Body.setTextureRect(IntRect(174, 0, 58, 12));
		}
		if (AnimationFrameCouner == 32) {
			Body.setTextureRect(IntRect(232, 0, 58, 12));
		}
		AnimationFrameCouner++;
	}
}
int Bullet::BulletType() { return 0; }
