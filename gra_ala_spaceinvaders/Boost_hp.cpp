#include "Boost_hp.h"

Texture Boost_hp::BodyTexture;

Boost_hp::Boost_hp(Vector2f vec, float factor) {
	Body.setPosition(vec);
	Body.setTexture(BodyTexture);
	Body.setScale(Vector2f(0.15f, 0.15f));
	SpawnDificultyFactor = factor;
}
std::string Boost_hp::GetClassName() { return "HP"; }
