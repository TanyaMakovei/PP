#include "Field.h"



Field::Field()
{
	for (int i = 0; i < FIELD_LENGHT;i++)
	{
		for (int j = 0;j < FIELD_WIDTH;j++)
		{
			gameField[i][j] = EMPTY;
		}
	}
}


Field::~Field()
{
}


void Field::generateLine()
{
	int countOfTrees;
	countOfTrees = rand() % MAX_COUNT_OF_TREES + 1;
	for (int i = 0; i < FIELD_WIDTH;i++)
	{
		gameField[0][i] = EMPTY;
		
	}
	for (int count = 0;count < countOfTrees;)
	{
		int numb;
		numb = rand() % (FIELD_WIDTH-1);
		if ((EMPTY == gameField[0][numb])&& (EMPTY == gameField[0][numb+1]))
		{
			gameField[0][numb] = TREE;
			gameField[0][numb+1] = TREE;
			count++;
		}

	}
}

void Field::generateField()
{
	for (int i = FIELD_LENGHT - 1; i > 0;i--)
	{
		for (int j = 0;j < FIELD_WIDTH;j++)
		{
			gameField[i][j] = gameField[i - 1][j];
		}
	}
	generateLine();
}

int Field::getPoint(int x, int y) const
{
	return gameField[x][y];
}

void Field::generateNextField()
{
	for (int k; k < MAX_COUNT_OF_TREES;k++)
	{

	}
}

