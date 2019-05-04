#include "Turtle.h"

Turtle::Turtle(){
	energy = 20;
	type = "turtle";
	
	texture.loadFromFile("images/turtleSL.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 350, 237));

	sprite.setPosition(20, 190);
	sprite.setScale(0.2, 0.2);
}

Turtle::~Turtle(){}

int Turtle::defMove() {
	energy -= 2;
	int randNum = defNum();
	if (randNum >= 1 && randNum <= 5) {
		return 3 * mult;
	}
	else if (randNum >= 6 && randNum <= 7) {
		return -9 * mult;
	}
	else{
		return 1 * mult;
	}
}

void Turtle::moveToPoint(float x, float y, float time) {
		currentFrame += 0.005*time;
		if (currentFrame > 1) { currentFrame = 0; }
		sprite.setTextureRect(sf::IntRect(350 * (int)getCurrentFrame(), 0, 350, 237));
		moveSprite(0.2*time, 0);
}