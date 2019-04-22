#pragma once
#include "Init.h"
#include "Animal.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class Race{
private:
	Animal** racers;
	RenderWindow window;
	Clock clock;
	float time;
	
public:
	Race();
	~Race();

	void showRacers();
	void output();
	void checkClose();
	void checkCollision();
	void updatePositions();
};