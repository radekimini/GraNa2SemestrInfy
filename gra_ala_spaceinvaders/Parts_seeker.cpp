#include "Parts_seeker.h"
Texture Parts_seeker::BodyTexture;

Parts_seeker::Parts_seeker(int x,int y, float TimeFactor) {
	SpawnTimeFactor = TimeFactor;
	for (int i = 0; i < 6; i++) {
		parts[i].setTexture(BodyTexture);
		parts[i].setTextureRect(IntRect(i * 50, 0, 50, 50));
		parts[i].setOrigin(25, 25);
	}
	parts[0].setPosition(x + 46, y - 6);
	parts[1].setPosition(x + 22, y - 5);
	parts[2].setPosition(x - 6, y - 4);
	parts[3].setPosition(x + 46, y - 5);
	parts[4].setPosition(x + 1, y - 7);
	parts[5].setPosition(x +19, y - 8);
}