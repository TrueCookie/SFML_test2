#pragma once
#include "Init.h"
#include "Animal.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class Race{
private:
	Object* background;
	Animal** racers;
	RenderWindow window;
	Clock clock;
	float time;
	Object** snack;
	Object* finishLine;
public:
	bool finishFlag;
	Race();
	~Race();

	void showMap();
	void showRacers();
	void output();
	void checkClose();
	void checkCollision();
	void checkFinish();
	void updatePositions();
	void printWinner();
};