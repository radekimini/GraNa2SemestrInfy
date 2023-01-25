#include "Explosion.h"

Explosion::Explosion() {
	FrameCounter = 0;
}
void Explosion::Display() {
	if (FrameCounter <= 60) {
		if (FrameCounter % 6 == 0) {
			Body.setTextureRect(IntRect(FrameCounter / 6*128, 0, 128, 128));
		}
	}
	FrameCounter++;
}
int Explosion::GetFrameCounter() { return FrameCounter; }
Sprite Explosion::GetBody() { return Body; }
