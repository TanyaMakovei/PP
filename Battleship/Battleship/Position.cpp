#include "Position.h"



Position::Position()
{
	Point position(0, 0);
}


Position::~Position()
{
}

void Position::setPosition(int axis, int shift)//значение сдвига и по какой оси сдвиг. 1 - х, 0 - у
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


