#include "Car.h"



Car::Car()
{
	x = START_X;
	y = START_Y;
}


Car::~Car()
{
}

void Car::shiftLeft()
{
	if (y > 0) y--;
}

void Car::shiftRight()
{
	if (y < FIELD_WIDTH - 1) y++;
}

int Car::getCarPos()
{
	return y;
}
