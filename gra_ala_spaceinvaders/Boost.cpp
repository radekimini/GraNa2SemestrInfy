#include "Boost.h"

Boost::Boost(Vector2f vec,float factor,Texture tex) {
	//Body.setPosition(vec);
	//Body.setRadius(30.f);
	//Body.setFillColor(Color::White);
	//Body.setTexture(tex);
	SpawnDificultyFactor = factor;
}
Boost::Boost() {
	AnimationCounter = 0;
	AnimationFrame = 0;
}
void Boost::AnimateBoost() {

}
void Boost::AnimationCounterer() {
	
}

Sprite Boost::GetBody() { return Body; }
float Boost::GetSpawnDificultyFactor() { return SpawnDificultyFactor; }
std::string Boost::GetClassName() { return "BASIC"; }


