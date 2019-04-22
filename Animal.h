#pragma once
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
class Animal{
protected:
	Texture texture;
	Sprite sprite;
	float currentFrame;
	int energy;
	std::string type;
	bool sleepFlag;
	int targetPos;
	bool moveFlag;
	//int delta;

public:
	Animal();
	~Animal();
	void setTargetPos(int val);
	int getTargetPos();
	bool isMovin();
	void setMoveFlag(bool val);
	int defNum();
	virtual int defMove() = 0;
	void setEnergy(int val);
	int getEnergy();
	bool isSleep();
	void getUp();
	std::string getType();
	bool isOut();
	void eatSnack();
	void bite();
	Sprite getSprite();
	void moveSprite(float x, float y);
	void setCurrentFrame(float num);
	float getCurrentFrame();
	virtual void moveToPoint(float x, float y, float time) = 0;
};