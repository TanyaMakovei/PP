#include "Field.h"
//#include "Helper.h"



Field::Field()
{
	for (int i = 0; i < FIELD_LENGHT;i++)
	{
		for (int j = 0;j < FIELD_WIDTH;j++)
		{
			gameField[i][j] = EMPTY;
		}
	}
	level = 0;
	generateNextField();
}


Field::~Field()
{
}


void Field::generateLine()
{
	if (level >= FIELD_LENGHT)
	{
		level = 0;
		generateNextField();
	}
	for (int i = 0; i < FIELD_WIDTH;i++)
	{
		gameField[0][i] = generatedField[FIELD_LENGHT - level][i];
	}
	level++;
}

void Field::generateField()
{
	int gameFieldTemp[FIELD_WIDTH][FIELD_LENGHT];
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

	for (int i = 0; i < FIELD_LENGHT;i++)
	{
		for (int j = 0;j < FIELD_WIDTH;j++)
		{
			generatedField[i][j] = EMPTY;
		}
	}
	int countOfTrees;
	for (int type = 1; type < 4;type++) {
		countOfTrees = rand() % MAX_COUNT_OF_TREES + 1;
		Tree tree1(type);
		int pointX,
			pointY;
		int sizeX = tree1.getSizeX();
		int sizeY = tree1.getSizeY();
		for (int count = 0;count < countOfTrees;)
		{			
			pointY = rand() % FIELD_WIDTH;
			pointX = rand() % FIELD_LENGHT;
			if (checkPosition(pointX, pointY, sizeX, sizeY))
			{
				count++;
			}
		}
	}
}

bool Field::checkPosition(int x, int y, int sizeX, int sizeY)
{
	if (((x + sizeX) >= FIELD_LENGHT) || ((y + sizeY) >= FIELD_WIDTH))
	{
		return false;
	}
	for (int i=0; i < sizeX;i++)
	{
		for (int j=0; j < sizeY; j++)
		{
			if (EMPTY != generatedField[x + i][y + j])
			{
				return false;
			}
			
		}
	}
	addTree(x, y, sizeX, sizeY);
	return true;
}

void Field::addTree(int x, int y, int sizeX, int sizeY)
{
	for (int i=0; i < sizeX;i++)
	{
		for (int j=0; j < sizeY; j++)
		{
			if (EMPTY != generatedField[x + i][y + j])
			{
				generatedField[x + i][y + j] = TREE;
			}
		}
	}
}

