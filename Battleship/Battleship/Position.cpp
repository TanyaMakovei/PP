#include "Position.h"



Position::Position()
{
	Point position(0,0);
}


Position::~Position()
{
}

void Position::setPosition(int axis,int shift)//�������� ������ � �� ����� ��� �����. 1 - �, 0 - �
{
	if (axis == 0) {
		int posX;
		posX = position.getX() + shift;
		if (posX >= 0 && posX <= 9) position.setX(posX);
	}
	else if (axis == 1) {
		int posY;
		posY = position.getY() + shift;
		if (posY >= 0 && posY <= 9) position.setY(posY);
	}

}


