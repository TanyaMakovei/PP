#include "GameLogic.h"
#include "Windows.h"




GameLogic::GameLogic()
{
	isGameOver = false;
	distance_ = START_DISTANCE;
	distance2_ = START_DISTANCE2;
	speed_ = START_SPEED;
	time_ = START_TIME;
	Field field1_;
	Car car1_;
	GamePrinter gamePrinter1_;
}


GameLogic::~GameLogic()
{
}


void GameLogic::pause()
{
	
		countTime();
		countPoints();
		system("cls");
		printf("PAUSE\n");
		gamePrinter1_.printStatus(time_, distance_,points_);
		do
		{  
		} while (!GetAsyncKeyState(VK_RETURN));
		system("cls");
		return;
	
}

void GameLogic::countTime()
{
	int deltaDist = (distance_ - distance2_) ;
	time_ += float(deltaDist) / float(speed_);
	distance2_ = distance_;
}

void GameLogic::generateField()
{

	field1_.generateField();
	distance_++;
	gamePrinter1_.printOldField(field1_);
	checkHit();
}

void GameLogic::generateCar()
{
	int y = car1_.getCarPos();
	gamePrinter1_.printCar(y);
}


void GameLogic::increaseSpeed()
{
	if (MAX_SPEED > speed_)
	{
		countTime();
		speed_++;
	}
}

void GameLogic::decreaseSpeed()
{
	if (MIN_SPEED < speed_)
	{
		countTime();
		speed_--;
	}
}


void GameLogic::printGame()
{
	while (!isGameOver)
	{
		generateField();
		generateCar();
		gamePrinter1_.printGame();
		checkPressKey();
		concurrency::wait(WAIT_TIME - speed_*COEFFICIENT);

	}

}

void GameLogic::endGame()
{
	countPoints();
	isGameOver = true;
	system("cls");
	printf("GAME OVER\n");
	gamePrinter1_.printStatus(time_, distance_,points_);
	do
	{
	} while (!GetAsyncKeyState(VK_ESCAPE));
	
}

void GameLogic::checkHit()
{
	if (TREE == field1_.getPoint(START_X, car1_.getCarPos()))
	{
		countTime();
		endGame();
	}
}

void GameLogic::shiftLeft()
{
	car1_.shiftLeft();
	gamePrinter1_.printOldField(field1_);
	generateCar();
	checkHit();

}

void GameLogic::shiftRight()
{
	car1_.shiftRight();
	gamePrinter1_.printOldField(field1_);
	generateCar();
	checkHit();
}

void GameLogic::checkPressKey()
{
	if (GetAsyncKeyState(VK_UP))
	{
		increaseSpeed();
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		decreaseSpeed();
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		shiftLeft();
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		shiftRight();
	}
	if (GetAsyncKeyState(VK_RETURN))
	{
		pause();
	}
	if (GetAsyncKeyState(VK_ESCAPE))
	{
		isGameOver = true;
	}

}

void GameLogic::countPoints()
{
	points_ = 10*distance_ - 5*time_;
}


