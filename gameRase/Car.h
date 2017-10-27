#pragma once
#include "Helper.h"

class Car
{
public:
	Car();
	~Car();

	void shiftLeft();
	void shiftRight();
	int getCarPos();
private:
	int x,
		y;

};

