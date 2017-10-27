#pragma once
#include "Helper.h"

class GameLogic
{
public:
	GameLogic();
	~GameLogic();

	void pause();
	void countTime();
	void printField();
	void printCar();
	void increaseSpeed();
	void decreaseSpeed();
	char drawElement(int x, int y);
	void printGame();
	void endGame();
	void printStatus();
	void checkHit();
	void shiftLeft();
	void shiftRight();
	void printOldField();
private:
	static char Buf[FIELD_LENGHT][FIELD_WIDTH];
	int speed;
	bool isPause = false;
	Field field1;
	Car car1;
	int time;
	int distance;
	int distance2;
	
};

