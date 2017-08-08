#include "Battlefield.h"
Battlefield::Battlefield()
{
	countShip = 0;
	modeGame = ShipArrangement;
	direction = HORIZONTAL;
	clearBattlefield();

}
Battlefield::~Battlefield()
{
}
Mode Battlefield::getMode()
{
	return modeGame;
}

int Battlefield::getStatus()
{
	return status;
}

void Battlefield::setStatus(int status)
{
	this->status = status;
}

void Battlefield::setShip(int x, int y)
{
	
	if (countShip == 0)
	{
		createShip(x, y, SIZE_4TYPE_SHIP);

	}
	else if (countShip > 0 && countShip <= 2) 
	{
		createShip(x, y, SIZE_3TYPE_SHIP);
	}
	else if (countShip > 2 && countShip <= 5)
	{
		createShip(x, y, SIZE_2TYPE_SHIP);
	}
	else if (countShip > 5 && countShip <= 9)
	{
		createShip(x, y, SIZE_1TYPE_SHIP);
	}
	else if (countShip > 9) 
	{
		modeGame = Battle;
	}
	countShip++;
	direction = HORIZONTAL;
}

void Battlefield::setMyPoint(int x, int y, int value)
{
	myBoard[x][y] = value;
}

void Battlefield::setEnemyPoint(int x, int y, int value)
{
	enemyBoard[x][y] = value;
}





void Battlefield::printBoards()
{
}

int Battlefield::getEnemyPoint(int x, int y)
{
	return enemyBoard[x][y];

}

char Battlefield::drawFrame(int x, int y)
{
	switch (this->getMyPoint(x, y)) 
	{
	case EMPTY:
		return 0xb0;
	case ALIVE:
		return 0xb2;
	case INJUR:
		return 0xc4;
	case KILL:
		return 0xcd;
	case MISS:
		return 0xf9;
	case NOT_AVAILABLE:
		return 0xb1;
	default:
		break;
	}
}

void Battlefield::changeDirection()
{
	if (direction == HORIZONTAL) direction = VERTICAL;
	else if (direction == VERTICAL) direction = HORIZONTAL;
}

int Battlefield::getDirection()
{
	return direction;
}

int Battlefield::getCountShip()
{
	return countShip;
}

void Battlefield::createShip(int x, int y, int sizeTypeShip)
{
	int pos;
	if (direction == HORIZONTAL)
	{
		pos = x + sizeTypeShip - 1;
	}
	else if (direction == VERTICAL)
	{
		pos = y + sizeTypeShip - 1;
	}
	if (pos >= SIZE_BATTLEFIELD)
	{
		//error
	}
	else
	{
		ships.push_back(&Ship(sizeTypeShip));
		Ship(sizeTypeShip).setShip(x, y, direction);
		for (int i = 0; i < sizeTypeShip;i++)
		{
			if (direction == HORIZONTAL)
			{
				myBoard[x][y + i] = 1;
			}
			else if (direction == VERTICAL)
			{
				myBoard[x + i][y] = 1;

			}

		}
	}
}

void Battlefield::clearBattlefield()
{
	for (int i = 0; i < SIZE_BATTLEFIELD;i++)
	{
		for (int j = 0; j < SIZE_BATTLEFIELD;j++)
		{
			myBoard[i][j] = 0;
		}
	}
}

int Battlefield::getMyPoint(int x, int y)
{
	return myBoard[x][y];

}