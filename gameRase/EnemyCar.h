#ifndef ENEMYCAR_H
#define ENEMYCAR_H

#include "Helper.h"

class EnemyCar
{
public:
	EnemyCar();
	~EnemyCar();

	void moveCar(int masField[FIELD_LENGHT][FIELD_WIDTH]);
	void doStep();
	void shiftLeft(int shift);
	void shiftRight(int shift);

private:
	int x_;
	int y_;

};
#endif ENEMYCAR_H
