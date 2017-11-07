#include "EnemyCar.h"



EnemyCar::EnemyCar()
{
}


EnemyCar::~EnemyCar()
{
}

void EnemyCar::moveCar(int masField[SPEED_ENEMY_CAR][FIELD_WIDTH])
{
	int step = 1;
	bool isFirst = true;
	int i = 0;
	while (step <= SPEED_ENEMY_CAR)
	{
		if (!isFirst)
		{
			i++;
		}
		if (y_ + i < FIELD_WIDTH)
		{
			if (EMPTY == masField[x_ + step][y_ + i])
			{
				shiftRight(i);
				doStep();
				i = 0;
				isFirst = true;
			}
			else if (y_ - i <= 0)
			{
				if (EMPTY == masField[x_ + step][y_ - i])
				{
					shiftLeft(i);
					doStep();
					i = 0;
					isFirst = true;
				}
				else
				{
					isFirst = false;
				}
			}
		}
		else if (y_ - i <= 0)
		{
			if (EMPTY == masField[x_ + step][y_ - i])
			{
				shiftLeft(i);
				doStep();
				i = 0;
				isFirst = true;
			}
			else
			{
				isFirst = false;
			}
		}


	}
}

void EnemyCar::doStep()
{
	x_++;
}

void EnemyCar::shiftLeft(int shift)
{
	if (y_ >= shift) y_ -= shift;
}

void EnemyCar::shiftRight(int shift)
{
	if (y_ < FIELD_WIDTH - shift) y_ += shift;
}
