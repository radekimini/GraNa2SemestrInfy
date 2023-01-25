#include "Boost_Skill.h"
#include "Bullet_5.h"
#include "Bullet_6.h"

Boost_Skill::Boost_Skill(Vector2f vec, float factor,int which) {
	if (which == 5) {
	Body.setTexture(Bullet_5::BodyTexture);
	}
	if (which == 6) {
	Body.setTexture(Bullet_6::BodyTexture);
	}

	Body.setTextureRect(IntRect(116, 0, 58, 12));
	Body.setScale(2.f,2.f);
	Body.rotate(-10);
	Body.setPosition(vec);
	SpawnDificultyFactor = factor;
}
std::string Boost_Skill::GetClassName() { return "SKILL"; }
