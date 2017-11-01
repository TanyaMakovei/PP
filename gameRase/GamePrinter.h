#ifndef GAMEPRINTER_H
#define GAMEPRINTER_H

#include "Helper.h"
#include "Field.h"

class GamePrinter
{
public:
	GamePrinter();
	~GamePrinter();

	
	void printCar(int y);
	void printGame();
	char drawElement(int x, int y, Field &field);
	void printStatus(float time, int distance) const;
	void printOldField(Field &field);
private:
	static char Buf[FIELD_LENGHT][FIELD_WIDTH];
};
#endif GAMEPRINTER_H
