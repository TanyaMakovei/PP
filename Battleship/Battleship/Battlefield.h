#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include "Mode.h"
#include "Ship.h"
#include "Common.h"

class Battlefield
{
private:
	int status; //0-компьютер, 1 - игрок
	int myBoard[10][10];//0-пусто,1-корабль,2-ранен,3-убит,4-промах,5-не доступно
	int enemyBoard[10][10];
	int countShip;
	Mode modeGame;
	vector<Ship*> ships;
	int direction;
public:
	Battlefield();
	~Battlefield();

	Mode getMode();
	int getStatus();
	void setStatus(int);
	void setShip(int, int);
	void setMyPoint(int, int, int);
	void setEnemyPoint(int, int, int);//установкаа значения в массив своего поля
	void printBoards();//вывод полей на экран, также вывож подсказок
	int getMyPoint(int, int);
	int getEnemyPoint(int, int);
	char drawFrame(int, int);
	void changeDirection();//установка направления корабля
	int getDirection();
	int getCountShip();
}
#endif