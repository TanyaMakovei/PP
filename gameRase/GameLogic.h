#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "Helper.h"
#include "Field.h"
#include "Car.h"
#include "GamePrinter.h"

class GameLogic
{
public:
	GameLogic();
	~GameLogic();

	void pause();
	void countTime();
	void generateField();
	void generateCar();
	void increaseSpeed();
	void decreaseSpeed();
	void printGame();
	void endGame();
	void checkHit();
	void shiftLeft();
	void shiftRight();
	void checkPressKey();
	void countPoints();
private:
	int speed_;
	bool isGameOver;
	Field field1_;
	Car car1_;
	GamePrinter gamePrinter1_;
	int points_;
	float time_;
	int distance_;
	int distance2_;

};


#endif GAMELOGIC_H
