#include "Ship.h"




Ship::Ship(int sizeS)
{
	size = sizeS;

}


Ship::~Ship()
{
}



int Ship::getSize()
{
	return size;
}

void Ship::setShip(int x, int y, int direction)
{
	if (direction == HORIZONTAL)
	{


		for (int i = 0; i < size; i++) 
		{
			Point p(x++, y);
			points.push_back(p);

		}
	}
	else if (direction == VERTICAL) 
	{		
			for (int i = 0; i < size; i++) 
			{
				Point p(x, y++);
				points.push_back(p);
			}
	}
}

