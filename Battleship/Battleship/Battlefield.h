#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include "Mode.h"
#include "Ship.h"
#include "Common.h"

class Battlefield
{
private:
	int status; //0-���������, 1 - �����
	int myBoard[10][10];//0-�����,1-�������,2-�����,3-����,4-������,5-�� ��������
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
	void setEnemyPoint(int, int, int);//���������� �������� � ������ ������ ����
	void printBoards();//����� ����� �� �����, ����� ����� ���������
	int getMyPoint(int, int);
	int getEnemyPoint(int, int);
	char drawFrame(int, int);
	void changeDirection();//��������� ����������� �������
	int getDirection();
	int getCountShip();
}
#endif