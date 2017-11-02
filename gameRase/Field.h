#ifndef FIELD_H
#define FIELD_H
#include "Helper.h"
#include "Tree.h"

class Field
{
public:
	Field();
	~Field();


	void generateLine();
	void generateField();
	int getPoint(int x, int y) const;
	void generateNextField();
private:
	int gameField[FIELD_LENGHT][FIELD_WIDTH];
	int generatedField[FIELD_LENGHT][FIELD_WIDTH];
	int level;

};

#endif FIELD_H