#include "Race.h"
#include "Hare.h"
#include "Turtle.h"
using namespace sf;

Race::Race(){
	racers = new Animal*[Init::racersNum];
	racers[0] = new Hare();
	racers[1] = new Turtle();
}

Race::~Race(){}

void Race::output() {
	window.create(sf::VideoMode(1024, 768), "Game", Style::Default);
	while (window.isOpen()) {
		//TODO: add time to set game speed
		//TODO: add snacks
		//TODO: add finish check
		time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;

		checkClose();
		
		updatePositions();
		checkClose();

		window.clear();
		showRacers();
		window.display();
	}
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

void Race::updatePositions() {
	for (int i = 0; i < Init::racersNum; ++i) {
		static int delta;
		//different delta for each
		if (!racers[i]->isMovin()) {
			delta = racers[i]->defMove();
			racers[i]->setTargetPos(delta);
			racers[i]->setMoveFlag(true);
		}
		if ((delta > 0 && racers[i]->getSprite().getPosition().x < racers[i]->getTargetPos()) || (delta < 0 && racers[i]->getSprite().getPosition().x > racers[i]->getTargetPos())) {
			racers[i]->moveToPoint(delta, 0, time);
		}else {
			racers[i]->setMoveFlag(false);
		}
	}
}