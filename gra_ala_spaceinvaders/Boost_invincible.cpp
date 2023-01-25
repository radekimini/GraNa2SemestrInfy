#include "Boost_invincible.h"

Texture Boost_invincible::BodyTexture;

Boost_invincible::Boost_invincible(Vector2f vec, float factor) {
	Body.setPosition(vec);
	//Body.setRadius(20.f);
	//Body.setFillColor(Color::Cyan);
	Body.setTexture(BodyTexture);
	Body.setScale(Vector2f(0.3f, 0.3f));
	Body.setTextureRect(IntRect(0, 0, 200, 200));
	SpawnDificultyFactor = factor;
}
void Boost_invincible::AnimateBoost() {
	Body.setTextureRect(IntRect(AnimationFrame *200, 0, 200, 200));
	//std::cout << (int)Body.getPosition().x / 20 % 76 << std::endl;
}
void Boost_invincible::AnimationCounterer(){
	if (AnimationCounter >= 20) {
		AnimationCounter = 0;
		if (AnimationFrame == 76) {
			AnimationFrame = 0;
		}
		else {
			AnimationFrame++;
		}
	}
	else {
		AnimationCounter++;
	}

}
std::string Boost_invincible::GetClassName() { return "INVINCIBLE"; }
