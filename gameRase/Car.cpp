#include "Car.h"



Car::Car()
{
	x_ = START_X;
	y_ = START_Y;
}


Car::~Car()
{
	
}

void Car::shiftLeft()
{
	if (y_ > 0) y_--;
}

void Car::shiftRight()
{
	if (y_ < FIELD_WIDTH - 1) y_++;
}

int Car::getCarPos() const
{
	return y_;
}

void Car::setStartCarPos()
{
	x_ = START_X;
	y_ = START_Y;
}
