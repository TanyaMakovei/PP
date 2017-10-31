#ifndef FIELD_H
#define FIELD_H
#include "Helper.h"

class Field
{
public:
	Field();
	~Field();


	void generateLine();
	void generateField();
	int getPoint(int x, int y) const;
private:
	int gameField[FIELD_LENGHT][FIELD_WIDTH];


};

#endif FIELD_H