#ifndef POSITION_H
#define POSITION_H
 
#include "Common.h"

class Position :public Point {
public:
	Point position;
public:
	Position();
	~Position();

	void setPosition(int axis,int shift);//��������� ������� �������, \\�������� � ������ ��� ������
	
	
};

#endif POSITION_H
