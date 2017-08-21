#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include "Mode.h"
#include "Ship.h"
#include "Common.h"

const int COMPUTER = 0;
const int HUMAN = 1;
class Battlefield
{
private:
	int status;
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
	void setStatus(int status);
	void setShip(int x, int y);
	void setMyPoint(int x, int y, int value);
	void setEnemyPoint(int x, int y, int value);//���������� �������� � ������ ������ ����
	void printBoards();//����� ����� �� �����, ����� ����� ���������
	int getMyPoint(int x, int y);
	int getEnemyPoint(int x, int y);
	char drawFrame(int x, int y);
	void changeDirection();//��������� ����������� �������
	int getDirection();
	int getCountShip();
	void setCountShip(int count);
	void createShip(int x, int y, int sizeTypeShip);
	void clearBattlefield();
	void addShipToBoard(int x, int y, int sizeTypeShip);
	bool checkEmpty(int x, int y, int sizeTypeShip);

};
#endif