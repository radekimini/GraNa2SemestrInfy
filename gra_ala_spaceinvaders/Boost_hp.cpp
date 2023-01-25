#include "Boost_hp.h"

Texture Boost_hp::BodyTexture;

Boost_hp::Boost_hp(Vector2f vec, float factor) {
	Body.setPosition(vec);
	Body.setTexture(BodyTexture);
	Body.setScale(Vector2f(0.15f, 0.15f));
	SpawnDificultyFactor = factor;
}
//void Boost_hp::AnimateBoost() {
//	Body.setTextureRect(IntRect(AnimationFrame * 200, 0, 200, 200));
//	//std::cout << (int)Body.getPosition().x / 20 % 76 << std::endl;
//}
//void Boost_hp::AnimationCounterer() {
//	if (AnimationCounter >= 20) {
//		AnimationCounter = 0;
//		if (AnimationFrame == 76) {
//			AnimationFrame = 0;
//		}
//		else {
//			AnimationFrame++;
//		}
//	}
//	else {
//		AnimationCounter++;
//	}
//
//}

std::string Boost_hp::GetClassName() { return "HP"; }
