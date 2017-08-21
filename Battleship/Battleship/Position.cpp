#include "Position.h"



Position::Position()
{
	Point position(0, 0);
}


Position::~Position()
{
}

void Position::setPosition(int axis, int shift, int sizeShip, int direction)//значение сдвига и по какой оси сдвиг.
{
	if (axis == 0)
	{
		int posX;
		int posEndX;
		posX = position.getX() + shift;
		if (HORIZONTAL == direction)
		{
			posEndX = posX;
		}
		else if(VERTICAL == direction)
		{
			posEndX = posX + sizeShip - 1;
		}
		if (posX >= 0 && posEndX < SIZE_BATTLEFIELD) position.setX(posX);
	}
	else if (axis == 1)
	{
		int posY;
		int posEndY;
		posY = position.getY() + shift;
		if (HORIZONTAL == direction)
		{
			posEndY = posY + sizeShip - 1;
		}
		else if (VERTICAL == direction)
		{
			posEndY = posY;
		}
		if (posY >= 0 && posEndY < SIZE_BATTLEFIELD) position.setY(posY);
	}
}
void Position::setBattlePosition(int axis, int shift)//значение сдвига и по какой оси сдвиг. 1 - х, 0 - у
{
	if (axis == 0)
	{
		int posX;

		posX = position.getX() + shift;

		if (posX >= 0 && posX < SIZE_BATTLEFIELD) position.setX(posX);
	}
	else if (axis == 1)
	{
		int posY;
		posY = position.getY() + shift;
		if (posY >= 0 && posY < SIZE_BATTLEFIELD) position.setY(posY);
	}
}


