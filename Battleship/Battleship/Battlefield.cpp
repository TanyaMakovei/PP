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
	if (countShip < 0)
	{
		countShip = 0;
	}
	else if (countShip < COUNT_4TYPE_SHIP)
	{
		createShip(x, y, SIZE_4TYPE_SHIP);

	}
	else if (countShip < (COUNT_4TYPE_SHIP + COUNT_3TYPE_SHIP))
	{
		createShip(x, y, SIZE_3TYPE_SHIP);
	}
	else if (countShip < (COUNT_4TYPE_SHIP + COUNT_3TYPE_SHIP + COUNT_2TYPE_SHIP))
	{
		createShip(x, y, SIZE_2TYPE_SHIP);
	}
	else if (countShip < (COUNT_4TYPE_SHIP + COUNT_3TYPE_SHIP + COUNT_2TYPE_SHIP + COUNT_1TYPE_SHIP))
	{
		createShip(x, y, SIZE_1TYPE_SHIP);
	}
	else if (countShip >= (COUNT_4TYPE_SHIP + COUNT_3TYPE_SHIP + COUNT_2TYPE_SHIP + COUNT_1TYPE_SHIP))
	{
		modeGame = Battle;
	}
	//direction = HORIZONTAL;
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

void Battlefield::setCountShip(int count)
{
	countShip = count;
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
		if (checkEmpty(x, y, sizeTypeShip))
		{
			ships.push_back(&Ship(sizeTypeShip));
			Ship(sizeTypeShip).setShip(x, y, direction);
			addShipToBoard(x, y, sizeTypeShip);
			countShip++;
		}
		else
		{
			//not available
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

void Battlefield::addShipToBoard(int x, int y, int sizeTypeShip)
{
	for (int i = 0; i < sizeTypeShip;i++)
	{
		if (direction == HORIZONTAL)
		{
			if (x > 0)
			{
				if (y > 0)
				{
					myBoard[x - 1][y - 1] = NOT_AVAILABLE;
				}
				if ((y + sizeTypeShip) < SIZE_BATTLEFIELD)
				{
					myBoard[x - 1][y + sizeTypeShip] = NOT_AVAILABLE;
				}
				myBoard[x - 1][y + i] = NOT_AVAILABLE;
			}
			if (y > 0)
			{
				myBoard[x][y - 1] = NOT_AVAILABLE;
			}
			if ((y + sizeTypeShip) < SIZE_BATTLEFIELD)
			{
				myBoard[x][y + sizeTypeShip] = NOT_AVAILABLE;
			}
			if (x < (SIZE_BATTLEFIELD - 1))
			{
				if (y > 0)
				{
					myBoard[x + 1][y - 1] = NOT_AVAILABLE;
				}
				if ((y + sizeTypeShip) < SIZE_BATTLEFIELD)
				{
					myBoard[x + 1][y + sizeTypeShip] = NOT_AVAILABLE;
				}
				myBoard[x + 1][y + i] = NOT_AVAILABLE;
			}
			myBoard[x][y + i] = ALIVE;
		}
		else if (direction == VERTICAL)
		{
			if (y > 0)
			{
				if (x > 0)
				{
					myBoard[x - 1][y - 1] = NOT_AVAILABLE;
				}
				if ((x + sizeTypeShip) < SIZE_BATTLEFIELD)
				{
					myBoard[x + sizeTypeShip][y - 1] = NOT_AVAILABLE;
				}
				myBoard[x + i][y - 1] = NOT_AVAILABLE;
			}
			if (x > 0)
			{
				myBoard[x - 1][y] = NOT_AVAILABLE;
			}
			if ((x + sizeTypeShip) < SIZE_BATTLEFIELD)
			{
				myBoard[x + sizeTypeShip][y] = NOT_AVAILABLE;
			}
			if (y < (SIZE_BATTLEFIELD - 1))
			{
				myBoard[x + i][y + 1] = NOT_AVAILABLE;
			}
			if (y < (SIZE_BATTLEFIELD - 1))
			{
				if (x > 0)
				{
					myBoard[x - 1][y + 1] = NOT_AVAILABLE;
				}
				if ((x + sizeTypeShip) < SIZE_BATTLEFIELD)
				{
					myBoard[x + sizeTypeShip][y + 1] = NOT_AVAILABLE;
				}
				myBoard[x + i][y + 1] = NOT_AVAILABLE;
			}
			myBoard[x + i][y] = ALIVE;
		}

	}
}

bool Battlefield::checkEmpty(int x, int y, int sizeTypeShip)
{

	if (HORIZONTAL == direction)
	{
		for (int i = 0; i < sizeTypeShip; i++)
		{
			if (EMPTY == myBoard[x][y + i])
			{
				
			}
			else
			{
				return false;
			}
		}
	}
	else if (VERTICAL == direction)
	{
		for (int i = 0; i < sizeTypeShip; i++)
		{
			if (EMPTY == myBoard[x + i][y])
			{

			}
			else
			{
				return false;
			}
		}

	}
	return true;
}

int Battlefield::getMyPoint(int x, int y)
{
	return myBoard[x][y];

}