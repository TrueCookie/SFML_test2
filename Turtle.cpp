#include "Turtle.h"

Turtle::Turtle(){
	energy = 20;
	type = "turtle";
	
	texture.loadFromFile("images/turtleSL.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 350, 237));

	sprite.setPosition(60, 190);
	sprite.setScale(0.2, 0.2);
}

Turtle::~Turtle(){}

int Turtle::defMove() {
	energy -= 2;
	int randNum = defNum();
	if (randNum >= 1 && randNum <= 5) {
		return 30;
	}
	else if (randNum >= 6 && randNum <= 7) {
		return -90;
	}
	else{
		return 10;
	}
}

void Turtle::moveToPoint(float x, float y, float time) {
	//if (getSprite().getPosition().x < x) {
		setCurrentFrame(0.005*time);
		if (getCurrentFrame() > 1) { setCurrentFrame(0); }
		getSprite().setTextureRect(sf::IntRect(350 * (int)getCurrentFrame(), 0, 350, 237));
		moveSprite(0.2*time, 0);
	//}
}