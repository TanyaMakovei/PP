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
	
	generateNextField();
}


Field::~Field()
{
}


void Field::generateLine()
{
	//int countOfTrees;
	//countOfTrees = rand() % MAX_COUNT_OF_TREES + 1;
	//for (int i = 0; i < FIELD_WIDTH;i++)
	//{
	//	gameField[0][i] = EMPTY;
	//	
	//}
	//for (int count = 0;count < countOfTrees;)
	//{
	//	int numb;
	//	numb = rand() % (FIELD_WIDTH-1);
	//	if ((EMPTY == gameField[0][numb])&& (EMPTY == gameField[0][numb+1]))
	//	{
	//		gameField[0][numb] = TREE;
	//		gameField[0][numb+1] = TREE;
	//		count++;
	//	}
	//}
	if (level >= FIELD_LENGHT)
	{
		generateNextField();
	}

	for (int i = 0; i < FIELD_WIDTH;i++)
	{
		gameField[0][i] = generatedField[FIELD_LENGHT-level-1][i];
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
	level = 0;
	for (int i = 0; i < FIELD_LENGHT;i++)
	{
		for (int j = 0; j < FIELD_WIDTH;j++)
		{
			generatedField[i][j] = EMPTY;

		}

	}
	for (int type = COUNT_TYPES_TREES; type > 0; type--)
	{
		for (int k = 0; k < MAX_COUNT_OF_TREES;)
		{
			Tree tree(type);
			bool notTree = true;
			int sizeX = tree.getSizeX();
			int sizeY = tree.getSizeY();
			int numbX = rand() % (FIELD_LENGHT - sizeX);
			int numbY = rand() % (FIELD_WIDTH - sizeY);
			notTree = checkPlace(numbX, numbY, sizeX, sizeY);
			if (notTree)
			{
				setTree(numbX, numbY,sizeX, sizeY);
				k++;
			}
		}
	}
}

bool Field::checkPlace(int placeX, int placeY, int sizeX, int sizeY)
{
	for (int x = 0; x < sizeX; x++)
	{
		for (int y = 0; y < sizeY; y++)
		{
			if (EMPTY != generatedField[placeX + x][placeY + y])
			{
				return false;
			}
		}
	}
}

void Field::setTree(int placeX, int placeY, int sizeX, int sizeY)
{
	for (int x = 0; x <sizeX; x++)
	{
		for (int y = 0; y < sizeY; y++)
		{
			generatedField[placeX + x][placeY + y] = TREE;
		}
	}
}

