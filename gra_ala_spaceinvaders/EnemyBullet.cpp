#include "EnemyBullet.h"

Texture EnemyBullet::BodyTexture;

EnemyBullet::EnemyBullet(sf::Vector2f pos){
	AnimationFrameCouner = 0;
	Body.setTexture(BodyTexture);
	Body.setTextureRect(IntRect(0, 0, 25, 20));
	Body.setScale(2.f, 2.f);
	//Body.setOrigin(Body.getGlobalBounds().width/2, Body.getGlobalBounds().height / 2);
	Body.setRotation(180);
	Body.setPosition(pos);

}
void EnemyBullet::EnemyMovement(float factor, std::vector<Player*>& PlayablePlayers, float time, std::vector<Enemy*>& enemies){
	Body.move((-10 - ((factor - 1) * time)), 0);
}
void EnemyBullet::ExhaustAnimate(int ExhaustCounter){
	if (AnimationFrameCouner <= 32) {
		if (AnimationFrameCouner == 8) {
			Body.setTextureRect(IntRect(24, 0, 25, 20));
		}
		if (AnimationFrameCouner == 16) {
			Body.setTextureRect(IntRect(49, 0, 25, 20));
		}
		if (AnimationFrameCouner == 24) {
			Body.setTextureRect(IntRect(74, 0, 25, 20));
		}
		if (AnimationFrameCouner == 32) {
			Body.setTextureRect(IntRect(99, 0, 25, 20));
		}
		AnimationFrameCouner++;
	}
}
std::string EnemyBullet::GetClassName(){
	return "BULLET";
}