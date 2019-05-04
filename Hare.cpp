#include "Hare.h"
#include <iostream>

Hare::Hare(){
	type = "hare";

	texture.loadFromFile("images/hareSL.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 295, 355));

	sprite.setPosition(20, 90);
	sprite.setScale(0.2, 0.2);
}

Hare::~Hare(){}

int Hare::defMove() {
	energy -= 2;
	int randNum = defNum();
	if (randNum <= 2) {
		return 0;
	}else if(randNum >= 3 && randNum <= 4){
		return 9 * mult;
	}else if (randNum == 5) {
		return -12 * mult;
	}else if (randNum >= 6 && randNum <= 8) {
		return 1 * mult;
	}else if (randNum >= 9) {
		return -2 * mult;
	}
}

void Hare::moveToPoint(float x, float y, float time) {	//why sprite disappears
		currentFrame += 0.005*time;
		if (currentFrame > 12) { currentFrame = 0; }
		sprite.setTextureRect(sf::IntRect(295 * (int)getCurrentFrame(), 0, 295, 355));
		moveSprite(0.2*time, 0);
}