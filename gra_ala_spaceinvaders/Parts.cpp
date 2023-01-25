#include "Parts.h"

Parts::Parts() {}
void Parts::PartsMove(float MoveFactor) {
	for (int i = 0; i < 6; i++) {
		parts[i].rotate((MoveFactor + 2) * i + 10);
		parts[i].move(Vector2f((1 + i * 1.5f) + (MoveFactor * 5), (1 + i * MoveFactor) + (i * 2.5)));
	}
}
void Parts::PartsDraw(RenderWindow& window) {
	for(int i = 0; i < 6; i++) {
		window.draw(parts[i]);
	}
}
Sprite Parts::GetPart(int i) { return parts[i]; }
bool Parts::PartsDissaper(float CurrentTimeFactor) {
	if (CurrentTimeFactor - SpawnTimeFactor >= 0.03) { return true; }
	else { return false; }
}