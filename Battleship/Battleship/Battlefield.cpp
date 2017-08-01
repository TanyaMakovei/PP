#include "Battlefield.h"
Battlefield::Battlefield()
{
	countShip = 0;
	Mode modeGame = ShipArrangement;
	direction = 0;//0-horizontal,1-vertical

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
	int pos;
	if (countShip == 0) {

		if (direction == 0) {
			pos = x + 3;
		}
		else if (direction == 1) {
			pos = y + 3;
		}
		if (pos > 9) {
			//error
		}
		else {
			ships.push_back(&Ship(4));
			Ship(4).setShip(x, y, direction);
			for (int i = 0; i < 4;i++) {
				if (direction == 0) {
					myBoard[x][y + i] = 1;
				}
				else if (direction == 1) {
					myBoard[x + i][y] = 1;

				}

			}
		}

	}
	else if (countShip > 0 && countShip <= 2) {
		if (direction == 0) {
			pos = x + 2;
		}
		else if (direction == 1) {
			pos = y + 2;
		}
		if (pos > 9) {
			//error
		}
		else {
			ships.push_back(&Ship(3));
			Ship(3).setShip(x, y, direction);
			for (int i = 0; i < 3;i++) {
				if (direction == 0) {
					myBoard[x][y + i] = 1;
				}
				else if (direction == 1) {
					myBoard[x + i][y] = 1;

				}

			}
		}

	}
	else if (countShip > 2 && countShip <= 5) {
		if (direction == 0) {
			pos = x + 1;
		}
		else if (direction == 1) {
			pos = y + 1;
		}
		if (pos > 9) {
			//error
		}
		else {
			ships.push_back(&Ship(2));
			Ship(2).setShip(x, y, direction);
			for (int i = 0; i < 2;i++) {
				if (direction == 0) {
					myBoard[x][y + i] = 1;
				}
				else if (direction == 1) {
					myBoard[x + i][y] = 1;

				}

			}
		}

	}
	else if (countShip > 5 && countShip <= 9) {
		if (direction == 0) {
			pos = x;
		}
		else if (direction == 1) {
			pos = y;
		}
		if (pos > 9) {
			//error
		}
		else {
			ships.push_back(&Ship(1));
			Ship(1).setShip(x, y, direction);
			for (int i = 0; i < 1;i++) {
				if (direction == 0) {
					myBoard[x][y + i] = 1;
				}
				else if (direction == 1) {
					myBoard[x + i][y] = 1;

				}

			}
		}

	}
	else if (countShip > 9) {
		modeGame = Battle;
	}
	countShip++;
	direction = 0;
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
	switch (this->getMyPoint(x, y)) {
	case 0:
		return 0xb0;
	case 1:
		return 0xb2;
	case 2:
		return 0xc4;
	case 3:
		return 0xcd;
	case 4:
		return 0xf9;
	case 5:
		return 0xb1;
	default:
		break;
	}
}

void Battlefield::changeDirection()
{
	if (direction == 0) direction = 1;
	else if (direction == 1) direction = 0;
}

int Battlefield::getDirection()
{
	return direction;
}

int Battlefield::getCountShip()
{
	return countShip;
}

int Battlefield::getMyPoint(int x, int y)
{
	return myBoard[x][y];

}