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

	void pauseGame();//����� ��������� ����� � ������� ��������, ����������� ��������� � ���� ��� ���������
	void printStatistic();//����� ���������� � ������
	void startGame(int);
	void checkHitPlayer2(int, int);// �������� ��������� � ��������� �������� � ������ ���������� ����
	void checkHitPlayer1(int, int);


}
#endif GAME_H