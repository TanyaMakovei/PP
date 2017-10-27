#pragma once

#include "Helper.h"

class Field
{
public:
	Field();
	~Field();


	void generateLine();
	void generateField();
	int getPoint(int x, int y);
private:
	int gameField[FIELD_LENGHT][FIELD_WIDTH];


};

