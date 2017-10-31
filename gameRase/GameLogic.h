#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "Helper.h"
#include "Field.h"
#include "Car.h"

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
	void printStatus() const;
	void checkHit();
	void shiftLeft();
	void shiftRight();
	void printOldField();
private:
	static char Buf[FIELD_LENGHT][FIELD_WIDTH];
	int speed_;
	bool isGameOver;
	bool isPause_ = false;
	Field field1_;
	Car car1_;
	int time_;
	int distance_;
	int distance2_;

};


#endif GAMELOGIC_H
