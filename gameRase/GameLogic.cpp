#include "GameLogic.h"
#include "Windows.h"

char GameLogic::Buf[FIELD_LENGHT][FIELD_WIDTH];

GameLogic::GameLogic()
{
	Field field1;
	Car car1;
	distance = -1;
	speed = 3;
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

void writeString(int row, LPCSTR arg) {
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 5, row + 5 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X * csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!WriteConsoleOutputCharacterA(hStdOut, arg,
		strlen(arg), homeCoords, &count))
		return;
}

void GameLogic::pause()
{
	if (false == isPause)
	{
		countTime();
		isPause = true;
		printf("PAUSE");
		printStatus();

	}
	else
	{
		isPause = false;
		printGame();
	}
}

void GameLogic::countTime()
{
	time += (distance-distance2)/speed;
	distance2 = distance;
}

void GameLogic::printField()
{

	field1.generateField();
	distance++;
	printOldField();
	checkHit();
}

void GameLogic::printCar()
{
	int y = car1.getCarPos();
	Buf[START_X][y] = SYMBOL_CAR;
}


	void GameLogic::increaseSpeed()
	{
		if (MAX_SPEED > speed) 
		{
			countTime();
			speed++;
		}
	}

	void GameLogic::decreaseSpeed()
	{
		if (MIN_SPEED < speed)
		{
			countTime();
			speed--;
		}
	}

	char GameLogic::drawElement(int x, int y)
	{
		switch (field1.getPoint(x, y))
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
		while (true)
		{
			printField();
			printCar();
			concurrency::wait(100-speed*10);
		}
		
	}

	void GameLogic::endGame()
	{
		printf("GAME OVER");
		printStatus();
		
	}

	void GameLogic::printStatus()
	{
		printf("Your time is:%d", time);
		printf("Your distance is:%d", distance);
	}

	void GameLogic::checkHit()
	{
		if (TREE == field1.getPoint(START_X,car1.getCarPos()))
		{
			countTime();
			endGame();
		}
	}

	void GameLogic::shiftLeft()
	{
		car1.shiftLeft();
		printOldField();
		printCar();
		checkHit();

	}

	void GameLogic::shiftRight()
	{
		car1.shiftRight();
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
		for (int i = 0;i < FIELD_LENGHT;i++)
		{
			writeString(i, Buf[i]);
		}
	}


