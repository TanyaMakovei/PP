#ifndef SHIP_H
#define SHIP_H

#include "Position.h"
#include "Common.h"
#include <vector>

class Ship
{
private:
	vector<Point> points;
 	int size;

public:
	Ship(int);
	~Ship();

	void setShip(int,int,int);// установка корабля 
	int getSize();
};

#endif SHIP_H