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
	level = 0;
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
		level = 0;
	}

	for (int i = 0; i < FIELD_WIDTH;i++)
	{
		gameField[0][i] = generatedField[level][i];
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
	for (int i = 0; i < FIELD_LENGHT;i++)
	{
		for (int j = 0; j < FIELD_WIDTH;j++)
		{
			generatedField[i][j] = EMPTY;

		}

	}
	for (int type = 1; type <= COUNT_TYPES_TREES; type++)
	{
		for (int k = 0; k < MAX_COUNT_OF_TREES;)
		{
			Tree tree(type);
			int numbX;
			int numbY;
			bool notTree = true;
			numbX = rand() % (FIELD_LENGHT - tree.getSizeX());
			numbY = rand() % (FIELD_WIDTH - tree.getSizeY());
			for (int x = 1; x <= tree.getSizeX(); x++)
			{
				for (int y = 1; y <= tree.getSizeY(); y++)
				{
					if (EMPTY != generatedField[x][y])
					{
						notTree = false;
					}
				}
			}

			if (notTree)
			{
				for (int x = 1; x <= tree.getSizeX(); x++)
				{
					for (int y = 1; y <= tree.getSizeY(); y++)
					{
						generatedField[x][y] = TREE;
					}
				}
				k++;
			}
		}
	}
}

