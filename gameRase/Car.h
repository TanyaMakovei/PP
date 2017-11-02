#ifndef CAR_H
#define CAR_H
#include "Helper.h"

class Car
{
public:
	Car();
	~Car();

	void shiftLeft();
	void shiftRight();
	int getCarPos() const;
private:
	int x_;
	int y_;

};


#endif CAR_H

