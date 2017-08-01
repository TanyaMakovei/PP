#ifndef GAME_H
#define GAME_H

#include "Ship.h"
#include "Battlefield.h"
#include "Position.h"
#include "Common.h"
#include "WaitTime.h"

class Game
{
private:
	int countKillPlayer1, countKillPlayer2;
	Battlefield player1;
	Battlefield player2;
	Position cursor;
	WaitTime gameTime;
public:
	Game();
	~Game();

	void pauseGame();//вывод состояния паузы и времени ожидания, возможность вернуться к игре или завершить
	void printStatistic();//вывод статистики в финале
	void startGame(int);
	void checkHitPlayer2(int, int);// проверка попадания и установка значения в массив вражеского поля
	void checkHitPlayer1(int, int);


}
#endif GAME_H