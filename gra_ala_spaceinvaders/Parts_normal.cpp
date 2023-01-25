#include "Parts_normal.h"
Texture Parts_normal::BodyTexture;

Parts_normal::Parts_normal(int x, int y, float TimeFactor) {
	SpawnTimeFactor = TimeFactor;
	for (int i = 0; i < 6; i++) {
		parts[i].setTexture(BodyTexture);
		parts[i].setTextureRect(IntRect(i * 50, 0, 50, 50));
		parts[i].setOrigin(25, 25);
	}
	parts[0].setPosition(x + 3, y - 14);
	parts[1].setPosition(x + 26, y - 9);
	parts[2].setPosition(x - 15, y - 10);
	parts[3].setPosition(x, y - 9);
	parts[4].setPosition(0, 0);
	parts[5].setPosition(0, 0);
}