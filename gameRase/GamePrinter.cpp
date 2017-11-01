#include "GamePrinter.h"
#include <Windows.h>

char GamePrinter::Buf[FIELD_LENGHT][FIELD_WIDTH];

GamePrinter::GamePrinter()
{
	int i, j;
	for (i = 0;i < FIELD_LENGHT;i++)
	{
		for (j = 0; j < FIELD_WIDTH;j++) {
			Buf[i][j] = SYMBOL_FIELD;
		}
	}
}


GamePrinter::~GamePrinter()
{
}

void writeString(int row, LPCSTR arg, int lengthArg) {
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { SHIFT_FIELD, row + SHIFT_FIELD };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if ((hStdOut != INVALID_HANDLE_VALUE) && GetConsoleScreenBufferInfo(hStdOut, &csbi) &&
		WriteConsoleOutputCharacterA(hStdOut, arg,
			lengthArg, homeCoords, &count))
	{
		cellCount = csbi.dwSize.X * csbi.dwSize.Y;
	}
	else
	{
		return;
	}
}


void GamePrinter::printCar(int y)
{
	Buf[START_X][y] = SYMBOL_CAR;
}

char GamePrinter::drawElement(int x, int y, Field &field)
{
	switch (field.getPoint(x, y))
	{
	case EMPTY:
		return SYMBOL_FIELD;
	case TREE:
		return SYMBOL_TREE;
	default:
		break;
	}
}

void GamePrinter::printGame()
{
	//printField();
	//printCar();
	for (int i = 0;i < FIELD_LENGHT;i++)
	{
		writeString(i, Buf[i], FIELD_WIDTH);
	}
}

void GamePrinter::printStatus(float time, int distance) const
{
	printf("Your time is:%f\n", time);
	printf("Your distance is:%d\n", distance);
}

void GamePrinter::printOldField(Field &field)
{

	for (int x = 0;x < FIELD_LENGHT;x++)
	{
		for (int y = 0; y < FIELD_WIDTH;y++)
		{
			Buf[x][y] = drawElement(x, y, field);
		}
	}
}
