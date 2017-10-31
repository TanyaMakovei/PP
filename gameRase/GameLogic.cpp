#include "GameLogic.h"
#include "Windows.h"


char GameLogic::Buf[FIELD_LENGHT][FIELD_WIDTH];

GameLogic::GameLogic()
{
	isGameOver = false;
	Field field1;
	Car car1;
	distance_ = -1;
	speed_ = 3;
	int i, j;
	for (i = 0;i < FIELD_LENGHT;i++)
	{
		for (j = 0; j < FIELD_WIDTH;j++) {
			Buf[i][j] = SYMBOL_FIELD;
		}
	}
}


GameLogic::~GameLogic()
{
}

void writeString(int row, LPCSTR arg, int lengthArg) {
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { SHIFT_FIELD, row + SHIFT_FIELD };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X * csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!WriteConsoleOutputCharacterA(hStdOut, arg,
		lengthArg, homeCoords, &count))
		return;
}

void GameLogic::pause()
{
	if (false == isPause_)
	{
		countTime();
		isPause_ = true;
		printf("PAUSE\n");
		printStatus();

	}
	else
	{
		isPause_ = false;
		printGame();
	}
}

void GameLogic::countTime()
{
	time_ += (distance_ - distance2_) / speed_;
	distance2_ = distance_;
}

void GameLogic::printField()
{

	field1_.generateField();
	distance_++;
	printOldField();
	checkHit();
}

void GameLogic::printCar()
{
	int y = car1_.getCarPos();
	Buf[START_X][y] = SYMBOL_CAR;
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

char GameLogic::drawElement(int x, int y)
{
	switch (field1_.getPoint(x, y))
	{
	case EMPTY:
		return SYMBOL_FIELD;
	case TREE:
		return SYMBOL_TREE;
	default:
		break;
	}
}

void GameLogic::printGame()
{
	while (!isGameOver)
	{
		printField();
		printCar();
		for (int i = 0;i < FIELD_LENGHT;i++)
		{
			writeString(i, Buf[i], FIELD_WIDTH);
		}
		concurrency::wait(WAIT_TIME - speed_*COEFFICIENT);
	}

}

void GameLogic::endGame()
{
	isGameOver = true;
	system("cls");
	printf("GAME OVER\n");
	printStatus();
	_getch();

}

void GameLogic::printStatus() const
{
	printf("Your time is:%d\n", time_);
	printf("Your distance is:%d\n", distance_);
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
	printOldField();
	printCar();
	checkHit();

}

void GameLogic::shiftRight()
{
	car1_.shiftRight();
	printOldField();
	printCar();
	checkHit();
}

void GameLogic::printOldField()
{

	for (int x = 0;x < FIELD_LENGHT;x++)
	{
		for (int y = 0; y < FIELD_WIDTH;y++)
		{
			Buf[x][y] = drawElement(x, y);

		}
	}
	


}


