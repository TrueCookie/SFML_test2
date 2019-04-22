#include "Hare.h"

Hare::Hare(){
	type = "hare";

	texture.loadFromFile("images/hareSL.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 295, 355));

	sprite.setPosition(60, 90);
	sprite.setScale(0.2, 0.2);
}

Hare::~Hare(){}

int Hare::defMove() {
	energy -= 2;
	int randNum = defNum();
	if (randNum <= 2) {
		return 0;
	}else if(randNum >= 3 && randNum <= 4){
		return 90;
	}else if (randNum == 5) {
		return -120;
	}else if (randNum >= 6 && randNum <= 8) {
		return 10;
	}else if (randNum >= 9) {
		return -20;
	}
}

void Hare::moveToPoint(float x, float y, float time) {
	//if (getSprite().getPosition().x < x) {
		setCurrentFrame(0.005*time);
		if (getCurrentFrame() > 12) { setCurrentFrame(0); }
		getSprite().setTextureRect(sf::IntRect(295 * (int)getCurrentFrame(), 0, 295, 355));
		moveSprite(0.2*time, 0);
	//}
}