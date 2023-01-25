#include "Parts_boost.h"
Texture Parts_boost::BodyTexture;

Parts_boost::Parts_boost(int x, int y, float TimeFactor) {
	 SpawnTimeFactor = TimeFactor;
	 for (int i = 0; i < 6; i++) {
		 parts[i].setTexture(BodyTexture);
		 parts[i].setTextureRect(IntRect(i * 50, 0, 50, 50));
		 parts[i].setOrigin(25, 25);
	 }
	 parts[0].setPosition(x, y - 8);
	 parts[1].setPosition(x + 26, y - 8);
	 parts[2].setPosition(x + 26, y - 8);
	 parts[3].setPosition(x - 8, y - 9);
	 parts[4].setPosition(x + 23, y - 8);
	 parts[5].setPosition(x - 17, y - 9);
 }