#ifndef POSITION_H
#define POSITION_H
 
#include "Common.h"

class Position :public Point {
public:
	Point position;
public:
	Position();
	~Position();

	void setBattlePosition(int axis, int shift);

	void setPosition(int axis,int shift, int sizeShip, int direction);//��������� ������� �������, \\�������� � ������ ��� ������
	
	
};

#endif POSITION_H
