#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "Ship.h"
#include "Battlefield.h"
#include "Position.h"
#include "Common.h"
#include "WaitTime.h"

class GameLogic
{
private:
	int countKillPlayer1, countKillPlayer2;
	Battlefield player1;
	Battlefield player2;
	Position cursor;
	WaitTime gameTime;
public:
	GameLogic();
	~GameLogic();

	void pauseGame();//вывод состояния паузы и времени ожидания, возможность вернуться к игре или завершить/
	void printStatistic();
	void doAction(int i_input);
	void doArrangmentAction(int i_input);
	void doBattleAction(int i_input);
	void checkHit(int x, int y, Battlefield playerAttac, Battlefield playerDefense);// проверка попадания и установка значения в массив вражеского поля
	void drawCursor(Battlefield player);
	void drawCursorByType(int sizeTypeShip, int direction);
	
	void drawFrame();
private:
	static const int BUF_HEIGHT = 10;
	static const int BUF_WIDTH = 57;
	static const int BUF_WIDTH_F = 20;
	static const int BUF_SHIFT = 4;
	static char Buf[BUF_HEIGHT][BUF_WIDTH];

};
#endif 
