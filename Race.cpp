#include "Race.h"
#include "Hare.h"
#include "Turtle.h"
using namespace sf;

Race::Race(){
	background = new Object("background", "images/background.jpg", sf::IntRect(0, 0, 502, 402), 0, 0, 2.0, 2.0);
	racers = new Animal*[Init::racersNum];
	racers[0] = new Hare();
	racers[1] = new Turtle();
	snack = new Object*[10];
	for (int i = 0; i < 10; ++i) {
		snack[i] = new Object("snack", "images/oreo.png", sf::IntRect(0, 0, 400, 400), 100*i-20, 100, 0.1, 0.1);
	}
	finishLine = new Object("finishLine", "images/finishLine.png", sf::IntRect(88, 0, 10, 200), 1000, 0, 1.2, 1.2);
	finishFlag = false;
	showMap();
}

Race::~Race(){
	delete[] racers;
}

void Race::showMap() {
	window.draw(background->getSprite());
	for (int i = 0; i < 10; ++i) {
		window.draw(snack[i]->getSprite());
	}
	window.draw(finishLine->getSprite());
}

void Race::output() {
	window.create(sf::VideoMode(1024, 768), "Game", Style::Default);
	int i = 0;
	while (window.isOpen() && !finishFlag) {
		//TODO: add time to set game speed
		//TODO: add snacks
		//TODO: add finish check
		//TODO: add sleep
		time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 1400;

		checkClose();
		
		updatePositions();
		checkFinish();
		checkCollision();

		window.clear();
		showMap();
		showRacers();
		window.display();
	}
	window.clear();
	showMap();
	showRacers();
	showRacers();
	printWinner();
	window.display();
}

void Race::showRacers() {
	for (int i = 0; i < Init::racersNum; ++i) {
		window.draw(racers[i]->getSprite());
	}
}

void Race::checkClose() {
	Event event;
	while (window.pollEvent(event)) {
		if (event.type == Event::Closed)
			window.close();
	}
}

void Race::checkCollision() {
	for (int i = 0; i < Init::racersNum; ++i) {
		for (int j = 0; j < Init::racersNum; ++j) {
			if (racers[i]->getSprite().getGlobalBounds().intersects(racers[j]->getSprite().getGlobalBounds()) && racers[i]->getType() == "turtle") {
				racers[j]->bite();
				//TODO: add "OUCH" sign
			}
		}
	}
}

void Race::checkFinish() {
	for (int i = 0; i < Init::racersNum; ++i) {
		if (racers[i]->getSprite().getGlobalBounds().intersects(finishLine->getSprite().getGlobalBounds())) {
			finishFlag = true;
		}
	}
}

void Race::updatePositions() {
	for (int i = 0; i < Init::racersNum; ++i) {
		//static int delta;
		//different delta for each
		if (!racers[i]->isMovin()) {
			racers[i]->delta = racers[i]->defMove();
			racers[i]->setTargetPos(racers[i]->delta);
			racers[i]->setMoveFlag(true);
		}
		if ((racers[i]->delta > 0 && racers[i]->getSprite().getPosition().x < racers[i]->getTargetPos()) || (racers[i]->delta < 0 && racers[i]->getSprite().getPosition().x > racers[i]->getTargetPos())) {
			racers[i]->moveToPoint(racers[i]->delta, 0, time);
		}else {
			racers[i]->setMoveFlag(false);
		}
	}
}

void Race::printWinner() {
	
}